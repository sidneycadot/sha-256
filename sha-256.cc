
////////////////
// sha-256.cc //
////////////////

#include "xuint32_t.h"
#include "sha-256.h"

#include <iostream>

typedef SHA256<uint32_t> SHA256_native;
typedef SHA256<xuint32_t<uint32_t>> SHA256_xuint32_native;


int main()
{
    SHA256_xuint32_native sha;
    //SHA256_native  sha;

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
