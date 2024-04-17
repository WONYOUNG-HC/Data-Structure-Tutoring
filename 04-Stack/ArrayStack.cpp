template <typename T>
class ArrayStack {
protected:
    T *arr;
    int cap;
    int t;

public:
    ArrayStack(int cap) {
        this->cap = cap;
        arr = new T[cap];
        t = -1;
    }

    int size() const {
        return t + 1;
    }

    bool empty() const {
        return t == -1;
    }

    T &top() const {
        if (empty()) {
            throw "Stack is empty";
        }

        return arr[t];
    }

    void push(const T &data) {
        if (size() == cap) {
            throw "Stack is full";
        }

        arr[++t] = data;
    }

    void pop() {
        if (empty()) {
            throw "Stack is empty";
        }

        --t;
    }

    ~ArrayStack() {
        delete[] arr;
    }
};

template <typename T>
class ArrayStack2 {
protected:
    T *arr;
    int cap;
    int t;

public:
    ArrayStack2(int cap = 1) {
        this->cap = cap;
        arr = new T[cap];
        t = -1;
    }

    int size() const {
        return t + 1;
    }

    bool empty() const {
        return t == -1;
    }

    T &top() const {
        if (empty()) {
            throw "Stack is empty";
        }

        return arr[t];
    }

    void push(const T &data) {
        if (size() == cap) {
            cap *= 2;
            T *new_arr = new T[cap];
            for (int i = 0; i <= t; i++) {
                new_arr[i] = arr[i];
            }

            delete[] arr;
            arr = new_arr;
        }

        arr[++t] = data;
    }

    void pop() {
        if (empty()) {
            throw "Stack is empty";
        }

        --t;
    }

    ~ArrayStack2() {
        delete[] arr;
    }
};