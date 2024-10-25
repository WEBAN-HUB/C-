// 문제
// N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.

// N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 N이 주어진다. (1 ≤ N < 15)

// 출력
// 첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.

#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> board;
int result = 0;

bool isSafe(int row, int col)
{
    for(int i =0; i < row; i++)
    {
        if(board[i] == col || abs(board[i] - col) == row - i)
        {
            // board[i] == col => board[i](i 줄의 퀸 열 번호)가 col(이제 놓으려고 하는 열)이 같으면 그 열에 이미 퀸이 있기 때문에 false
            // abs(board[i] - col) == row - i => abs(board[i] - col)(i줄의 퀸 열과 이제 놓으려는 열의 거리)가 row-i(현재 줄에서 그 퀸 줄의 거리)가 같다면 대각선
            // 퀸이 같은 대각선 상에 있다는 것은 같은 값의 거리로 행과 열을 움직였다는 말이기 때문에 위의 거리가 같다면 대각선인 것
            return false;
        }
    }
    return true;
}

void nqueen(int row)
{
    if(row == n)
    {
        result++;
        return;
    }

    for(int i = 0;i < n; i++)
    {
        if(isSafe(row,i))
        {
            board[row] = i;
            nqueen(row+1);
            board[row] = -1;
        }
    }
}

int main()
{
    cin >> n;
    board.assign(n,-1);
    nqueen(0);
    cout << result;
}