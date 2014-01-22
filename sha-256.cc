
#include "xuint32_t.h"
#include "sha-256.h"

#include <iostream>

typedef SHA256<uint32_t> SHA256_native;
typedef SHA256<xuint32_t> SHA256_xuint32;

//typedef SHA256<xuint32_t> SHA256_x;

int main()
{
    //SHA256_xuint32 sha;
    SHA256_native  sha;

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
