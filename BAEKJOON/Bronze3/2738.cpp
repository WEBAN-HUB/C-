// 문제
// N*M크기의 두 행렬 A와 B가 주어졌을 때, 두 행렬을 더하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 행렬의 크기 N 과 M이 주어진다. 둘째 줄부터 N개의 줄에 행렬 A의 원소 M개가 차례대로 주어진다.
// 이어서 N개의 줄에 행렬 B의 원소 M개가 차례대로 주어진다. N과 M은 100보다 작거나 같고, 행렬의 원소는 절댓값이 100보다 작거나 같은 정수이다.

// 출력
// 첫째 줄부터 N개의 줄에 행렬 A와 B를 더한 행렬을 출력한다. 행렬의 각 원소는 공백으로 구분한다.
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    int A[N][M];
    for(int i = 0; i < N; i++)
    {    
        //string str;
        //cin >> str;
        // 전체 공백 제거
        //str.erase(remove(str.begin(),str.end(),' '),str.end());
        int data[M];
        for(int j = 0; j < M; j++)
        {
            // 문자형 숫자를 int로 변환하는 법
            // 그냥 형변환 하면 아스키 코드값이 나온다
            //A[i][j] = *(str.begin()+i) - '0';

            // 숫자가 띄어쓰기 형식으로 한 줄에 쳐도 
            // 띄어쓰기를 기준으로 숫자가 입력 된다.
            // M = 3, 1 2 3을 입력하면
            // 이 반복문을 돌며 1, 2, 3이 data[0], data[1], data[2]에 들어간다. 
            cin >> data[j];
            A[i][j] = data[j];
        }
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            int p = 0;
            cin >> p;
            A[i][j] += p;
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            // 문자형 숫자를 int로 변환하는 법
            // 그냥 형변환 하면 아스키 코드값이 나온다
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

}