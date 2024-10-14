// 문제
// 어떤 큰 도화지에 그림이 그려져 있을 때, 그 그림의 개수와, 그 그림 중 넓이가 가장 넓은 것의 넓이를 출력하여라. 단, 그림이라는 것은 1로 연결된 것을 한 그림이라고 정의하자. 가로나 세로로 연결된 것은 연결이 된 것이고 대각선으로 연결이 된 것은 떨어진 그림이다. 그림의 넓이란 그림에 포함된 1의 개수이다.

// 입력
// 첫째 줄에 도화지의 세로 크기 n(1 ≤ n ≤ 500)과 가로 크기 m(1 ≤ m ≤ 500)이 차례로 주어진다. 두 번째 줄부터 n+1 줄 까지 그림의 정보가 주어진다. (단 그림의 정보는 0과 1이 공백을 두고 주어지며, 0은 색칠이 안된 부분, 1은 색칠이 된 부분을 의미한다)

// 출력
// 첫째 줄에는 그림의 개수, 둘째 줄에는 그 중 가장 넓은 그림의 넓이를 출력하여라. 단, 그림이 하나도 없는 경우에는 가장 넓은 그림의 넓이는 0이다.


// 1. 아이디어
// 2중 for -> 값 1 && 방문 x -> BFS
// BFS 돌면서 그림 개수 + 1, 최대 값을 갱신
// 2. 시간 복잡도
// BFS : O(V+E)
//  V : n x m (입력 값) = 500 x 500
//  E : 4(최대 4방향으로 확인하는 경우가 있음) x 500 x 500
// V + E : 5 x 250000 = 100만 < 2억(평균 1초 최대 연산 수) -> 2억보다 낮기 때문에 1초안에 처리 가능 !
// 3. 자료구조
// 그래프 전체 지도 : int[][]
// 방문 : bool[][]
// Queue : BFS를 위한 큐

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n = 0, m = 0, count = 0, maxValue = 0;
vector<vector<int>> iVec;
vector<vector<bool>> boolMap;

const int ny[4] = {0, 1, 0, -1};
const int nx[4] = {1, 0, -1, 0};

void BFS(int row, int col)
{
    count++;
    int result = 1;
    queue<pair<int,int>> q;
    q.push({row,col});
    boolMap[row][col] = true;

    while(!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int my = y + ny[i];
            int mx = x + nx[i];

            if(my >= 0 && my < n && mx >= 0 && mx < m && !boolMap[my][mx] && iVec[my][mx] == 1)
            {
                boolMap[my][mx] = true;
                q.push({my,mx});
                result++;
            }
        }
    }
    maxValue = max(maxValue,result);
}

int main()
{
    cin >> n >> m;
    boolMap.assign(n,vector<bool>(m,false));

    for(int i = 0; i < n; i++)
    {
        vector<int> col;
        for(int j = 0; j < m; j++)
        {
            int value;
            cin >> value;
            col.push_back(value);
        }
        iVec.push_back(col);
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!boolMap[i][j] && iVec[i][j] == 1)
            {
                BFS(i,j);
            }
        }
    }

    cout << count << "\n" << maxValue;
}