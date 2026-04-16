#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
} Node;
typedef struct Queue{
    int count;
    Node *first;
    Node *last;
} Queue;
void init(Queue *queue){
    queue->count = 0;
    queue->first = queue->last = 0;
}
int empty(Queue *queue){
    return queue->count == 0;
}
int size(Queue *queue){
    return queue->count;
}
void enqueue(Queue *queue, int item){
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = item;
    if(empty(queue)) queue->first = newnode;
    else queue->last->next = newnode;
    queue->last = newnode;
    queue->count++;
}
int dequeue(Queue *queue){
    if(empty(queue)) return -1;
    Node *del = queue->first;
    int ret = del->data;
    queue->first = del->next;
    free(del);
    queue->count--;
    return ret;
}
int main(){
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    init(queue);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        enqueue(queue, i);
    while(size(queue) != 1){
        printf("%d ", dequeue(queue));
        enqueue(queue, dequeue(queue));
    }
    printf("%d ", dequeue(queue));
    return 0;
}
