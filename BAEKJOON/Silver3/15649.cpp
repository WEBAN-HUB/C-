// 문제
// 자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

// 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
// 입력
// 첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

// 출력
// 한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

// 수열은 사전 순으로 증가하는 순서로 출력해야 한다.


//아이디어
// 1부터 N중에 하나를 선택한 뒤
// 다음 1부터 N까지 선택할 때 이미 선택한 값이 아닌 경우 선택
// M개를 선택할 경우 출력
// -----------
// 백트래킹 재귀 함수 안에서, for 돌면서 숫자 선택(방문 여부 확인)
// 재귀함수에서 M개를 선택할 경우 출력
// 백트래킹 문제는 N이 작다.

//시간 복잡도 (1초를 기준)
// N*N 중복이 가능, N = 8까지
// N! 중복이 불가 N = 10까지

//자료구조
// 방문 여부 확인 배열 vector bool
// 선택한 값 입력 배열 vector int
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, M;
vector<bool> visited;
vector<int> res;

void recur(int num)
{
    if(num == M)
    {
        string result = "";
        for(int val : res)
        {
            result += (char)(val + '0');
            result += " ";
        }
        cout << result + "\n";
        return;
    }

    for(int i =1; i < N+1;i++)
    {
        if(visited[i] == false)
        {
            visited[i] = true;
            res.push_back(i);
            recur(num + 1);
            visited[i] = false;
            res.pop_back();
        }
    }
}

int main()
{
    cin >> N >> M;

    visited.assign(N+1,false);

    recur(0);
}