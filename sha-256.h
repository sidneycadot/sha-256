
///////////////
// sha-256.h //
///////////////

#ifndef sha_256_h
#define sha_256_h

#include <string>
#include <sstream>
#include <iomanip>

template <typename my_uint32_t>
class SHA256_State
{
    private:

        static inline my_uint32_t Ch(const my_uint32_t x, const my_uint32_t & y, const my_uint32_t z)
        {
            return (x & y) ^ (~x & z);
        }

        static inline my_uint32_t Maj(const my_uint32_t x, const my_uint32_t & y, const my_uint32_t z)
        {
            return (x & y) ^ (x & z) ^ (y & z);
        }

        static inline my_uint32_t ROTR(const unsigned n, const my_uint32_t & x)
        {
            return (x >> n) | (x << (32 - n));
        }

        static inline my_uint32_t SHR(const unsigned n, const my_uint32_t & x)
        {
            return (x >> n);
        }

        static inline my_uint32_t Sigma_0_256(const my_uint32_t x)
        {
            return ROTR(2, x) ^ ROTR(13, x) ^ ROTR(22, x);
        }

        static inline my_uint32_t Sigma_1_256(const my_uint32_t x)
        {
            return ROTR(6, x) ^ ROTR(11, x) ^ ROTR(25, x);
        }

        static inline my_uint32_t sigma_0_256(const my_uint32_t x)
        {
            return ROTR(7, x) ^ ROTR(18, x) ^ SHR(3, x);
        }

        static inline my_uint32_t sigma_1_256(const my_uint32_t x)
        {
            return ROTR(17, x) ^ ROTR(19, x) ^ SHR(10, x);
        }

    public:

        my_uint32_t H[8];

        SHA256_State()
        {
            reset();
        }

        void reset()
        {
            H[0] = 0x6a09e667;
            H[1] = 0xbb67ae85;
            H[2] = 0x3c6ef372;
            H[3] = 0xa54ff53a;
            H[4] = 0x510e527f;
            H[5] = 0x9b05688c;
            H[6] = 0x1f83d9ab;
            H[7] = 0x5be0cd19;
        }

        void update(const my_uint32_t M[16])
        {
            const uint32_t K[64] =
            {
                0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
                0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
                0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
                0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
                0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
                0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
                0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
                0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
                0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
                0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
                0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
                0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
                0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
                0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
                0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
                0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
            };

            my_uint32_t W[64];

            for (unsigned t = 0; t < 64; ++t)
            {
                W[t] = (t < 16) ? M[t] : (sigma_1_256(W[t - 2]) + W[t - 7] + sigma_0_256(W[t - 15]) + W[t - 16]);
            }

            my_uint32_t a = H[0];
            my_uint32_t b = H[1];
            my_uint32_t c = H[2];
            my_uint32_t d = H[3];
            my_uint32_t e = H[4];
            my_uint32_t f = H[5];
            my_uint32_t g = H[6];
            my_uint32_t h = H[7];

            for (unsigned t = 0; t < 64; ++t)
            {
                const my_uint32_t T_1 = h + Sigma_1_256(e) + Ch (e, f, g) + K[t] + W[t];
                const my_uint32_t T_2 =     Sigma_0_256(a) + Maj(a, b, c);

                // Update a ... h

                h = g;
                g = f;
                f = e;
                e = d + T_1;
                d = c;
                c = b;
                b = a;
                a = T_1 + T_2;
            }

            H[0] += a;
            H[1] += b;
            H[2] += c;
            H[3] += d;
            H[4] += e;
            H[5] += f;
            H[6] += g;
            H[7] += h;
        }

    std::string state() const
    {
        std::ostringstream oss;

        oss << std::hex << std::setfill('0');

        for (unsigned i = 0; i < 8; ++i)
        {
            oss << std::setw(8) << H[i];
        }

        return oss.str();
    }
};

template <typename my_uint32_t>
class SHA256
{
    private:

        SHA256_State<my_uint32_t> sha256_state;

        my_uint32_t M[16]; // message bits
        uint64_t count_bits;

    public:

        SHA256() : count_bits(0) {}

        void reset()
        {
            sha256_state.reset();

            count_bits = 0;
        }

        void add_bit(unsigned bit)
        {
            // Shift the message bits ...
            for (unsigned i = 0; i < 16; ++i)
            {
                if (i < 15)
                {
                    M[i] = (M[i] << 1) | (M[i + 1] >> 31);
                }
                else
                {
                    M[i] = (M[i] << 1) | (bit & 1);
                }
            }

            ++count_bits;

            if (count_bits % 512 == 0)
            {
                sha256_state.update(M);
            }
        }

        void add_byte(const uint8_t byte)
        {
            for (unsigned i = 0; i < 8; ++i)
            {
                add_bit((byte >> (7 - i)) & 1);
            }
        }

        void add_bytes(const uint8_t * bytes, const std::size_t num_bytes)
        {
            for (std::size_t i = 0; i < num_bytes; ++i)
            {
                add_byte(bytes[i]);
            }
        }

        void finalize()
        {
            const uint64_t num_data_bits = count_bits;

            add_bit(1);

            while (count_bits % 512 != 448)
            {
                add_bit(0);
            }

            for (unsigned i = 0; i < 64; ++i)
            {
                add_bit((num_data_bits >> (63 - i)) & 1);
            }
        }

        std::string state() const
        {
            return sha256_state.state();
        }
};

#endif // sha_256_h
