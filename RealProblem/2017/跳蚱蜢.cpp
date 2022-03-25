#include <iostream>
#include <string.h>
#include <queue>
#include <set>

using namespace std;
char* start="012345678";
char* target="087654321";

struct StateAndLevel
{
    char* state;
    int level;
    int pos0;

    StateAndLevel(char* _state, int _level, int _pos0):state(_state),level(_level),pos0(_pos0){}
};
struct cmp
{
    bool operator()(char* a, char* b)
    {
        return strcmp(a,b)<0;
    }
};
queue<StateAndLevel> q;
set<char*, cmp> allState;

void swap(char* s, int a, int b)
{
    char t=s[a];
    s[a]=s[b];
    s[b]=t;
}
void addNei(char* state, int pos, int newPos, int le)
{
    char* new_state=(char*)malloc(9*sizeof(char));
    strcpy(new_state,state);
    // 交换
    swap(new_state, pos, newPos);
    if(allState.find(new_state)==allState.end())
    {
        allState.insert(new_state);
        q.push(StateAndLevel(new_state, le+1, newPos));
    }
}

int main(int argc, const char* argv[])
{
    q.push(StateAndLevel(start, 0, 0));
    allState.insert(start);

    while (!q.empty())
    {
        StateAndLevel sal=q.front();
        char* state=sal.state;
        int le=sal.level;
        if(strcmp(state,target)==0)
        {
            cout<< le <<endl;
            return 0;
        }
        int pos0=sal.pos0;

        int new_pos=(pos0-1+9)%9;
        addNei(state, pos0, new_pos, le);
        new_pos=(pos0-2+9)%9;
        addNei(state, pos0, new_pos, le);
        new_pos=(pos0+1+9)%9;
        addNei(state, pos0, new_pos, le);
        new_pos=(pos0+2+9)%9;
        addNei(state, pos0, new_pos, le);
        q.pop();
    }
    return 0;
}