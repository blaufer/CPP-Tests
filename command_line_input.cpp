// Run as follows:
// g++ -o main command_line_input.cpp
// ./main geek for geeks
#include <iostream>
#include <string>

using namespace std;
 
int main(int argc, char** argv)
{
    cout << "You have entered " << argc
         << " arguments:" << "\n";

    int orient_int = argc - 2;
    int run_int = argc - 1;
    string orient = argv[orient_int];
    string run_type = argv[run_int];

    cout << orient << "\n";
    cout << run_type << "\n";
/*
    for (int i = 0; i < argc; ++i)
        cout << argv[i] << "\n";
*/ 
    return 0;
}
