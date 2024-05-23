#include <iostream>

using namespace std;

void make_heap(int *heap, int &n, const int* input, const int input_len);
void insert(int *heap, int &n, const int value);
void erase(int *heap, int &n);
void print_heap(int *heap, int n);

/**
 * heap이 동작하기 위한 main 함수이다.
 * main 함수는 변경하지 않고 그대로 사용한다.
 */
int main() {
    /*
    heap을 구현하기 위해 이진 트리를 배열로 표현
    n은 heap 안에 있는 원소 개수를 저장하는 변수
    */
    int heap[100], n = 0;

    int input1[7] = {3, 7, 2, 6, -1, 4, 5};
    int input2[10] = {9, 7, 4, 6, 3, -1, -1, 2, 5, -1};
    int input3[13] = {2, 5, 1, 3, 4, 7, 6, -1, -1, -1, 3, 2, 1};
    
    make_heap(heap, n, input1, 7);
    print_heap(heap, n);

    make_heap(heap, n, input2, 10);
    print_heap(heap, n);

    make_heap(heap, n, input3, 13);
    print_heap(heap, n);

    return 0;
}

/**
 * heap의 연산을 제어하는 함수이다.
 * heap을 초기화 하고 input의 값에 따라 삽입 또는 삭제 연산 진행한다.
 * make_heap 함수는 변경하지 않고 그대로 사용한다.
 * @param heap 이진 트리를 표현하는 배열이다.
 * @param n heap에 있는 원소의 개수로 참조자를 사용해 call by reference로 구현된다.
 * @param input heap의 연산을 위한 입력 값으로 양수면 insert, -1이면 erase 연산을 진행한다.
 * @param input_len input 배열의 길이이다.
 */ 
void make_heap(int *heap, int &n, const int *input, const int input_len) {
    // heap의 원소 개수 초기화
    n = 0;

    // 모든 input 값에 대해서 연산 실행
    for (int i = 0; i < input_len; i++) {
        if (input[i] > 0) {
            // input 값이 양의 정수면 insert 함수 실행
            insert(heap, n, input[i]);
        } else {
            // input 값이 -1이면 erase 함수 실행
            erase(heap, n);
        }
    }
}

/**
 * heap에 원소를 삽입하는 upheap 과정을 진행한다.
 * heap은 완전 이진 트리의 구조를 지켜야 하고, 우선 순위를 만족해야 한다.
 * heap의 우선 순위는 최소 heap으로 구현한다.
 * @param heap 이진 트리를 표현하는 배열이다.
 * @param n heap에 있는 원소의 개수로 참조자를 사용해 call by reference로 구현된다.
 * @param value heap에 삽입할 원소이다.
 */
void insert(int *heap, int &n, const int value) {
    // TODO heap에 원소를 삽입하는 과정 구현하기
}

/**
 * heap에 원소를 삭제하는 downheap 과정을 진행한다.
 * heap은 완전 이진 트리의 구조를 지켜야 하고, 우선 순위를 만족해야 한다.
 * heap의 우선 순위는 최소 heap으로 구현한다.
 * @param heap 이진 트리를 표현하는 배열이다.
 * @param n heap에 있는 원소의 개수로 참조자를 사용해 call by reference로 구현된다.
 */
void erase(int *heap, int &n) {
    // TODO heap에서 원소를 삭제하는 과정 구현하기
}

/**
 * heap에 있는 원소를 출력하는 함수이다.
 * 정렬된 값을 출력하는 것이 아닌 배열에 있는 원소 값을 출력한다.
 * print_heap 함수는 변경하지 않고 그대로 사용한다.
 * @param heap 이진 트리를 표현하는 배열이다.
 * @param n heap에 있는 원소의 개수이다.
 */
void print_heap(int *heap, int n) {
    cout << "Print value in heap" << endl;
    for (int i = 0; i < n; i++) {
        cout << heap[i] << ' ';
    }
    cout << endl << endl;
}