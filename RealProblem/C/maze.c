#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define FILE_PATH "./maze.data"

int maze[1004][1004];
int m, n;

int haveExit()
{
    // TODO:
}

void read()
{
    FILE *fp;
    memset(maze, -1, sizeof(maze));
    if((fp=fopen(FILE_PATH, "r"))==NULL)
    {
        perror(FILE_PATH);
        exit(1);
    }
    fscanf(fp, "%d %d", &m, &n);
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            fscanf(fp, "%d", &maze[i][j]);
        }
    }
    fclose(fp);
}

int main()
{
    read();
    if(haveExit())
    {
        printf("YES\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}