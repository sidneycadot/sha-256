
///////////////
// sha-256.h //
///////////////

#ifndef sha_256_h
#define sha_256_h

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

namespace // anonymous namespace
{
    template <typename T>
    inline T Ch(const T x, const T & y, const T & z)
    {
        return (x & y) ^ (~x & z);
    }

    template <typename T>
    inline T Maj(const T & x, const T & y, const T & z)
    {
        return (x & y) ^ (x & z) ^ (y & z);
    }

    template <int n, typename T>
    inline T ROTR(const T & x)
    {
        return (x >> n) | (x << (8 * sizeof(T) - n));
    }

    template <int n, typename T>
    inline T SHR(const T & x)
    {
        return (x >> n);
    }
};

template <typename Basetype>
struct SHA256_Algorithm
{
    typedef Basetype basetype;

    static const unsigned NumberOfRounds = 64;

    static const unsigned BlockBits = 512;
    static const unsigned SizeBits  =  64;

    static const unsigned NumberOfBaseTypeBits = 32;

    static const basetype K[64];

    static basetype Sigma_0(const basetype & x)
    {
        return ROTR<2>(x) ^ ROTR<13>(x) ^ ROTR<22>(x);
    }

    static basetype Sigma_1(const basetype & x)
    {
        return ROTR<6>(x) ^ ROTR<11>(x) ^ ROTR<25>(x);
    }

    static basetype sigma_0(const basetype & x)
    {
        return ROTR<7>(x) ^ ROTR<18>(x) ^ SHR<3>(x);
    }

    static basetype sigma_1(const basetype & x)
    {
        return ROTR<17>(x) ^ ROTR<19>(x) ^ SHR<10>(x);
    }
};

template <typename basetype>
const basetype SHA256_Algorithm<basetype>::K[64] =
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

template <typename Basetype>
struct SHA512_Algorithm
{
    typedef Basetype basetype;

    static const unsigned NumberOfRounds = 80;

    static const unsigned BlockBits = 1024;
    static const unsigned SizeBits  =  128;

    static const unsigned NumberOfBaseTypeBits = 64;

    static const basetype K[80];

    static basetype Sigma_0(const basetype & x)
    {
        return ROTR<28>(x) ^ ROTR<34>(x) ^ ROTR<39>(x);
    }

    static basetype Sigma_1(const basetype & x)
    {
        return ROTR<14>(x) ^ ROTR<18>(x) ^ ROTR<41>(x);
    }

    static basetype sigma_0(const basetype & x)
    {
        return ROTR<1>(x) ^ ROTR<8>(x) ^ SHR<7>(x);
    }

    static basetype sigma_1(const basetype & x)
    {
        return ROTR<19>(x) ^ ROTR<61>(x) ^ SHR<6>(x);
    }
};

template <typename basetype>
const basetype SHA512_Algorithm<basetype>::K[80] =
{
    0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f, 0xe9b5dba58189dbbc,
    0x3956c25bf348b538, 0x59f111f1b605d019, 0x923f82a4af194f9b, 0xab1c5ed5da6d8118,
    0xd807aa98a3030242, 0x12835b0145706fbe, 0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2,
    0x72be5d74f27b896f, 0x80deb1fe3b1696b1, 0x9bdc06a725c71235, 0xc19bf174cf692694,
    0xe49b69c19ef14ad2, 0xefbe4786384f25e3, 0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65,
    0x2de92c6f592b0275, 0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4, 0x76f988da831153b5,
    0x983e5152ee66dfab, 0xa831c66d2db43210, 0xb00327c898fb213f, 0xbf597fc7beef0ee4,
    0xc6e00bf33da88fc2, 0xd5a79147930aa725, 0x06ca6351e003826f, 0x142929670a0e6e70,
    0x27b70a8546d22ffc, 0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed, 0x53380d139d95b3df,
    0x650a73548baf63de, 0x766a0abb3c77b2a8, 0x81c2c92e47edaee6, 0x92722c851482353b,
    0xa2bfe8a14cf10364, 0xa81a664bbc423001, 0xc24b8b70d0f89791, 0xc76c51a30654be30,
    0xd192e819d6ef5218, 0xd69906245565a910, 0xf40e35855771202a, 0x106aa07032bbd1b8,
    0x19a4c116b8d2d0c8, 0x1e376c085141ab53, 0x2748774cdf8eeb99, 0x34b0bcb5e19b48a8,
    0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb, 0x5b9cca4f7763e373, 0x682e6ff3d6b2b8a3,
    0x748f82ee5defb2fc, 0x78a5636f43172f60, 0x84c87814a1f0ab72, 0x8cc702081a6439ec,
    0x90befffa23631e28, 0xa4506cebde82bde9, 0xbef9a3f7b2c67915, 0xc67178f2e372532b,
    0xca273eceea26619c, 0xd186b8c721c0c207, 0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178,
    0x06f067aa72176fba, 0x0a637dc5a2c898a6, 0x113f9804bef90dae, 0x1b710b35131c471b,
    0x28db77f523047d84, 0x32caab7b40c72493, 0x3c9ebe0a15c9bebc, 0x431d67c49c100d4c,
    0x4cc5d4becb3e42b6, 0x597f299cfc657e2a, 0x5fcb6fab3ad6faec, 0x6c44198c4a475817
};

template <typename basetype>
struct SHA224_Traits
{
    typedef SHA256_Algorithm<basetype> BaseAlgorithm;

    static const unsigned NumberOfHashBits = 224;

    static constexpr uint32_t init[8] =
    {
        0xc1059ed8, // TODO: figure out where these come from
        0x367cd507,
        0x3070dd17,
        0xf70e5939,
        0xffc00b31,
        0x68581511,
        0x64f98fa7,
        0xbefa4fa4
    };
};

template <typename basetype>
struct SHA256_Traits
{
    typedef SHA256_Algorithm<basetype> BaseAlgorithm;

    static const unsigned NumberOfHashBits = 256;

    static constexpr uint32_t init[8] =
    {
        0x6a09e667, // the first 32 bits of the fractional parts of the square roots of the first eight prime numbers.
        0xbb67ae85,
        0x3c6ef372,
        0xa54ff53a,
        0x510e527f,
        0x9b05688c,
        0x1f83d9ab,
        0x5be0cd19
    };
};

template <typename basetype>
struct SHA384_Traits
{
    typedef SHA512_Algorithm<basetype> BaseAlgorithm;

    static const unsigned NumberOfHashBits = 384;

    static constexpr uint64_t init[8] =
    {
        0xcbbb9d5dc1059ed8, // the first 64 bits of the fractional parts of the square roots of the ninth through sixteenth prime numbers.
        0x629a292a367cd507,
        0x9159015a3070dd17,
        0x152fecd8f70e5939,
        0x67332667ffc00b31,
        0x8eb44a8768581511,
        0xdb0c2e0d64f98fa7,
        0x47b5481dbefa4fa4
    };
};

template <typename basetype>
struct SHA512_Traits
{
    typedef SHA512_Algorithm<basetype> BaseAlgorithm;

    static const unsigned NumberOfHashBits = 512;

    static constexpr uint64_t init[8] =
    {
        0x6a09e667f3bcc908, // the first 64 bits of the fractional parts of the square roots of the first eight prime numbers.
        0xbb67ae8584caa73b,
        0x3c6ef372fe94f82b,
        0xa54ff53a5f1d36f1,
        0x510e527fade682d1,
        0x9b05688c2b3e6c1f,
        0x1f83d9abfb41bd6b,
        0x5be0cd19137e2179
    };
};

template <typename basetype>
struct SHA512_InitialValueGenerator_Traits
{
    typedef SHA512_Algorithm<basetype> BaseAlgorithm;

    static const unsigned NumberOfHashBits = 512;

    static constexpr uint64_t init[8] =
    {
        0x6a09e667f3bcc908 ^ 0xa5a5a5a5a5a5a5a5, // the first 64 bits of the fractional parts of the square roots of the first eight prime numbers.
        0xbb67ae8584caa73b ^ 0xa5a5a5a5a5a5a5a5, // xorred with 0xa5, repeated.
        0x3c6ef372fe94f82b ^ 0xa5a5a5a5a5a5a5a5,
        0xa54ff53a5f1d36f1 ^ 0xa5a5a5a5a5a5a5a5,
        0x510e527fade682d1 ^ 0xa5a5a5a5a5a5a5a5,
        0x9b05688c2b3e6c1f ^ 0xa5a5a5a5a5a5a5a5,
        0x1f83d9abfb41bd6b ^ 0xa5a5a5a5a5a5a5a5,
        0x5be0cd19137e2179 ^ 0xa5a5a5a5a5a5a5a5
    };
};

template <typename Traits>
class SHA2_State
{
    private:

        typedef typename Traits::BaseAlgorithm::basetype basetype;

    public:

        basetype H[8]; // The state of the SHA-2 algorithm

        SHA2_State()
        {
            reset();
        }

        void reset()
        {
            for (unsigned i = 0; i < 8; ++i)
            {
                H[i] = Traits::init[i];
            }
        }

        void update(const basetype M[16])
        {
            basetype W[Traits::BaseAlgorithm::NumberOfRounds];

            for (unsigned t = 0; t < Traits::BaseAlgorithm::NumberOfRounds; ++t)
            {
                W[t] = (t < 16) ? M[t] : (Traits::BaseAlgorithm::sigma_1(W[t - 2]) + W[t - 7] + Traits::BaseAlgorithm::sigma_0(W[t - 15]) + W[t - 16]);
            }

            basetype a = H[0];
            basetype b = H[1];
            basetype c = H[2];
            basetype d = H[3];
            basetype e = H[4];
            basetype f = H[5];
            basetype g = H[6];
            basetype h = H[7];

            for (unsigned t = 0; t < Traits::BaseAlgorithm::NumberOfRounds; ++t)
            {
                const basetype T_1 = h + Traits::BaseAlgorithm::Sigma_1(e) + Ch(e, f, g) + Traits::BaseAlgorithm::K[t] + W[t];
                const basetype T_2 =     Traits::BaseAlgorithm::Sigma_0(a) + Maj(a, b, c);

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
};

template <typename Traits>
class SHA2
{
    private:

        SHA2_State<Traits> sha_state;

        typedef typename Traits::BaseAlgorithm::basetype basetype;

        basetype M[16]; // message buffer

        uint64_t bitcount;

    public:

        SHA2() : bitcount(0) {}

        void reset()
        {
            sha_state.reset();

            bitcount = 0;
        }

        void add_bit(unsigned bit)
        {
            // Shift the message bits ...
            for (unsigned i = 0; i < 16; ++i)
            {
                if (i < 15)
                {
                    const unsigned SignBit = Traits::BaseAlgorithm::NumberOfBaseTypeBits - 1;

                    M[i] = (M[i] << 1) | (M[i + 1] >> SignBit);
                }
                else
                {
                    M[i] = (M[i] << 1) | (bit & 1);
                }
            }

            ++bitcount;

            if (bitcount % Traits::BaseAlgorithm::BlockBits == 0)
            {
                sha_state.update(M);
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
            const uint64_t num_data_bits = bitcount;

            const unsigned NumberOfSizeBits = 8 * sizeof(uint64_t);

            add_bit(1);

            while (bitcount % Traits::BaseAlgorithm::BlockBits != Traits::BaseAlgorithm::BlockBits - NumberOfSizeBits)
            {
                add_bit(0);
            }

            for (unsigned i = 0; i < NumberOfSizeBits; ++i)
            {
                add_bit((num_data_bits >> (NumberOfSizeBits - 1 - i)) & 1);
            }
        }

        std::string state() const
        {
            std::ostringstream oss;

            oss << std::hex << std::setfill('0');

            static_assert(Traits::NumberOfHashBits % Traits::BaseAlgorithm::NumberOfBaseTypeBits == 0, "Should be divisible.");

            const unsigned ShowWords = Traits::NumberOfHashBits / Traits::BaseAlgorithm::NumberOfBaseTypeBits;

            for (unsigned i = 0; i < ShowWords; ++i)
            {
                const unsigned nibbles = 2 * sizeof(basetype);

                oss << std::setw(nibbles) << sha_state.H[i];
            }

            return oss.str();
        }
};

#endif // sha_256_h
