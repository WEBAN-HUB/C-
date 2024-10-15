// 문제
// <그림 1>과 같이 정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 철수는 이 지도를 가지고 연결된 집의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 대각선상에 집이 있는 경우는 연결된 것이 아니다. <그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다. 지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.



// 입력
// 첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고, 그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.

// 출력
// 첫 번째 줄에는 총 단지수를 출력하시오. 그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.

// 아이디어
// 2중 for, 값 1 && 방문 x => DFS
// DFS를 통해 찾은 값을 저장 후 정렬해서 출력
// 시간복잡도
// DFS : O(V+E)
// V, E : n^2, 4N^2
// V+E : 5N^2(빅 오 표기법에서는 상수를 제외한다) ~= N^2 ~= 625 < 2억 보다 작음 1초안에 처리 가능 !
// 자료구조
// 그래프 저장 : int[][]
// 방문 여부 : bool[][]
// 결과 : int[]

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n = 0, areaSize = 0;
vector<vector<int>> inputMap;
vector<vector<bool>> visitedMap;
vector<int> resultMap;

int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};

void GraphSearch(int row, int col)
{
    for(int i = 0; i < 4; i++)
    {
        int ny = row + dy[i];
        int nx = col + dx[i];
        if(ny >= 0 && ny < n && nx >= 0 && nx < n && !visitedMap[ny][nx] && inputMap[ny][nx] == 1)
        {
            visitedMap[ny][nx] = true;
            areaSize++;
            GraphSearch(ny,nx);
        }
    }
}

int main()
{
    cin >> n;

    inputMap.assign(n,vector<int>(n,0));
    visitedMap.assign(n,vector<bool>(n,false));

    for(int i = 0; i < n; i++)
    {
        string line;
        cin >> line;
        for(int j = 0; j < n; j++)
        {
            inputMap[i][j] = line[j] - '0';
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(inputMap[i][j] == 1 && !visitedMap[i][j])
            {
                areaSize = 1;
                visitedMap[i][j] = true;
                GraphSearch(i,j);
                resultMap.push_back(areaSize);
                areaSize = 0;
            }
        }
    }

    sort(resultMap.begin(),resultMap.end());

    cout << resultMap.size() << "\n";
    for(auto v : resultMap)
    {
        cout << v << "\n";
    }
}