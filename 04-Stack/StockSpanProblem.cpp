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

int *quadratic_span(int *price, int len) {
    int *span = new int[len];

    for (int i = 0; i < len; i++) {
        span[i] = 1;
        for (int j = i - 1; j >= 0 && price[j] <= price[i]; j--) {
            span[i]++;
        }
    }

    return span;
}

int *linear_span(int *price, int len) {
    int *span = new int[len];
    ArrayStack2<int> stack;

    for (int i = 0; i < len; i++) {
        while (!stack.empty() && price[stack.top()] <= price[i]) {
            stack.pop();
        }

        if (stack.empty()) {
            span[i] = i + 1;
        } 
        else {
            span[i] = i - stack.top();
        }
    }
}