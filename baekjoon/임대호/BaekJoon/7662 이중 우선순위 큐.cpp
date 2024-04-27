#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

vector<int> arr;

int nextInsertIdx = 0;

void byInsert(int idx) {
    if (idx == 0)
        return;

    int rootIdx = (idx + 1) / 2 - 1;

    if (arr[rootIdx] < arr[idx]) {
        int temp = arr[rootIdx];
        arr[rootIdx] = arr[idx];
        arr[idx] = temp;

        byInsert(rootIdx);
    }
}

void byRemoveMax(int idx) {
    int left = (idx + 1) * 2 - 1;
    int right = (idx + 1) * 2;

    // 자식 노드 없을 때
    if (left >= nextInsertIdx && right >= nextInsertIdx)
        return;

    // 왼쪽 노드만 존재할 때, 대소 비교
    if (right >= nextInsertIdx && arr[left] <= arr[idx])
        return;

    if (arr[idx] > arr[left] && arr[idx] > arr[right])
        return;

    int maxIdx = 0;
    if (arr[left] > arr[right])
        maxIdx = left;
    else
        maxIdx = right;

    int temp = arr[maxIdx];
    arr[maxIdx] = arr[idx];
    arr[idx] = temp;

    byRemoveMax(maxIdx);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int nextDepth = 1;

    int t, k, startIdx, min, minIdx;
    cin >> t;

    char c;
    int v;

    arr.resize(1000001);

    for (int i = 0; i < t; i++) {
        cin >> k;

        nextDepth = 1;
        nextInsertIdx = 0;

        for (int j = 0; j < k; j++) {
            cin >> c >> v;

            if (c == 'I') {
                arr[nextInsertIdx++] = v;

                byInsert(nextInsertIdx - 1);

                if (nextDepth == 0 || nextInsertIdx == pow(2, nextDepth) - 1)
                    nextDepth++;
            } else if (c == 'D') {
                if (nextInsertIdx == 0)
                    continue;

                nextInsertIdx--;

                if (v == 1) {
                    arr[0] = arr[nextInsertIdx];
                    arr[nextInsertIdx] = 0;
                    byRemoveMax(0);
                } else if (v == -1) {
                    min = INT_MAX;
                    minIdx = -1;
                    for (int k_ = nextInsertIdx; k_ ; k_--) {
                        if (arr[k_] < min) {
                            min = arr[k_];
                            minIdx = k_;
                        }
                    }

                    if (minIdx != -1) {
                        for (; minIdx < nextInsertIdx; minIdx++) {
                            arr[minIdx] = arr[minIdx + 1];
                        }
                    }
                }
            }
        }

        if (nextInsertIdx == 0)
            cout << "EMPTY" << '\n';
        else {
            min = INT_MAX;
            for (int j = 0; j < nextInsertIdx; j++) {
                if (arr[j] < min) {
                    min = arr[j];
                }
            }

            cout << arr[0] << ' ' << min << '\n';
        }
    }

    return 0;
}

//#include <iostream>
//#include <list>
//
//using namespace std;
//
//class Node;
//class Tree;
//class DoublePriorityQueue;
//
//class Node {
//public:
//    int value;
//    Node* left;
//    Node* right;
//    Node* parent;
//
//    void insert(Node* node) {
//        if (node->value >= value) {
//            if (right == nullptr) {
//                right = node;
//                right->parent = this;
//            }
//            else
//                right->insert(node);
//        } else {
//            if (left == nullptr) {
//                left = node;
//                left->parent = this;
//            }
//            else
//                left->insert(node);
//        }
//    }
//
//    void clear() {
//        if (left != nullptr) {
//            left->clear();
//            left = nullptr;
//        }
//        if (right != nullptr) {
//            right->clear();
//            right = nullptr;
//        }
//
//        delete this;
//    }
//
//    Node* getLeft() {
//        if (left == nullptr)
//            return this;
//
//        return left->getLeft();
//    }
//
//    Node* getRight() {
//        if (right == nullptr)
//            return this;
//
//        return right->getRight();
//    }
//
//    void deleteLeft() const {
//        if (left == nullptr) {
////            delete this;
//
//            if (parent != nullptr)
//                parent->left = nullptr;
//
//            if (right != nullptr) {
//                if (parent != nullptr) {
//                    parent->left = right;
//                    right->parent = parent;
//                }
//            }
//        } else {
//            left->deleteLeft();
//        }
//    }
//
//    void deleteRight() const {
//        if (right == nullptr) {
////            delete this;
//
//            if (parent != nullptr)
//                parent->right = nullptr;
//
//            if (left != nullptr) {
//                if (parent != nullptr) {
//                    parent->right = left;
//                    left->parent = parent;
//                }
//            }
//        } else {
//            right->deleteRight();
//        }
//    }
//};
//
//class Tree {
//public:
//    Node* head;
//
//    void insert(Node* node) {
//        if (head == nullptr)
//            head = node;
//        else
//            head->insert(node);
//    }
//
//    void clear() const {
//        if (head == nullptr)
//            return;
//
//        head->clear();
//    }
//
//    int min() const {
//        Node* min = head->getLeft();
//        return min->value;
//    }
//
//    int max() const {
//        Node* max = head->getRight();
//        return max->value;
//    }
//
//    void deleteMin() {
//        if (head == nullptr)
//            return;
//
//        if (head->left != nullptr) {
//            head->deleteLeft();
//        } else {
//            if (head->right != nullptr) {
//                Node *newHead = head->right;
////                delete head;
//                head = newHead;
//                head->parent = nullptr;
//            } else {
////                delete head;
//                head = nullptr;
//            }
//        }
//    }
//
//    void deleteMax() {
//        if (head == nullptr)
//            return;
//
//        if (head->right != nullptr) {
//            head->deleteRight();
//        } else {
//            if (head->left != nullptr) {
//                Node *newHead = head->left;
////                delete head;
//                head = newHead;
//                head->parent = nullptr;
//            } else {
////                delete head;
//                head = nullptr;
//            }
//        }
//    }
//};
//
//class DoublePriorityQueue {
//public:
//    Tree* tree;
//
//    void insert(int v) const {
//        Node* node = new Node();
//        node->value = v;
//        tree->insert(node);
//    }
//
//    void clear() const {
////        tree.clear();
//        tree->head = nullptr;
//    }
//
//    int min() const {
//        return tree->min();
//    }
//
//    int max() const {
//        return tree->max();
//    }
//
//    bool empty() const {
//        return tree->head == nullptr;
//    }
//
//    void deleteMin() const {
//        tree->deleteMin();
//    }
//
//    void deleteMax() const {
//        tree->deleteMax();
//    }
//};
//int main() {
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    ios::sync_with_stdio(false);
//
//    int t, n;
//    cin >> t;
//
//    char c;
//    int val;
//
//    auto* dPq = new DoublePriorityQueue();
//    dPq->tree = new Tree();
//
//    for (int i = 0; i < t; i++) {
//        cin >> n;
//
//        for (int j = 0; j < n; j++) {
//            cin >> c >> val;
//
//            if (c == 'I') {
//                dPq->insert(val);
//            } else if (c == 'D') {
//                if (val == 1)
//                    dPq->deleteMax();
//                else
//                    dPq->deleteMin();
//            }
//        }
//
//        if (dPq->empty())
//            cout << "EMPTY" << '\n';
//        else
//            cout << dPq->max() << ' ' << dPq->min() << '\n';
//
//        dPq->clear();
//    }
//
//    return 0;
//}
//	