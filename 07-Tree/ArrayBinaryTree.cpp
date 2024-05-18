template <typename T>
class ArrayBinaryTree {
private:
    T *arr;
    int capacity;
    int n;
public:
    ArrayBinaryTree(int cap) {
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

    int get_root() const {
        return 1;
    }

    void add_root(const T e) {
        arr[1] = e;
        n = 1;
    }

    void add_left(int node, T e) {
        arr[2 * node] = e;
    }
    void add_right(int node, T e) {
        arr[2 * node + 1] = e;
    } 

    void remove(int node) {
        arr[node] = NULL;
        n--;
    }
};
