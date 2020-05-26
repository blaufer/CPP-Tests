#include <iostream>
#include <time.h>
#include <sys/stat.h>

bool fileExists(const std::string& file)
{
    struct stat buf;
    return (stat(file.c_str(), &buf) == 0);
}

time_t fileModTime(const char* file)
{
    struct stat buf;
    stat(file, &buf);
    return buf.st_mtime;
}


int main(int argc, char** argv)
{
    if (fileExists("./reflect.cpp"))
    {
        std::cout << "Exists";
    }
    else
    {
        std::cout << "Failed";
    }
    
    time_t x = fileModTime("./reflect.cpp");
    std::cout << x;
 
    return 0;
}
