#include <string>

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

bool is_parentheses(char c) {
    return c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}';
}

bool paretheses_matching(std::string str) {
    ArrayStack2<char> stack;

    char open[3] = {'[', '{', '('};
    char close[3] = {']', '}', ')'};
    for (int i = 0; i < str.length(); i++) {
        if (!is_parentheses(str[i])) 
            continue;

        for (int j = 0; j < 3; j++) {
            if (str[i] == close[j] && !stack.empty() && stack.top() == open[j]) {
                stack.pop();
                break;
            } 
            else if (j == 2) {
                stack.push(str[i]);
            }
        }
    }

    return stack.empty();
}