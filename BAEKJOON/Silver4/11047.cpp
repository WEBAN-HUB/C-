// 문제
// 준규가 가지고 있는 동전은 총 N종류이고, 각각의 동전을 매우 많이 가지고 있다.

// 동전을 적절히 사용해서 그 가치의 합을 K로 만들려고 한다. 이때 필요한 동전 개수의 최솟값을 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 10, 1 ≤ K ≤ 100,000,000)

// 둘째 줄부터 N개의 줄에 동전의 가치 Ai가 오름차순으로 주어진다. (1 ≤ Ai ≤ 1,000,000, A1 = 1, i ≥ 2인 경우에 Ai는 Ai-1의 배수)

// 출력
// 첫째 줄에 K원을 만드는데 필요한 동전 개수의 최솟값을 출력한다.

/*
1. 아이디어
- 동전을 저장한 뒤, 반대로 뒤집는다.
- 동전 for -> 동전 사용 개수 추가, 동전 사용한 만큼 k값 갱신
2. 시간 복잡도
- O(N)
3. 자료 구조
- 동전 금액 : int 배열
- 동전 사용 count : int 배열
- 남은 금액 : int
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;

int main()
{
    cin >> n >> k;
    vector<int> coins;
    for(int i =0; i < n; i++)
    {
        int val;
        cin >> val;
        coins.push_back(val);
    }
    reverse(coins.begin(),coins.end());
    int count = 0 ;
    for(int coin : coins)
    {
        count += k / coin;
        k = k % coin;
    }

    cout << count;
}