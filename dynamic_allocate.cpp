#include <iostream>
#include <vector>

using namespace std;

vector<vector<float>> zeros(int ROW, int COL)
{
    /*
    Can also initialize with
    vector<vector<int>> vec{ { 1, 2, 3 }, 
        { 4, 5, 6 }, 
        { 7, 8, 9 } };
    */

    vector<vector<float>> foo;
    vector<float> temp;
    int i;

    for (i=0; i<COL; i++)
    {
        temp.push_back(0.0);
    }

    for (i=0; i<ROW; i++)
    {
        foo.push_back(temp);
    }

    return foo;
}


void printVector(vector<vector<float>> foo)
{
    for (int i = 0; i < foo.size(); i++)
    { 
        for (int j = 0; j < foo[i].size(); j++) 
            cout << foo[i][j] << " "; 
        cout << endl;
    }
}

int main(int argc, char **argv)
{
    int i, j;
    vector<vector<float>> foo;
    
    foo = zeros(4,5);

    foo[2][4] = 28;

    printVector(foo);

    return 0;
}
