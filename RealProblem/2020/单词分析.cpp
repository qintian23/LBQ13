#include <iostream>
#include <string.h>
using namespace std;

int word[26];
int main()
{
    // string s;
    // cin>> s;
    string s="longlonglongistoolong";
    for (int i = 0; i < s.length(); i++)
    {
        word[s[i]-'a']++;
    }
    
    int max=-1;
    int index=0;
    for (int i = 0; i < 26; i++)
    {
        if(max<word[i])
        {
            max=word[i];
            index=i;
        }
    }
    cout<< char('a'+index) << endl << max <<endl;

    return 0;
}