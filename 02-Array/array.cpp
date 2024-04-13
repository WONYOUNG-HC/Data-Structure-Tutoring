class RealArray {
private:
    int *arr;

public:
    RealArray(int capacity) {
        arr = new int[capacity];
    }

    int &operator[](int index) {
        return *(arr + index);
    }

    ~RealArray() {
        delete[] arr;
    }
};

class ArrayObject : public RealArray {
private:
    int capa;
    int cur;

public:
    ArrayObject(int capacity) : RealArray(capacity) {
        capa = capacity;
        cur = 0;
    }

    void push_back(int data) {
        if (cur == capa) {
            return;
        }
        (*this)[cur++] = data;
    }

    void pop_back() {
        if (cur == 0) {
            return;
        }
        cur--;
    }

    void insert(int index, int data) {
        for (int i = capa - 1; i > index; i--) {
            (*this)[i] = (*this)[i - 1];
        }
        (*this)[index] = data;
        
        if (cur < capa) {
            cur++;
        }
    }

    void erase(int index) {
        for (int i = index; i < capa - 1; i++) {
            (*this)[i] = (*this)[i + 1];
        }
        cur--;
    }

    int current() {
        return (*this)[cur];
    }

    int capacity() {
        return capa;
    }
    
    int size() {
        return cur;
    }
};