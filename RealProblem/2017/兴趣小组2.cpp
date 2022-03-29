#include <iostream>
#include <fstream>
#include <set>
using namespace std;

set<string> A;
set<string> B;
set<string> C;

void read(set<string> &A, string path)
{
    ifstream fin;
    fin.open(path, ios_base::in);
    while (!fin.eof())
    {
        string s;
        fin>> s;
        if(s.length()>0)
            A.insert(s);
    }
    fin.close();
}

int main(int agrc, char* argv[])
{
    int ans=0;
    read(A,"A.txt");
    read(B,"B.txt");
    read(C,"C.txt");

    cout<< A.size() <<endl;

    set<string>::iterator iterA=A.begin();
    while (iterA!=A.end())
    {
        if(B.find(*iterA) != B.end() && C.find(*iterA) == C.end())
            ans++;
        iterA++;
    }
    cout<< ans <<endl;
    return 0;
}