// 문제
// 2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

// 아래 그림은 2×5 크기의 직사각형을 채운 한 가지 방법의 예이다.

// 입력
// 첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)

// 출력
// 첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.

/*
아이디어
A1 : 1, A2 : 2, A3 : 1 + 2
An = A(n-1) + A(n-2)
for문으로 3부터 N까지 돌면서 이전 값과, 그 이전 값을 더해서 저장 이 때 10007로 나눈 나머지
시간 복잡도
O(N)
자료구조
방법의 수 배열
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> res = {0,1,2};

    if (n > 2)
    {
        for (int i = 3; i < n + 1; i++)
        {
            res.push_back((res[i - 1] + res[i - 2]) % 10007);
        }
        cout << res.back();
    }
    else
    {
        cout << res[n];
    }
}