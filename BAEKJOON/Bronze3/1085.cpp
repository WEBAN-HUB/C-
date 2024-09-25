// 문제
// 한수는 지금 (x, y)에 있다. 직사각형은 각 변이 좌표축에 평행하고, 왼쪽 아래 꼭짓점은 (0, 0), 오른쪽 위 꼭짓점은 (w, h)에 있다. 직사각형의 경계선까지 가는 거리의 최솟값을 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 x, y, w, h가 주어진다.

// 출력
// 첫째 줄에 문제의 정답을 출력한다.
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int x, y, w, h;

    cin >> x >> y >> w >> h;
    // algorithm include 후 min, max 함수를 활용하여 최솟값 최댓값을 얻을 수 있다.
    // 인자값으로 여러 개의 인자를 받을 겨우 아래와 같이 활용
    cout << min({w-x,x,h-y,y});
}