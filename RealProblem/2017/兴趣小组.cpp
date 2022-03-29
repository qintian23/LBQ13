#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
const int LEN=7*36;
void read(string filename, string data[], int &n)
{
    ifstream in(filename,ios::in);
    string line;
    string s;
    int i=0;
    if(in) // 有该文件
    {
        while (getline (in, line)) // line中不包括每行的换行符
        { 
            stringstream ss(line); 
            for( ;getline(ss,s,','); i++)
            {
                // *(data+i)=s;
                data[i]=s;
                // cout<< s << ',';
            }
            // cout<< endl;
        }
    }
    else // 没有该文件
    {
        cout <<"no such file" << endl;
    }
    n=i;
    in.close();
}

int main()
{
    int alen, blen, clen;
    string a[LEN];
    string b[LEN];
    string c[LEN];

    read("A.txt", a, alen);
    // cout<< endl <<endl;

    read("B.txt", b, blen);
    // cout<< endl <<endl;

    read("C.txt", c, clen);

    // cout<< b[0] <<endl;
    // cout<< a[0] << ',' << b[0] << ',' << c[0] <<endl;

    for(int i=0; i<alen; i++)
    {
        for(int k=0; k<clen; k++)
        {
            if(a[i]==c[k])
            {
                a[i]="#";
                break;
            }
        }
    }

    int ans=0;
    for(int i=0; i<alen; i++)
    {
        for(int j=0; j<blen; j++)
        {
            if(a[i]==b[j])
            {
                ans++;
            }
        }
    }

    cout<< ans <<endl;

    return 0;
}