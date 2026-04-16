#include <bits/stdc++.h>

#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

void _init() {
#ifndef BOJ
    freopen("boj.in", "r", stdin);
    // freopen("boj.out", "w", stdout);
#endif // BOJ
}

using namespace std;

typedef struct Node {
    int data;
    Node* prev, * next;
    Node(int x, Node* prev, Node* next) : data(x), prev(prev), next(next) {}
} Node;

class Deque {
public:
    Node* head, * tail;
    int __size;
    Deque() {
        head = tail = nullptr;
        __size = 0;
    }
    void push_back(int x) {
        Node* new_node = new Node(x, nullptr, nullptr);
        if (__size != 0) {
            new_node->prev = tail;
            tail->next = new_node;
        }
        else {
            head = new_node;
        }
        tail = new_node;
        __size++;
    }
    void push_front(int x) {
        Node* new_node = new Node(x, nullptr, nullptr);
        if (__size != 0) {
            new_node->next = head;
            head->prev = new_node;
        }
        else {
            tail = new_node;
        }
        head = new_node;
        __size++;
    }
    int front() {
        if (__size == 0) return -1;
        return head->data;
    }
    int back() {
        if (__size == 0) return -1;
        return tail->data;
    }
    void pop_back() {
        if (__size == 0) return;
        Node* node = tail;
        if (__size == 1) {
            head = nullptr;
        }
        else {
            tail = node->prev;
            tail->next = nullptr;
        }
        delete node;
        __size--;
    }
    void pop_front() {
        if (__size == 0) return;
        Node* node = head;
        if (__size == 1) {
            tail = nullptr;
        }
        else {
            head = node->next;
            head->prev = nullptr;
        }
        delete node;
        __size--;
    }
    int size() {
        return __size;
    }
    int empty() {
        return __size == 0;
    }
};

int main() {
    FASTIO;
    _init();

    Deque dq;
    int n; cin >> n;
    while (n--) {
        string cmd; cin >> cmd;
        if (cmd == "push_front") {
            int x; cin >> x;
            dq.push_front(x);
        }
        else if (cmd == "push_back") {
            int x; cin >> x;
            dq.push_back(x);
        }
        else if (cmd == "pop_front") {
            cout << dq.front() << endl;
            dq.pop_front();
        }
        else if (cmd == "pop_back") {
            cout << dq.back() << endl;
            dq.pop_back();
        }
        else if (cmd == "front") {
            cout << dq.front() << endl;
        }
        else if (cmd == "back") {
            cout << dq.back() << endl;
        }
        else if (cmd == "size") {
            cout << dq.size() << endl;
        }
        else if (cmd == "empty") {
            cout << dq.empty() << endl;
        }
    }

    return 0;
}
