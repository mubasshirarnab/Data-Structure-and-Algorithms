#include <bits/stdc++.h>

using namespace std;

int visited[7] = {0, 0, 0, 0, 0, 0, 0};
int a[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}};

void DFS(int i)
{
    cout << i << " ";
    visited[i] = 1;

    for (int j = 0; j < 7; j++)
    {
        if (a[i][j] == 1 && visited[j] == 0)
        {
            DFS(j);
        }
    }
}

int main()
{
    DFS(0);

    return 0;
}



// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     stack<int> s;
//     int visited[7] = {0, 0, 0, 0, 0, 0, 0};
//     int a[7][7] = {
//     {0, 1, 1, 1, 0, 0, 0},
//     {1, 0, 1, 0, 0, 0, 0},
//     {1, 1, 0, 1, 1, 0, 0},
//     {1, 0, 1, 0, 1, 0, 0},
//     {0, 0, 1, 1, 0, 1, 1},
//     {0, 0, 0, 0, 1, 0, 0},
//     {0, 0, 0, 0, 1, 0, 0}};

//     int i = 4;
//     cout << i << " ";
//     visited[i] = 1;
//     s.push(i);

//     while (!s.empty())
//     {
//         int x = s.top();
//         s.pop();
//         for (int j = 0; j < 7; j++)
//         {
//             if (a[x][j] == 1 && visited[j] == 0)
//             {
//                 cout << j << " ";
//                 visited[j] = 1;
//                 s.push(j);
//             }
//         }
//     }

//     return 0;
// }
