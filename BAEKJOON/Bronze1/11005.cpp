// 문제
// 10진법 수 N이 주어진다. 이 수를 B진법으로 바꿔 출력하는 프로그램을 작성하시오.

// 10진법을 넘어가는 진법은 숫자로 표시할 수 없는 자리가 있다. 이런 경우에는 다음과 같이 알파벳 대문자를 사용한다.

// A: 10, B: 11, ..., F: 15, ..., Y: 34, Z: 35

// 입력
// 첫째 줄에 N과 B가 주어진다. (2 ≤ B ≤ 36) N은 10억보다 작거나 같은 자연수이다.

// 출력
// 첫째 줄에 10진법 수 N을 B진법으로 출력한다.
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n, b;
    cin >> n >> b;

    string b_num;
    while (n != 0)
    {
        int tmp = n % b;
        if (tmp > 9)
        {
            tmp = tmp - 10 + 'A';
            b_num += tmp;
        }
        else
        {
            b_num += ('0' + tmp);
        }
        n /= b;
    }
    reverse(b_num.begin(), b_num.end());

    cout << b_num << '\n';
}