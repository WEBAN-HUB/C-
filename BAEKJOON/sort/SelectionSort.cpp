// 선택 정렬의 특징
// 간단한 구현: 선택 정렬은 다른 정렬 알고리즘에 비해 구현이 간단하고 이해하기 쉬운 편이다.

// 제자리 정렬: 추가 메모리를 거의 사용하지 않기 때문에 메모리 효율이 좋다. 입력 배열을 변경하여 정렬을 수행한다.

// 최악의 시간 복잡도: 모든 경우에 대해 시간 복잡도가 O(n^2)로, 입력 배열이 정렬되어 있는지에 관계없이 항상 같은 시간 복잡도를 가진다.

// 안정적인 정렬이 아님: 선택 정렬은 안정적이지 않다. 즉, 동일한 값이 있으면 그 값들의 상대적인 순서가 유지되지 않을 수 있다.

// 적은 데이터 이동: 각 반복마다 최소값을 찾아 한 번의 교환을 수행하기 때문에 데이터 이동이 적다. 전체 교환 횟수는 배열 크기(n)의 최대값보다 하나 적다.

// 부분적으로 정렬되지 않은 배열에 효율적이지 않음: 부분적으로 정렬된 배열에 대해서는 그다지 효율적이지 않다.

// 선택 정렬의 단점
// 비효율적인 시간 복잡도: 최선, 최악, 평균 시간 복잡도가 모두 O(n^2)로, 특히 크기가 큰 배열에 대해서 매우 비효율적이다.

// 안정적인 정렬이 아님: 같은 값의 요소가 있을 때 그 요소들의 상대적인 순서를 보장하지 않는다.

// 부분적으로 정렬된 배열에 비효율적: 이미 정렬된 배열이나 부분적으로 정렬된 배열에 대해서는 추가적인 최적화가 불가능하다.

// 대규모 데이터셋에 비효율적: 선택 정렬은 작은 데이터셋에는 적합하지만 대규모 데이터셋에는 효율적이지 않다.

#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;  // 최소값의 인덱스를 i로 설정
        cout << "Step " << i + 1 << ": Initial minIndex = " << minIndex << " (Value = " << arr[minIndex] << ")\n";
        
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;  // 새로운 최소값 발견 시 minIndex 업데이트
            }
        }
        
        // 최소값과 현재 i 위치의 값을 교환
        cout << "Swap: arr[" << i << "] (Value = " << arr[i] << ") with arr[" << minIndex << "] (Value = " << arr[minIndex] << ")\n";
        (arr[i], arr[minIndex]);
        
        // 현재 배열 상태 출력
        cout << "Current array: ";
        for (int x = 0; x < n; ++x) {
            cout << arr[x] << " ";
        }
        cout << "\n-----------------------\n";
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    cout << "Initial array: ";
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n-----------------------\n";

    selectionSort(arr);

    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}