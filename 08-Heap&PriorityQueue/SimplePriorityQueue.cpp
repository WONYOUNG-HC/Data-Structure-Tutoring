template <typename T>
class SimplePriorityQueue {
private:
    T *arr;
    int capacity;
    int n;
public:
    SimplePriorityQueue(int cap) {
        capacity = cap;
        arr = new T[capacity];
        n = 0;
    }

    int size() const {
        return n;
    }

    bool empty() const {
        return size() == 0;
    }

    T top() const {
        T ret = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] < ret) {
                ret = arr[i];
            }
        }

        return ret;
    }

    void push(const T e) {
        arr[n++] = e;
    }

    void pop() {
        n--;
    }
};
