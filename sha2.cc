
/////////////
// sha2.cc //
/////////////

#include "expr_uint32_t.h"
#include "xuint_t.h"
#include "sha2.h"

#include <iostream>

typedef SHA2<SHA224_Traits<uint32_t>> SHA224_native;
typedef SHA2<SHA256_Traits<uint32_t>> SHA256_native;
typedef SHA2<SHA384_Traits<uint64_t>> SHA384_native;
typedef SHA2<SHA512_Traits<uint64_t>> SHA512_native;

typedef SHA2<SHA512Truncated_Traits<uint64_t, 224>> SHA512_224_native;
typedef SHA2<SHA512Truncated_Traits<uint64_t, 256>> SHA512_256_native;

typedef SHA2<SHA224_Traits<xuint_t<uint32_t>>> SHA224_x_native;
typedef SHA2<SHA256_Traits<xuint_t<uint32_t>>> SHA256_x_native;
typedef SHA2<SHA384_Traits<xuint_t<uint64_t>>> SHA384_x_native;
typedef SHA2<SHA512_Traits<xuint_t<uint64_t>>> SHA512_x_native;

//typedef SHA256<xuint32_t<uint32_t>> SHA256_xuint32_native;
//typedef SHA256<xuint32_t<xuint32_t<uint32_t>>> SHA256_xuint32_xuint32_native;
//typedef SHA256<xuint32_t<expr_uint32_t>> SHA256_xuint32_native;
//typedef SHA256<xuint32_t<xuint32_t<uint32_t>>> SHA256_xuint32_xuint32_native;

//typedef SHA256<xuint32_t<expr_uint32_ptr_t>> SHA256_xuint32_expr;

int main()
{
    SHA224_native sha224;
    SHA256_native sha256;
    SHA384_native sha384;
    SHA512_native sha512;
    SHA512_224_native sha512_224;
    SHA512_256_native sha512_256;

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
            sha512_224.add_byte(c);
            sha512_256.add_byte(c);
        }
    }

    sha224.finalize();
    sha256.finalize();
    sha384.finalize();
    sha512.finalize();
    sha512_224.finalize();
    sha512_256.finalize();

    std::cout << "SHA-224 .......... : " << sha224.hex() << std::endl;
    std::cout << "SHA-256 .......... : " << sha256.hex() << std::endl;
    std::cout << "SHA-384 .......... : " << sha384.hex() << std::endl;
    std::cout << "SHA-512 .......... : " << sha512.hex() << std::endl;
    std::cout << "SHA-512/224 ...... : " << sha512_224.hex() << std::endl;
    std::cout << "SHA-512/256 ...... : " << sha512_256.hex() << std::endl;

    return 0;
}
