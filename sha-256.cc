
////////////////
// sha-256.cc //
////////////////

#include "expr_uint32_t.h"
#include "xuint32_t.h"
#include "sha-256.h"

#include <iostream>

typedef SHA256<uint32_t> SHA256_native;
typedef SHA256<xuint32_t<uint32_t>> SHA256_xuint32_native;
typedef SHA256<xuint32_t<expr_uint32_ptr_t>> SHA256_xuint32_expr;


int main()
{
    expr_uint32_ptr_t henk = std::make_shared<expr_uint32_t>(3);

    //SHA256_xuint32_native sha;
    //SHA256_native  sha;
    SHA256_xuint32_expr sha;

    while (true)
    {
        int c = getchar();
        if (c == EOF)
        {
            break;
        }
        else
        {
            sha.add_byte(c);
        }
    }

    sha.finalize();

    std::cout << sha.state() << std::endl;

    return 0;
}
