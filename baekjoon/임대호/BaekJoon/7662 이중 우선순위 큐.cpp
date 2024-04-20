#include <iostream>
#include <list>

using namespace std;

class Node;
class Tree;
class DoublePriorityQueue;

class Node {
public:
    int value;
    Node* left;
    Node* right;
    Node* parent;

    void insert(Node* node) {
        if (node->value >= value) {
            if (right == nullptr) {
                right = node;
                right->parent = this;
            }
            else
                right->insert(node);
        } else {
            if (left == nullptr) {
                left = node;
                left->parent = this;
            }
            else
                left->insert(node);
        }
    }

    void clear() {
        if (left != nullptr) {
            left->clear();
            left = nullptr;
        }
        if (right != nullptr) {
            right->clear();
            right = nullptr;
        }

        delete this;
    }

    Node* getLeft() {
        if (left == nullptr)
            return this;

        return left->getLeft();
    }

    Node* getRight() {
        if (right == nullptr)
            return this;

        return right->getRight();
    }

    void deleteLeft() {
        if (left == nullptr) {
//            delete this;

            if (parent != nullptr)
                parent->left = nullptr;

            if (right != nullptr) {
                if (parent != nullptr) {
                    parent->left = right;
                    right->parent = parent;
                }
            }
        } else {
            left->deleteLeft();
        }
    }

    void deleteRight() {
        if (right == nullptr) {
//            delete this;

            if (parent != nullptr)
                parent->right = nullptr;

            if (left != nullptr) {
                if (parent != nullptr) {
                    parent->right = left;
                    left->parent = parent;
                }
            }
        } else {
            right->deleteRight();
        }
    }
};

class Tree {
public:
    Node* head;

    void insert(Node* node) {
        if (head == nullptr)
            head = node;
        else
            head->insert(node);
    }

    void clear() {
        if (head == nullptr)
            return;

        head->clear();
    }

    int min() {
        Node* min = head->getLeft();
        return min->value;
    }

    int max() {
        Node* max = head->getRight();
        return max->value;
    }

    void deleteMin() {
        if (head == nullptr)
            return;

        if (head->left != nullptr) {
            head->deleteLeft();
        } else {
            if (head->right != nullptr) {
                Node *newHead = head->right;
//                delete head;
                head = newHead;
                head->parent = nullptr;
            } else {
//                delete head;
                head = nullptr;
            }
        }
    }

    void deleteMax() {
        if (head == nullptr)
            return;

        if (head->right != nullptr) {
            head->deleteRight();
        } else {
            if (head->left != nullptr) {
                Node *newHead = head->left;
//                delete head;
                head = newHead;
                head->parent = nullptr;
            } else {
//                delete head;
                head = nullptr;
            }
        }
    }
};

class DoublePriorityQueue {
public:
    Tree* tree;

    void insert(int v) {
        Node* node = new Node();
        node->value = v;
        tree->insert(node);
    }

    void clear() {
//        tree.clear();
        tree->head = nullptr;
    }

    int min() {
        return tree->min();
    }

    int max() {
        return tree->max();
    }

    bool empty() {
    return tree->head == nullptr;
    }

    void deleteMin() {
        tree->deleteMin();
    }

    void deleteMax() {
        tree->deleteMax();
    }
};
int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int t, n;
    cin >> t;

    char c;
    int val;

    DoublePriorityQueue* dPq = new DoublePriorityQueue();
    dPq->tree = new Tree();

    for (int i = 0; i < t; i++) {
        cin >> n;

        for (int j = 0; j < n; j++) {
            cin >> c >> val;

            if (c == 'I') {
                dPq->insert(val);
            } else if (c == 'D') {
                if (val == 1)
                    dPq->deleteMax();
                else
                    dPq->deleteMin();
            }
        }

        if (dPq->empty())
            cout << "EMPTY" << '\n';
        else
            cout << dPq->max() << ' ' << dPq->min() << '\n';

        dPq->clear();
    }

    dPq = nullptr;

    return 0;
}
