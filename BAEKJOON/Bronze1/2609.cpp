// 문제
// 두 개의 자연수를 입력받아 최대 공약수와 최소 공배수를 출력하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에는 두 개의 자연수가 주어진다. 이 둘은 10,000이하의 자연수이며 사이에 한 칸의 공백이 주어진다.

// 출력
// 첫째 줄에는 입력으로 주어진 두 수의 최대공약수를, 둘째 줄에는 입력으로 주어진 두 수의 최소 공배수를 출력한다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int div = 2;
    int minel = 1;
    while (true)
    {
        if(n % div == 0 && m % div == 0)
        {
            n = n /div;
            m = m /div;
            minel *= div;
        }
        else
        {
            div++;
        }

        if(div > n || div > m)
        {
            break;
        }
    }
    int maxel = minel * n * m;

    cout << minel << "\n" << maxel;
}