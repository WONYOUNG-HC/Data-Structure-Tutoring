template <typename T>
class Node {
private:
    T element;
    Node<T> *parent;
    Node<T> *left;
    Node<T> *right;
public:
    Node(T e) {
        element = e;
        parent = nullptr;
        left = nullptr;
        right = nullptr;
    }

    T get_element() const {
        return element;
    } 

    Node<T> *get_parent() const {
        return parent;
    }

    Node<T> *get_left() const {
        return left;
    }

    Node<T> *get_right() const {
        return right;
    }

    friend class LinkedBinaryTree<T>;
};

template <typename T>
class LinkedBinaryTree {
private:
    Node<T> *root;
    int n;
public:
    LinkedBinaryTree() {
        root = nullptr;
        n = 0;
    }

    int size() const {
        return n;
    }

    bool empty() const {
        return size() == 0;
    }

    Node<T> *get_root() const {
        return root;
    }
    
    void add_root(T e) {
        root = new Node<T>(e);
        n = 1;
    }

    void add_left(Node<T> *node, T e) {
        Node<T> *new_node = new Node<T>(e);
        new_node->parent = node;
        node->left = new_node;
        n++;
    }

    void add_right(Node<T> *node, T e) {
        Node<T> *new_node = new Node<T>(e);
        new_node->parent = node;
        node->right = new_node;
        n++;
    }

    void remove(Node<T> *node) {
        if (node->get_parent() == nullptr) {
            root = nullptr;
        } else {
            Node<T> *parent = node->get_parent();
            if (node == parent->get_left()) {
                parent->left = nullptr;
            } else {
                parent->right = nullptr;
            }
        }
        delete node;
        n--;
    }
};