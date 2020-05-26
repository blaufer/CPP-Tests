#include <iostream>
#include <getopt.h>

using namespace std;

//---------------------------------------------------------

// Doing this basically makes it global in Python terminology but 
// it's very bad practice unless you know what you're doing and
// I should be using pass by reference
char *file = (char*)"none";
bool restart = false;
int temperature = 0;
double timestep = 0.0003;

//---------------------------------------------------------

void PrintHelp()
{
    cout <<
        "--file <f>         -f      Set the filename\n"
        "--restart          -r      Run from restart file, default = false\n"
        "--temperaure <t>   -t      Temperature to perform the run at, default = 0\n"
        "--timestep <s>     -s      Set the timestep, default = 0.0003\n"
        "--help             -h      Print this message and exit\n";

    exit(1);
}

//---------------------------------------------------------

void ProcessArgs(int argc, char **argv)
{
    // Place a : after the options that accept an argument
    const char* const short_opts = "f:rt:s:h";

    const option long_opts[] =
    {
        {"file", required_argument, nullptr, 'f'},
        {"restart", no_argument, nullptr, 'r'},
        {"temperature", required_argument, nullptr, 't'},
        {"timestep", required_argument, nullptr, 's'},
        {"help", no_argument, nullptr, 'h'},
        {nullptr, no_argument, nullptr, 0}
    };

    while (true)
    {
        const auto opt = getopt_long(argc, argv, short_opts, long_opts, nullptr);

        // Detect the end of the options
        if (opt == -1)
            break;

        // Switch Case is like using if elif else in Python where this says
        // if opt == 'f', elif opt == 'r', ..., and default is else
        switch (opt)
        {
            case 'f':
                file = optarg;
            case 'r':
                restart = true;
                break;
            case 't':
                temperature = atoi(optarg);
                break;
            case 's':
                timestep = atof(optarg);
                break;
            case 'h': // In C++, the cases can be stacked like this
            case '?': // and it means that h, ?, and default all go
            default:  // the next one, in this case PrintHelp()
                PrintHelp();
                break;
        }
    }

}

//---------------------------------------------------------

int main(int argc, char **argv)
{
    ProcessArgs(argc, argv);

    printf("%s\n", file);
    // True False is actually stored as 0 is false and anything
    // else, typically 1, is true, this prints the word instead
    // of the number
    printf("%s\n", restart ? "true" : "false");
    printf("%i\n", temperature);
    printf("%f\n", timestep);
    
    return 0;
}
