#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string s;
    vector<string> lines;
    ifstream testfile("test.txt");

    if(testfile.is_open())
    {
        while(getline(testfile,s))
        {
            lines.push_back(s);
        }
        testfile.close();
    }
    else
    {
        cout << "Unable to open file";
    }
    
    for(int i = 0; i < lines.size(); i++)
    {
        cout << i << ": " << lines[i] << "\n";
    }

    return 0;
}