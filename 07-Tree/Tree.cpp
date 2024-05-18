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
};

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
};

int depth(const Tree<int> &t, const Position<int> &p) {
    if (p.isRoot()) 
        return 0;
    else
        return 1 + depth(t, p.parent());
}

int height1(const Tree<int> &t) {
    int h = 0;
    PositionList nodes = t.positions();
    for (auto q = nodes.begin(); q != nodes.end(); ++q) {
        if (q->isExternal()) {
            h = max(h, depth(t, q));
        }
    }
    return h;
}

int height2(const Tree<int> &t, const Position<int> &p) {
    if (p.isExternal()) 
        return 0; 
    
    int h = 0;
    PositionList ch = p.children();
    for (auto q = ch.begin(); q != ch.end(); ++q) 
        h = max(h, height2(t, *q));
    return 1 + h;
}