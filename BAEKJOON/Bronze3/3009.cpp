// 문제
// 세 점이 주어졌을 때, 축에 평행한 직사각형을 만들기 위해서 필요한 네 번째 점을 찾는 프로그램을 작성하시오.

// 입력
// 세 점의 좌표가 한 줄에 하나씩 주어진다. 좌표는 1보다 크거나 같고, 1000보다 작거나 같은 정수이다.

// 출력
// 직사각형의 네 번째 점의 좌표를 출력한다.
#include <stdio.h>

int main()
{
    // 아래와 같은 원리로 문제를 해결할 수 있다.
    // 초기 값에 계산할 값 ^=연산(비트 XOR 연산)을 수행하게 되면 
    // 초기 값과 게산할 값의 다른 비트 부분들이 1로 변한 어떠한 값으로 변하게 된다.
    // 그런데 변화된 어떠한 값에 계산했던 같은 값으로 다시 ^= 연산을 수행하게 되면
    // 초기 값으로 다시 돌아가게 된다.

   int a,b,c,d,e,f;
   scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
   printf("%d %d",a^c^e,b^d^f);
}