#include <iostream>
#include <string>

using namespace std;

/**
 * heap을 기반으로 priority queue를 구현한 클래스이다.
 * 모든 자료형에 대해서 priority queue는 동작이 되어야 한다.
 * Comapre는 comparator의 클래스로 less인 경우 최소 heap, greater인 경우 최대 heap으로 동작한다.
 * insert, erase 함수를 제외한 모든 멤버 변수, 멤버 함수에 대한 수정은 허용하지 않는다.
 * 필요시 추가적인 멤버 함수는 정의 가능하다.
 */
template <typename T, typename Compare>
class PriorityQueue {
private:
    // heap을 구현하기 위해 이진 트리를 배열로 표현
    T *heap;
    // heap 배열의 크기를 저장하는 변수
    int capacity;
    // heap 안에 있는 원소의 개수를 저장하는 변수
    int n;
    // 우선 순위를 비교하는 comparator 객체
    Compare cmp;
public:
    /**
     * priority queue를 초기화 하는 생성자
     * 배열의 크기를 인자로 받고, 그 크기만큼 배열을 생성
     * 배열 크기의 기본 값은 100
     * @param cap heap 배열의 크기
     */
    PriorityQueue(int cap = 100) {
        capacity = cap;
        heap = new int[capacity];
        n = 0;
    }

    /**
     * priority queue가 비어 있는지를 반환한다.
     */
    bool empty() const {
        return n == 0;
    }

    /**
     * heap에 원소를 삽입하는 upheap 과정을 진행한다.
     * heap은 완전 이진 트리의 구조를 지켜야 하고, 우선 순위를 만족해야 한다.
     * heap의 우선 순위는 클래스에 등록된 Compare에 따라 정의된다.
     * @param value heap에 삽입할 원소이다. 
     */
    void insert(const T value) {
        // TODO heap에 원소를 삽입하는 과정 구현하기
    }

    /**
     * heap에 원소를 삭제하는 downheap 과정을 진행한다.
     * heap은 완전 이진 트리의 구조를 지켜야 하고, 우선 순위를 만족해야 한다.
     * heap의 우선 순위는 클래스에 등록된 Compare에 따라 정의된다. 
     */
    void erase() {
        // TODO heap에서 원소를 삭제하는 과정 구현하기
    }

    /**
     * priority queue에서 우선순위가 가장 높은 원소를 반환한다.
     * priority queue의 우선순위는 등록된 compare에 따라 정의된다.
     */
    T top() const {
        return heap[1];
    }

    /**
     * priority queue를 해제하는 소멸자이다.
     */
    ~PriorityQueue() {
        delete[] heap;
    }
};

/**
 * 학생 정보를 저장하는 클래스이다.
 * 학생의 정보는 학번과 이름을 간진다.
 * 해당 클래스의 멤버 변수나 멤버 함수의 수정, 추가는 허용하지 않는다. 
 */
class Student {
private:
    // 학생의 학번
    int num;
    // 학생의 이름
    string name;
public:
    /**
     * 학생의 정보를 초기화 하는 생성자이다.
     */
    Student(int _num, string _name) {
        num = _num;
        name = _name;
    }

    /**
     * 학생의 학번을 반환하는 함수이다.
     */
    int get_num() const {
        return num;
    }

    /**
     * 학생의 이름을 반환하는 함수이다.
     */
    string get_name() const {
        return name;
    }

    // 학생 클래스 출력을 위해 ostream의 operator overloading 함수 friend 선언
    friend ostream &operator<<(ostream &os, Student &st);
};

/**
 * 학생 클래스를 출력하기 위한 operator overloading 함수이다.
 * 학생의 학번과 이름을 출력한다.
 * 해당 함수는 수정하지 않고 그대로 사용한다.
 * @param os 출력 스트림
 * @param st 출력할 학생 객체
 */
ostream &operator<<(ostream &os, Student &st) {
    os << "num : " << st.num << ", " << "name : " << st.name << endl;
    return os;
}

/**
 * 학생의 학번을 기준으로 우선순위를 정하는 comparator 클래스이다.
 * 학번이 작을수록 우선순위가 높다.
 * 해당 클래스는 priority queue에 사용되는 comparator로 사용된다.
 */
class Comparator {
public:
    /**
     * 학생의 학번을 기준으로 우선순위를 정하는 함수이다.
     * 학번이 작을수록 우선순위가 높도록 정의한다.
     * @param a 비교할 학생 객체
     * @param b 비교할 학생 객체
     */
    bool operator()(const Student a, const Student b) {
        // TODO 학생의 학번을 기준으로 우선순위를 정하는 함수 구현하기
    }
};

template <typename T, typename Compare>
void make_pq(PriorityQueue<T, Compare> pq, T *input, int input_len);

template <typename T, typename Compare>
void print_pq(PriorityQueue<T, Compare> pq);

/**
 * priority queue가 동작하기 위한 main 함수이다.
 * main 함수는 변경하지 않고 그대로 사용한다.
 */
int main() {
    // 낮은 숫자가 우선순위가 높은 min priority queue
    PriorityQueue<int, less<int>> min_pq;
    // 높은 숫자가 우선순위가 높은 max priority queue
    PriorityQueue<int, greater<int>> max_pq;
    int input1[5] = {4, 3, 6, 2, 7};

    // 학번이 낮은 순서대로 우선순위가 높은 priority queue
    PriorityQueue<Student, Comparator> student_pq;
    Student st1(20213582, "장은지");
    Student st2(20223497, "서제현");
    Student st3(20223498, "윤소빈");
    Student input2[3] = {st1, st2, st3};
    
    make_pq(min_pq, input1, 5);
    print_pq(min_pq);

    make_pq(max_pq, input1, 5);
    print_pq(max_pq);

    make_pq(student_pq, input2, 3);
    print_pq(student_pq);

    return 0;
}

/**
 * priority queue를 초기화하고 원소를 삽입하는 함수이다.
 * priority queue의 연산을 위한 input 배열을 받아서 priority queue에 삽입한다.
 * make_pq 함수는 변경하지 않고 그대로 사용한다.
 * @param pq priority queue 객체
 * @param input priority queue에 삽입할 원소 배열
 * @param input_len input 배열의 길이
 */
template <typename T, typename Compare>
void make_pq(PriorityQueue<T, Compare> pq, T *input, int input_len) {
    for (int i = 0; i < input_len; i++) {
        pq.insert(input[i]);
    }
}

/**
 * priority queue에 있는 원소를 출력하는 함수이다.
 * priority queue에 있는 원소를 출력하고, priority queue가 비어 있을 때까지 원소를 삭제한다.
 * print_pq 함수는 변경하지 않고 그대로 사용한다.
 * @param pq priority queue 객체
 * @param input priority queue에 삽입할 원소 배열
 * @param input_len input 배열의 길이
 */
template <typename T, typename Compare>
void print_pq(PriorityQueue<T, Compare> pq) {
    cout << "Print value in heap" << endl;
    while (!pq.empty()) {
        cout << pq.top() << ' ';
        pq.erase();
    }  
    cout << endl << endl;
}