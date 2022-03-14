#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

void statistic(vector<string> &acc, set<string> &city, map<string,int> &people)
{
    for(vector<string>::iterator it=acc.begin(); it!=acc.end(); it++)
    {
        string uid=(*it).substr(0,18);
        city.insert(uid.substr(0,3));
        people[(*it).substr(0,18)]++;
    }

    for(set<string>::iterator  it=city.begin(); it!=city.end(); it++)
    {
        cout<< *it <<endl;
    }

    map<string, int>::iterator it=people.begin();
    while (it!=people.end())
    {
        if((*it).second < 2)
        {
            people.erase((*it++).first);
        }
        else
        {
            cout<< (*it).first << " : " << (*it).second <<endl;
            it++;
        }
    }
}

int main()
{
    vector<string> acc={"1104001935010142886220010198743200","1204001935010142886220010198743200",
                        "1304001935010142886220010198743200","1204001935010142886220010198743200",
                        "1204001935010142886220010198743200","1304001935010142886220010198743200",
                        "1204001935010142886220010198743200","1304001935010142886220010198743200",
                        "1804001935010142886220010198743200","1404001935010142886220010198743200",
                        "1504001935010142886220010198743200","1504001935010142886220010198743200",
                        "1904001935010142886220010198743200","1904001935010142886220010198743200"};
    
    set<string> city;
    map<string,int> people;
    statistic(acc,city,people);
    return 0;
}