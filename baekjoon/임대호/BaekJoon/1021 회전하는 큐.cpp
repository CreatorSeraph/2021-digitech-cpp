#include <iostream>
#include <vector>

using namespace std;


class node {
public:
    node() {
        prev = nullptr;
        next = nullptr;
    }

    int data;
    node* prev;
    node* next;
};

class c_queue {
private:
    node* head;
    node* tail;
    int call_count;

public:
    c_queue() { }
    c_queue(int size) {
        head = nullptr;
        tail = nullptr;
        node* prev = nullptr;

        for (int i = 0; i < size; i++) {
            node* n = new node();
            if (i == 0)
                head = n;
            if (i == size - 1)
                tail = n;

            if (prev != nullptr) {
                prev->next = n;
                n->prev = prev;
            }

            n->data = i + 1;
            prev = n;
        }

        head->prev = tail;
        tail->next = head;

        call_count = 0;
    }
    ~c_queue() { }

    void find(int val) {

        node* left = head;
        node* right = head;

        int leftCount = 0, rightCount = 0;

        while (left->data != val) {
            left = left->prev;
            leftCount++;
        }

        while (right->data != val) {
            right = right->next;
            rightCount++;
        }

        node* target;
        if (leftCount < rightCount) {
            target = left;
            call_count += leftCount;
        } else {
            target = right;
            call_count += rightCount;
        }

        head = target->next;
        tail = target->prev;

        head->prev = tail;
        tail->next = head;

        delete target;
    }

    int callCount() {
        return call_count;
    }
};

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    c_queue* q = new c_queue(n);

    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;

        q->find(temp);
    }

    cout << q->callCount();

    delete q;

    return 0;
}
