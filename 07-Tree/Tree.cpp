using namespace std;

class PositionList;
template <typename T>
class Position {
private:
    T element;
    Position<T> *parent;
    PositionList children;

public:
    T& operator*() {
        return element;
    }

    Position<T> parent() const {
        return *parent;
    }

    PositionList children() const {
        return children;
    }

    bool isRoot() const {
        return parent == nullptr;
    }
    
    bool isExternal() const {
        return children.empty();
    }
}

template <typename T>
class Tree {
private:
    PositionList _positions;

public:
    int size() const {
        return _positions.size();
    }

    bool empty() const {
        return size() == 0;
    }

    Position<T> root() const {
        for (Position<T> p : _positions) {
            if (p.isRoot()) {
                return p;
            }
        }

        throw "Can not find root";
    }

    PositionList positions() {
        return _positions;
    }
}

int depth(const Tree<int> &t, const Position<int> &p) {
    if (p.isRoot()) 
        return 0;
    else
        return 1 + depth(t, p.parent());
}