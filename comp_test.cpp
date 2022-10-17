#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


vector<string> readfile(string filename){
    string s;
    vector<string> lines;
    ifstream testfile(filename);

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

    return lines;
}

int compare(vector<string> precomp, vector<string> postcomp){
    int count = 0;
    if(precomp.size() != postcomp.size())
    { 
        cout << "Files are not the same size.\nPre-compression size: " + to_string(precomp.size()) + "\nPost-decompression size: " + to_string(postcomp.size()) << endl;
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < precomp.size(); i++)
    {
        if(precomp[i].compare(postcomp[i]) != 0){
            count++;
        }
    }

    return count;
}

int main(){
    vector<string> precomp;
    vector<string> postdecomp;

    precomp = readfile("test.txt");
    postdecomp = readfile("test2.txt");
    
    int count = compare(precomp,postdecomp);

    cout << "The pre-compression and post-decompression have a difference of " << count << ".\nThis is a " << count/precomp.size()*100 << "% difference" << endl;

    for(int i = 0; i < precomp.size(); i++)
    {
        cout << i << ": " << precomp[i] << "\n";
    }

    return 0;
}