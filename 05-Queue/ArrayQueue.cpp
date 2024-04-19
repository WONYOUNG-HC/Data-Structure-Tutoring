template <typename T>
class ArrayQueue {
private:
    T *arr;
    int cap, n;
    int f, r;

public:
    ArrayQueue(int cap) {
        this->cap = cap;
        arr = new T[cap];
        f = r = 0;
        n = 0;
    }

    int size() const {
        return n;
    }

    bool empty() const {
        return n == 0;
    }

    T &front() {
        if (empty()) {
            throw "Queue is empty";
        }

        return arr[f];
    }

    void enqueue(const T &data) {
        if (size() == cap) {
            throw "Queue is full";
        }

        arr[r++] = data;
        n++;
    }

    void dequeue() {
        if (empty()) {
            throw "Queue is empty";
        }

        f++;
        n--;
    }
};

template <typename T>
class ArrayQueue2 {
private:
    T *arr;
    int cap, n;
    int f, r;

public:
    ArrayQueue2(int cap) {
        this->cap = cap;
        arr = new T[cap];
        f = r = 0;
        n = 0;
    }

    int size() const {
        return n;
    }

    bool empty() const {
        return n == 0;
    }

    T &front() {
        if (empty()) {
            throw "Queue is empty";
        }

        return arr[f];
    }

    void enqueue(const T &data) {
        if (size() == cap) {
            throw "Queue is full";
        }

        arr[r] = data;
        r = (r + 1) % cap;
        n++;
    }

    void dequeue() {
        if (empty()) {
            throw "Queue is empty";
        }

        f = (f + 1) % cap;
        n--;
    }
};

template <typename T>
class ArrayQueue3 {
private:
    T *arr;
    int cap, n;
    int f, r;

public:
    ArrayQueue3(int cap = 1) {
        this->cap = cap;
        arr = new T[cap];
        f = r = 0;
        n = 0;
    }

    int size() const {
        return n;
    }

    bool empty() const {
        return n == 0;
    }

    T &front() {
        if (empty()) {
            throw "Queue is empty";
        }

        return arr[f];
    }

    void enqueue(const T &data) {
        if (size() == cap) {
            cap *= 2;
            T *new_arr = new T[cap];
            for (int i = 0; i < n; i++) {
                new_arr[i] = arr[(f + i) % n];
            }

            delete[] arr;
            arr = new_arr;
            f = 0;
            r = n;
        }

        arr[r] = data;
        r = (r + 1) % cap;
        n++;
    }

    void dequeue() {
        if (empty()) {
            throw "Queue is empty";
        }

        f = (f + 1) % cap;
        n--;
    }
};