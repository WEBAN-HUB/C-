// 문제
// 그래프가 주어졌을 때, 그 그래프의 최소 스패닝 트리를 구하는 프로그램을 작성하시오.

// 최소 스패닝 트리는, 주어진 그래프의 모든 정점들을 연결하는 부분 그래프 중에서 그 가중치의 합이 최소인 트리를 말한다.

// 입력
// 첫째 줄에 정점의 개수 V(1 ≤ V ≤ 10,000)와 간선의 개수 E(1 ≤ E ≤ 100,000)가 주어진다. 다음 E개의 줄에는 각 간선에 대한 정보를 나타내는 세 정수 A, B, C가 주어진다. 이는 A번 정점과 B번 정점이 가중치 C인 간선으로 연결되어 있다는 의미이다. C는 음수일 수도 있으며, 절댓값이 1,000,000을 넘지 않는다.

// 그래프의 정점은 1번부터 V번까지 번호가 매겨져 있고, 임의의 두 정점 사이에 경로가 있다. 최소 스패닝 트리의 가중치가 -2,147,483,648보다 크거나 같고, 2,147,483,647보다 작거나 같은 데이터만 입력으로 주어진다.

// 출력
// 첫째 줄에 최소 스패닝 트리의 가중치를 출력한다.

#include <iostream>
#include <vector>
#include <queue>
#include <functional> //greater<pair<int,int>> 사용을 위해 포함
#include <cmath> // abs 함수 사용을 위해 포함

using namespace std;

struct CompareAbs
{
    bool operator()(const pair<int, int>& p1, const pair<int,int>& p2)
    {
        return abs(p1.first) > abs(p2.first); // first의 절대값을 기준으로 오름차순 정렬
    }
};

/*
1. 아이디어
- MST 기본 문제, 외우기
- 간선을 인접 리스트에 넣기
- 힙에 시작점 넣기
- 힙이 빌때까지 다음의 작업을 반복
    - 힙의 최소값을 꺼내서, 해당 노드 방문을 안헀다면
        - 방문표시, 해당 비용추가, 연결된 간선들 힙에 넣어주기
2. 시간 복잡도
-MST : O(ElogE)
3. 자료구조
- 간선이 저장되는 인접리스트 : (가중치, 노드번호)
- 힙 : (가중치, 노드번호)
- 방문 여부 bool 리스트
- MST 결과 값 int
*/

int main()
{

    int v, e;
    int result = 0;
    cin >> v >> e;
    vector<vector<pair<int,int>>> edge;
    vector<bool> chk;
    edge.assign(v+1,vector<pair<int,int>>());
    chk.assign(v+1,false);

    for(int i =0; i < e; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        edge[a].push_back({c,b});
        edge[b].push_back({c,a});
    }

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > minHeap;

    minHeap.push({0,1});

    while(!minHeap.empty())
    {
        pair<int,int> node = minHeap.top();
        minHeap.pop();
        if(chk[node.second] == false)
        {
            chk[node.second] = true;
            result += node.first;
            for(auto next_node : edge[node.second])
            {
                if(chk[next_node.second] == false)
                {
                    minHeap.push(next_node);
                }
            }
        }
    }

    cout << result;
}