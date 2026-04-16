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
int include(Queue *queue, int item){
    Node *node = queue->first;
    while(node->next != NULL){
        if(node->data == item) return 1;
        node = node->next;
    }
    return 0;
}
int main(){
    Queue *queue = malloc(sizeof(Queue));
    init(queue);
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)
        enqueue(queue, i);
    printf("<");
    while(size(queue) != 1){
        for(int i = 0; i < k - 1; i++)
            enqueue(queue, dequeue(queue));
        printf("%d, ", dequeue(queue));
    }
    printf("%d>", dequeue(queue));
    return 0;
}
