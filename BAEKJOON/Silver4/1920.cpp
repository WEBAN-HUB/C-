// 문제
// N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때, 이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 자연수 N(1 ≤ N ≤ 100,000)이 주어진다. 다음 줄에는 N개의 정수 A[1], A[2], …, A[N]이 주어진다. 다음 줄에는 M(1 ≤ M ≤ 100,000)이 주어진다. 다음 줄에는 M개의 수들이 주어지는데, 이 수들이 A안에 존재하는지 알아내면 된다. 모든 정수의 범위는 -231 보다 크거나 같고 231보다 작다.

// 출력
// M개의 줄에 답을 출력한다. 존재하면 1을, 존재하지 않으면 0을 출력한다.


// 1. 아이디어
// - N개의 숫자를 정렬
// - N개를 for 돌면서, 이진 탐색
// - 이진 탐색 안에서 데이터를 찾으면 1출력 아니면 0 출력
// 2. 시간 복잡도
// - N개 입력값 정렬 = O(NlogN)
// - M개를 N개중에서 탐색 = O(NlogN)
// 총합 : O((N+M)logN) -> 가능

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int n, m;
vector<int> inputvec;
vector<int> findvec;

void search(int start, int end, int target)
{
    if(start == end)
    {
        if(inputvec[start] == target)
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
        return;
    }

    int mid = (start + end) / 2;

    if(inputvec[mid] < target)
    {
        search(mid+1, end, target);
    }
    else
    {
        search(start,mid,target);
    }
}

int main()
{
    cin >> n;
    cin.ignore();

    string str;
    getline(cin,str);
    istringstream iss(str);
    
    int input;
    while(iss >> input)
    {
        inputvec.push_back(input);
    }

    cin >> m;
    cin.ignore();
    getline(cin,str);
    istringstream iss2(str);
    while(iss2 >> input)
    {
        findvec.push_back(input);
    }
    
    // 이진 탐색을 위한 정렬
    sort(inputvec.begin(),inputvec.end());

    for(int i = 0; i < findvec.size(); i++)
    {
        search(0, n-1, findvec[i]);
    }
}