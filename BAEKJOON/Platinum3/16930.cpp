// 문제
// 진영이는 다이어트를 위해 N×M 크기의 체육관을 달리려고 한다. 체육관은 1×1 크기의 칸으로 나누어져 있고, 칸은 빈 칸 또는 벽이다. x행 y열에 있는 칸은 (x, y)로 나타낸다.

// 매 초마다 진영이는 위, 아래, 오른쪽, 왼쪽 중에서 이동할 방향을 하나 고르고, 그 방향으로 최소 1개, 최대 K개의 빈 칸을 이동한다.

// 시작점 (x1, y1)과 도착점 (x2, y2)가 주어졌을 때, 시작점에서 도착점으로 이동하는 최소 시간을 구해보자.

// 입력
// 첫째 줄에 체육관의 크기 N과 M, 1초에 이동할 수 있는 칸의 최대 개수 K가 주어진다.

// 둘째 줄부터 N개의 줄에는 체육관의 상태가 주어진다. 체육관의 각 칸은 빈 칸 또는 벽이고, 빈 칸은 '.', 벽은 '#'으로 주어진다.

// 마지막 줄에는 네 정수 x1, y1, x2, y2가 주어진다. 두 칸은 서로 다른 칸이고, 항상 빈 칸이다.

// 출력
// (x1, y1)에서 (x2, y2)로 이동하는 최소 시간을 출력한다. 이동할 수 없는 경우에는 -1을 출력한다.

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <utility>  // std::pair, std::make_pair를 사용하기 위해 필요

using namespace std;

const int MAX = 1000;
char cmap[MAX][MAX];
bool visited[MAX][MAX];

int x1,y1,x2,y2,n,m,k;
int time;
struct qnode
{
    pair<int,int> prev;
    int x, y, time, limit;
    qnode(int inX, int inY, int inTime, int inLimit)
    {
        x = inX;
        y = inY;
        time = inTime;
        limit = inLimit;
    };
};

int mx[4] = {0,1,0,-1};
int my[4] = {1,0,-1,0};

int BFS(int x, int y)
{
    queue<qnode> q;
    qnode firstNode(x,y,0,1);
    visited[x][y] = true;
    firstNode.prev = {0,0};
    q.push(firstNode);
    while(!q.empty())
    {
        qnode curN = q.front();
        q.pop();

        if(curN.x == x2 && curN.y == y2)
        {
            return curN.time;
        }

        for(int i =0;i < 4;i++)
        {
            int nx = curN.x + mx[i];
            int ny = curN.y + my[i];
            if(nx > 0 && ny > 0 && nx < n+1 && ny < m+1)
            {
                if(cmap[nx][ny] == '.' && !visited[nx][ny])
                {
                    if(curN.prev == pair<int,int>(0,0))
                    {
                        if((mx[i] != curN.prev.first && my[i] != curN.prev.second) || curN.limit+1 > k)
                        {
                            qnode nextNode(nx,ny,curN.time+1,1);
                            nextNode.prev = {mx[i],my[i]};
                            visited[nx][ny] = true;
                            q.push(nextNode);
                        }
                        else
                        {
                            qnode nextNode(nx,ny,curN.time+1,curN.limit+1);
                            nextNode.prev = {mx[i],my[i]};
                            visited[nx][ny] = true;
                            q.push(nextNode);
                        }
                    }
                    else
                    {
                        if((mx[i] != curN.prev.first && my[i] != curN.prev.second) || curN.limit+1 > k)
                        {
                            qnode nextNode(nx,ny,curN.time+1,1);
                            nextNode.prev = {mx[i],my[i]};
                            visited[nx][ny] = true;
                            q.push(nextNode);
                        }
                        else
                        {
                            qnode nextNode(nx,ny,curN.time,curN.limit+1);
                            nextNode.prev = {mx[i],my[i]};
                            visited[nx][ny] = true;
                            q.push(nextNode);
                        }
                    }
                }
            }
        }
    }

    return -1;
}

int main()
{
    cin >> n >> m >> k;
    time = 0;
    for(int i = 1; i < n+1; i++)
    {
        string input = "";
        cin >> input;
        for(int j = 1; j < m+1;j++)
        {
            cmap[i][j] = input[j-1];
            visited[i][j] = false;
        }
    }
    cin >> x1 >> y1 >> x2 >> y2;
    cout << BFS(x1,y1);
}