// 병합 정렬의 특징
// 안정적인 정렬: 병합 정렬은 안정적인 정렬 알고리즘이다. 이는 동일한 값을 가진 요소들의 상대적인 순서를 유지한다는 것을 의미한다.

// 분할 정복 알고리즘: 병합 정렬은 배열을 반으로 나누어 정렬한 후 병합하는 분할 정복 방식으로 작동한다.

// 시간 복잡도: 최선, 최악, 평균 모두 O(n log n)의 시간 복잡도를 가진다, 특히 큰 데이터셋에서도 효율적으로 작동한다.

// 추가 메모리 사용: 병합 정렬은 추가적인 메모리를 필요로 한다. 임시 배열을 사용하여 병합 과정을 수행하므로, O(n)의 추가 공간이 필요하다.

// 비교 기반 정렬: 병합 정렬은 요소를 비교하여 정렬 순서를 결정하는 비교 기반 정렬 알고리즘이다.

// 재귀적 접근: 병합 정렬은 재귀적 접근을 사용하여 배열을 나누고, 정렬하고, 병합한다.

// 병합 정렬의 단점
// 추가 메모리 사용: 임시 배열을 사용하기 때문에 추가적인 메모리 공간이 필요하다, 특히 메모리 효율이 중요한 환경에서는 단점이 될 수 있다.

// 비교적 느린 성능: 작은 데이터셋에서는 삽입 정렬이나 선택 정렬 등 다른 단순한 알고리즘에 비해 느릴 수 있다.

// 재귀 호출의 오버헤드: 재귀 호출을 많이 사용하기 때문에 재귀 호출의 오버헤드가 발생할 수 있다. 특히 깊이가 깊어질수록 성능에 영향을 미칠 수 있다.

// 일관된 성능: 시간 복잡도가 항상 O(n log n)으로 유지되기 때문에, 최선의 경우에도 다른 알고리즘(예: 퀵 정렬)의 최선 시간 복잡도(O(n log n))보다 빠르지 않다.

#include <iostream>
#include <vector>
using namespace std;

// 두 개의 하위 배열을 병합하는 함수
void merge(vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // 임시 배열 생성
    vector<int> L(n1), R(n2);

    // 임시 배열에 데이터 복사
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    // 병합 과정
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    // 남아있는 요소들 복사
    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }
    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

// 병합 정렬 함수
void mergeSort(vector<int>& arr, int left, int right) 
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid); // 왼쪽 절반 정렬
    mergeSort(arr, mid + 1, right); // 오른쪽 절반 정렬
    merge(arr, left, mid, right); // 병합
}

int main() 
{
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    cout << "Initial array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl << "-----------------------" << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;

}