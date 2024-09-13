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
    int N = 0, B = 0;

    cin >> N >> B;
    string output = "";
    int i = 1;
    int div = 0;
    while (N > 0)
    {
        // 제곱할 때 (int) 형변환 필요
        // 인자, 리턴 다 double 형이기 때문
        // ceil = 소숫점 위로 반올림
        div = ceil(pow(B, i));
        if (div > N)
        {
            int remain = (int)(((double)N / (double)div)*B);
            
            if (remain < 10)
            {
                output.insert(0, to_string(remain));
                break;
            }
            else
            {
                char ch = 'A'+(remain-10);
                // insert(위치,사이즈,넣을문자or문자열)
                output.insert(0, 1,ch);
                break;
            }
        }
        else
        {
            int remain = N % div;
            int addch = remain / ceil(pow(B, i-1));
            if (remain != 0)
            {
                if (addch < 10)
                {
                    output.insert(0, to_string(addch));
                    N -= remain;
                }
                else
                {
                    char ch = 'A'+(addch-10);
                    output.insert(0, 1,ch);
                    N -= remain;
                }
            }
            else
            {
                output.insert(0, "0");
            }
        }
        i++;
    }
    cout << output;
}