#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
typedef struct Queue {
    Node* first;
    Node* last;
    int count;
} Queue;
void init(Queue* queue) {
    queue->first = queue->last = NULL;
    queue->count = 0;
}
int size(Queue* queue) {
    return queue->count;
}
int empty(Queue* queue) {
    return queue->count == 0;
}
void push(Queue* queue, int item) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = item;
    if(!empty(queue))
        queue->last->next = newnode;
    else queue->first = newnode;
    queue->last = newnode;
    queue->count++;
}
int pop(Queue* queue) {
    if (empty(queue)) return -1;
    int ret = queue->first->data;
    Node* del = queue->first;
    queue->first = queue->first->next;
    free(del);
    queue->count--;
    return ret;
}
int front(Queue* queue) {
    if (empty(queue)) return -1;
    return queue->first->data;
}
int back(Queue* queue) {
    if (empty(queue)) return -1;
    return queue->last->data;
}
int main() {
    int n, item;
    char cmd[6];
    Queue queue;
    init(&queue);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", cmd);
        if (strcmp(cmd, "push") == 0) {
            scanf("%d", &item);
            push(&queue, item);
        }
        else if (strcmp(cmd, "pop") == 0)
            printf("%d\n", pop(&queue));
        else if (strcmp(cmd, "size") == 0)
            printf("%d\n", size(&queue));
        else if (strcmp(cmd, "empty") == 0)
            printf("%d\n", empty(&queue));
        else if (strcmp(cmd, "back") == 0)
            printf("%d\n", back(&queue));
        else printf("%d\n", front(&queue));
    }
}
