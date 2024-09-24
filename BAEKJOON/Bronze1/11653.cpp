// 문제
// 정수 N이 주어졌을 때, 소인수분해하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 정수 N (1 ≤ N ≤ 10,000,000)이 주어진다.

// 출력
// N의 소인수분해 결과를 한 줄에 하나씩 오름차순으로 출력한다. N이 1인 경우 아무것도 출력하지 않는다.
#include <iostream>
using namespace std;

int main()
{
    // cin, cout은 기본적으로 C의 stdio.h와 동기화되어있다.
    // stdio.h의 버퍼와 iostream의 버퍼를 같이 쓴다는 의미.
    // 동기화를 유지하는 작업이 추가되다 보니 상대적으로 속도가 느리다.
    // 아래의 함수로 동기화를 해제해 줄 수 있다.
    // 동기화를 해제하게 되면 아래와 같은 사항을 유의해야 한다.
    // C의 입출력 방식과 동시 사용 불가 (printf, scanf, getchar, puts, gets)
    // -> 동기화를 해제했기 때문에 C의 버퍼와 C++의 버퍼가 독립적이다. 따라서 출력되는 순서를 보장할 수 없다.
    // 멀티쓰레드 불가 - 싱글쓰레드 환경에서만 사용(실무에서 사용 불가)
    ios::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);

    int N = 0;
    cin >> N;
    for (int i = 2; i <= N; i++) {
        while (N % i == 0) {
            //endl보다 "\n"이 빠름
            cout << i << "\n";
            N /= i;
        }
    }
}