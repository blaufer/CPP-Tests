#include <fstream>

int main()
{
    std::ifstream    inFile("In.txt");
    std::ofstream    outFile("Out.txt");

    outFile << inFile.rdbuf();
}
