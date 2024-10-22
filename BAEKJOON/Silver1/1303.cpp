// 문제
// 전쟁은 어느덧 전면전이 시작되었다. 결국 전투는 난전이 되었고, 우리 병사와 적국 병사가 섞여 싸우게 되었다. 그러나 당신의 병사들은 흰색 옷을 입고, 적국의 병사들은 파란색 옷을 입었기 때문에 서로가 적인지 아군인지는 구분할 수 있다. 문제는 같은 팀의 병사들은 모이면 모일수록 강해진다는 사실이다.

// N명이 뭉쳐있을 때는 N2의 위력을 낼 수 있다. 과연 지금 난전의 상황에서는 누가 승리할 것인가? 단, 같은 팀의 병사들이 대각선으로만 인접한 경우는 뭉쳐 있다고 보지 않는다.

// 입력
// 첫째 줄에는 전쟁터의 가로 크기 N, 세로 크기 M(1 ≤ N, M ≤ 100)이 주어진다. 그 다음 두 번째 줄에서 M+1번째 줄에는 각각 (X, Y)에 있는 병사들의 옷색이 띄어쓰기 없이 주어진다. 모든 자리에는 병사가 한 명 있다. B는 파란색, W는 흰색이다. 당신의 병사와 적국의 병사는 한 명 이상 존재한다.

// 출력
// 첫 번째 줄에 당신의 병사의 위력의 합과 적국의 병사의 위력의 합을 출력한다.

#include <iostream>
#include <queue>
#include <string>

using namespace std;

const int MAX = 100;

char soldiers[MAX][MAX];
bool visited[MAX][MAX];

int mp, ep;
int n, m;
int count;

int mx[4] = {1,0,-1,0};
int my[4] = {0,1,0,-1};

void DFS(int y, int x, char findC)
{
    visited[y][x] = true;
    count++;
    for(int i =0; i < 4; i++)
    {
        int nx = x + mx[i];
        int ny = y + my[i];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m)
        {
            continue;
        }
        else
        {
            if (soldiers[ny][nx] == findC && visited[ny][nx] == false)
            {
                DFS(ny, nx, findC);
            }
        }
    }
}

void BFS(int y, int x, char findC)
{
    queue<pair<int,int>> q;
    q.push({y,x});
    visited[y][x] = true;
    count++;
    while(!q.empty())
    {
        int qy = q.front().first;
        int qx = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int ny = qy + my[i];
            int nx = qx + mx[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m)
            {
                continue;
            }
            else
            {
                if(soldiers[ny][nx] == findC && visited[ny][nx] == false)
                {
                    q.push({ny,nx});
                    visited[ny][nx] = true;
                    count++;
                }
            }
        }
    }
}

int main()
{

    mp = 0, ep = 0;
    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        string input = "";
        cin >> input;
        for(int j =0; j < n; j++)
        {
            soldiers[i][j] = input[j];
            visited[i][j] = false;
        }
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(!visited[i][j])
            {
                count = 0;
                char findC = soldiers[i][j];
                //DFS(i,j,findC);
                BFS(i,j,findC);
                if(findC == 'W')
                {
                    mp += count * count;
                }
                else if(findC == 'B')
                {
                    ep += count * count;
                }
            }
        }
    }

    cout << mp << " " << ep;
}