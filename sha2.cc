
/////////////
// sha2.cc //
/////////////

#include "sha2.h"

#include <iostream>
#include <fstream>
#include <string>
#include <memory>

typedef SHA2<SHA224_Traits<uint32_t>> SHA224_native;
typedef SHA2<SHA256_Traits<uint32_t>> SHA256_native;
typedef SHA2<SHA384_Traits<uint64_t>> SHA384_native;
typedef SHA2<SHA512_Traits<uint64_t>> SHA512_native;

typedef SHA2<SHA512_Truncated_Traits<uint64_t, 224>> SHA512_224_native;
typedef SHA2<SHA512_Truncated_Traits<uint64_t, 256>> SHA512_256_native;

using namespace std;

int main(int argc, char ** argv)
{
    bool interpretAsType = false;

    unique_ptr<SHA2_Processor> sha(new SHA256_native);

    for (int i = 1; i < argc; ++i)
    {
        string arg(argv[i]);

        if (interpretAsType)
        {
            if (arg == "224")
            {
                sha = unique_ptr<SHA2_Processor>(new SHA224_native);
            }
            else if (arg == "256")
            {
                sha = unique_ptr<SHA2_Processor>(new SHA256_native);
            }
            else if (arg == "384")
            {
                sha = unique_ptr<SHA2_Processor>(new SHA384_native);
            }
            else if (arg == "512")
            {
                sha = unique_ptr<SHA2_Processor>(new SHA512_native);
            }
            else if (arg == "512/224")
            {
                sha = unique_ptr<SHA2_Processor>(new SHA512_224_native);
            }
            else if (arg == "512/256")
            {
                sha = unique_ptr<SHA2_Processor>(new SHA512_256_native);
            }
            else
            {
                cout << "Ignored unknown SHA2 type: " << arg << endl;
            }

            interpretAsType = false;
        }
        else if (arg == "-t")
        {
            interpretAsType = true;
        }
        else
        {
            // Actually calculate the correct SHA2.

            ifstream f(arg, ios::binary);

            while (true)
            {
                int c = f.get();
                if (!f)
                {
                    break;
                }

                sha->add_byte(c);
            }

            f.close();

            sha->finalize();

            cout << sha->hex() << "  " << arg << endl;

            sha->reset();

            interpretAsType = false;
        }
    } // loop over the arguments

    return 0;
}
