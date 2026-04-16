#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#define endl '\n'

using namespace std;

typedef struct Node {
    int elem;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct {
    Node *first;
    Node *last;
} DLinkedList;

Node *getNthNode(DLinkedList *dl, int n) {
    Node *ret = dl->first;
    while(n--) ret = ret->next;
    return ret;
}

void print(DLinkedList *dl) {
    Node *s = dl->first;
    while(s) {
        cout << s->elem + 1 << ' ';
        s = s->next;
    }
}
void rprint(DLinkedList *dl) {
    Node *s = dl->last;
    while(s) {
        cout << s->elem + 1 << ' ';
        s = s->prev;
    }
}

int main() {
    int n, m; cin >> n >> m;
    DLinkedList *dl = new DLinkedList;
    Node *newNode = new Node;
    newNode->elem = 0;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    dl->first = dl->last = newNode;

    for(int i = 1; i < n; i++) {
        Node *newNode = new Node;
        newNode->elem = i;
        newNode->prev = dl->last;
        newNode->prev->next = newNode;
        dl->last = newNode;
        newNode->next = nullptr;
    }

    while(m--) {
        //print(dl); cout << endl; //rprint(dl); cout << endl;
        int i, j, k; cin >> i >> j >> k;
        i--, j--, k--;
        Node *s, *e, *m;
        s = getNthNode(dl, i);
        e = getNthNode(dl, j);
        m = getNthNode(dl, k);

        if(s == m) continue;

        Node *ss = s->prev;
        if(s->prev != nullptr) s->prev->next = m;
        else dl->first = m;
        s->prev = e;

        m->prev->next = e->next;
        if(e->next != nullptr) e->next->prev = m->prev;
        e->next = s;

        m->prev = ss;
    }

    print(dl);

    return 0;
}
