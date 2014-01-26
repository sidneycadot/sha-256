
////////////////
// sha-256.cc //
////////////////

#include "expr_uint32_t.h"
#include "xuint32_t.h"
#include "sha-256.h"

#include <iostream>

typedef SHA2<SHA224_Traits<uint32_t>> SHA224_native;
typedef SHA2<SHA256_Traits<uint32_t>> SHA256_native;
typedef SHA2<SHA384_Traits<uint64_t>> SHA384_native;
typedef SHA2<SHA512_Traits<uint64_t>> SHA512_native;
typedef SHA2<SHA512_InitialValueGenerator_Traits<uint64_t>> SHA512_ivg;

//typedef SHA256<xuint32_t<uint32_t>> SHA256_xuint32_native;
//typedef SHA256<xuint32_t<xuint32_t<uint32_t>>> SHA256_xuint32_xuint32_native;
//typedef SHA256<xuint32_t<expr_uint32_t>> SHA256_xuint32_native;
//typedef SHA256<xuint32_t<xuint32_t<uint32_t>>> SHA256_xuint32_xuint32_native;

//typedef SHA256<xuint32_t<expr_uint32_ptr_t>> SHA256_xuint32_expr;

void ivg_test()
{
    SHA512_ivg sha;

    for (unsigned t = 1; t < 512; ++t)
    {
        std::string name = "SHA-512/" + std::to_string(t);

        sha.reset();
        sha.add_bytes(reinterpret_cast<const uint8_t *>(name.c_str()), name.size());
        sha.finalize();

        std::cout << name << " " << sha.state() << std::endl;

    }
}

int main()
{
    //ivg_test();
    //return 0;

    SHA224_native sha224;
    SHA256_native sha256;
    SHA384_native sha384;
    SHA512_native sha512;

    while (true)
    {
        int c = getchar();
        if (c == EOF)
        {
            break;
        }
        else
        {
            sha224.add_byte(c);
            sha256.add_byte(c);
            sha384.add_byte(c);
            sha512.add_byte(c);
        }
    }

    sha224.finalize();
    sha256.finalize();
    sha384.finalize();
    sha512.finalize();

    std::cout << "SHA-224: " << sha224.state() << std::endl;
    std::cout << "SHA-256: " << sha256.state() << std::endl;
    std::cout << "SHA-384: " << sha384.state() << std::endl;
    std::cout << "SHA-512: " << sha512.state() << std::endl;

    return 0;
}
