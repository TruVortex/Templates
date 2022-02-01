// i copied this off of wikipedia lmao
#include <iostream>

using namespace std;

template<typename T, typename C = std::less<T>>

struct SplayTree {

    struct Node {

        Node *left, *right, *parent;
        T key;

        Node(const T &init = T()) : left(nullptr), right(nullptr), parent(nullptr), key(init) {}
    } *root;

    long long pSize;

    SplayTree() : root(nullptr), pSize(0) {}

    void leftRotate(Node *x) {
        Node *y = x->right;
        if (y) {
            x->right = y->left;
            if (y->left) {
                y->left->parent = x;
            }
            y->parent = x->parent;
        }
        if (!x->parent) {
            root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        if (y) {
            y->left = x;
        }
        x->parent = y;
    }

    void rightRotate(Node *x) {
        Node *y = x->left;
        if (y) {
            x->left = y->right;
            if (y->right) {
                y->right->parent = x;
            }
            y->parent = x->parent;
        }
        if (!x->parent) {
            root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        if (y) {
            y->right = x;
        }
        x->parent = y;
    }

    void splay(Node *x) {
        while (x->parent) {
            if (!x->parent->parent) {
                if (x->parent->left == x) right_rotate(x->parent);
                else left_rotate(x->parent);
            } else if (x->parent->left == x && x->parent->parent->left == x->parent) {
                right_rotate(x->parent->parent);
                right_rotate(x->parent);
            } else if (x->parent->right == x && x->parent->parent->right == x->parent) {
                left_rotate(x->parent->parent);
                left_rotate(x->parent);
            } else if (x->parent->left == x && x->parent->parent->right == x->parent) {
                right_rotate(x->parent);
                left_rotate(x->parent);
            } else {
                left_rotate(x->parent);
                right_rotate(x->parent);
            }
        }
    }

    void replace(Node *u, Node *v) {
        if (!u->parent) {
            root = v;
        } else if (u == u->parent->left) {
            u->parent->left = v;
        } else {
            u->parent->right = v;
        }
        if (v) {
            v->parent = u->parent;
        }
    }

    Node *subtree_minimum(Node *u) {
        while (u->left) {
            u = u->left;
        }
        return u;
    }

    const T &minimum() {
        return subtree_minimum(root)->key;
    }

    Node *subtree_maximum(Node *u) {
        while (u->right) {
            u = u->right;
        }
        return u;
    }

    const T &maximum() {
        return subtree_maximum(root)->key;
    }
    
    void insert(const T &key) {
        Node *z = root, *p = nullptr;
        while (z) {
            p = z;
            if (comp(z->key, key)) z = z->right;
            else z = z->left;
        }
        z = new Node(key);
        z->parent = p;
        if (!p) {
            root = z;
        } else if (comp(p->key, z->key)) {
            p->right = z;
        } else {
            p->left = z;
        }
        splay(z);
        pSize++;
    }

    Node *find(const T &key) {
        Node *z = root;
        while (z) {
            if (comp(z->key, key)) {
                z = z->right;
            } else if (comp(key, z->key)) {
                z = z->left;
            } else {
                return z;
            }
        }
        return nullptr;
    }

    void erase(const T &key) {
        Node *z = find(key);
        if (!z) {
            return;
        }
        splay(z);
        if (!z->left) {
            replace(z, z->right);
        } else if (!z->right) {
            replace(z, z->left);
        } else {
            Node *y = subtree_minimum(z->right);
            if (y->parent != z) {
                replace(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            replace(z, y);
            y->left = z->left;
            y->left->parent = y;
        }
        delete z;
        pSize--;
    }

    bool empty() const {
        return root == nullptr;
    }

    unsigned long size() const {
        return p_size;
    }
};
