// 문제
// N×M크기의 배열로 표현되는 미로가 있다.

// 1	0	1	1	1	1
// 1	0	1	0	1	0
// 1	0	1	0	1	1
// 1	1	1	0	1	1
// 미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오. 한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.

// 위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.

// 입력
// 첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다. 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수들은 붙어서 입력으로 주어진다.

// 출력
// 첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 100;
int imap[MAX][MAX];
bool visited[MAX][MAX];
int n, m; // n = y m = x
vector<int> distList;
int dist;

int my[4] = {0,1,0,-1};
int mx[4] = {1,0,-1,0};

struct qnode
{
    int y, x, sum;
    qnode(int inY, int inX, int inSum)
    {
        y = inY;
        x = inX;
        sum = inSum;
    }
};

void DFS(int y, int x, int sum)
{
    visited[y][x] = true;
    sum++;
    if(y == n-1 && x == m-1)
    {
        distList.push_back(sum);
        return;
    }
    for(int i = 0; i < 4; i++)
    {
        int curY = y + my[i];
        int curX = x + mx[i];

        if(curY >= 0 && curX >= 0 && curY < n && curX < m)
        {
            if(!visited[curY][curX] && imap[y][x] == 1)
            {
                DFS(curY,curX,sum);
                visited[curY][curX] = false;
            }
        }
    }
}

void BFS()
{
    vector<int> distList;
    queue<qnode> q;
    qnode firstNode(0,0,1);
    visited[0][0] = true;
    q.push(firstNode);

    while(!q.empty())
    {
        qnode curNode = q.front();
        q.pop();
        if(curNode.y == n-1 && curNode.x == m-1)
        {
            dist = curNode.sum;
            return;
        }
                    

        for(int i = 0; i < 4; i++)
        {
            int ny = curNode.y + my[i];
            int nx = curNode.x + mx[i];
            if(ny >= 0 && nx >= 0 && ny < n && nx < m)
            {
                if(imap[ny][nx] == 1 && !visited[ny][nx])
                {
                    qnode nextNode(ny,nx,curNode.sum+1);
                    visited[ny][nx] = true;
                    q.push(nextNode);
                    
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        string input = "";
        cin >> input;
        for(int j = 0; j < m;j++)
        {
            imap[i][j] = input[j] - '0';
            visited[i][j] = false;
        }
    }

    //DFS(0,0,0);
    //sort(distList.begin(),distList.end());
    //cout << distList[0];
    BFS();
    cout << dist;
}