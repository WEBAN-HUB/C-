// 문제
// 세 점이 주어졌을 때, 축에 평행한 직사각형을 만들기 위해서 필요한 네 번째 점을 찾는 프로그램을 작성하시오.

// 입력
// 세 점의 좌표가 한 줄에 하나씩 주어진다. 좌표는 1보다 크거나 같고, 1000보다 작거나 같은 정수이다.

// 출력
// 직사각형의 네 번째 점의 좌표를 출력한다.
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int count = 3, x , y;
    vector<int> arrX, arrY;

    while(count > 0)
    {
        cin >> x >> y;
        if(find(arrX.begin(),arrX.end(),x) == arrX.end())
        {
            arrX.push_back(x);
        }
        else
        {
            arrX.erase(find(arrX.begin(),arrX.end(),x));
        }
        if(find(arrY.begin(),arrY.end(),y) == arrY.end())
        {
            arrY.push_back(y);
        }
        else
        {
            arrY.erase(find(arrY.begin(),arrY.end(),y));
        }
        count--;
    }
    cout << arrX.front() << " " << arrY.front();

}