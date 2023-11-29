#include<bits/stdc++.h>

using namespace std;

int main()
{
    int visited[5] = {0,0,0,0,0};
    queue <int> q;
    int a[5][5] = {
        {0,1,0,1,1},
        {1,0,1,1,0},
        {0,1,0,1,1},
        {1,1,1,0,1},
        {1,0,1,1,0}
    };

    int i = 1;
    cout<< i << " ";
    visited[i] = 1;
    q.push(i);

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        for (int j = 0; j < 5; j++)
        {
            if(a[x][j] == 1 && visited[j] == 0)
            {
                cout<< j << " ";
                visited[j] = 1;
                q.push(j);
            }
        }
        
    }
    

    return 0;
}