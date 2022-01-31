#include <iostream>
#include<fstream>
using namespace std;
int main()
{
    fstream file;
    ifstream ifile("file.txt", ios::in);
    ofstream ofile("file2.txt", ios::out | ios::app);
  
        ofile << ifile.rdbuf();
        
    string word;
    file.open("file2.txt"); 

    return 0;
}
