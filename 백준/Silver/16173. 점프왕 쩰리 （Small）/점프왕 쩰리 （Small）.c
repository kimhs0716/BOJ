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
void init(Queue*);
int empty(Queue*);
int size(Queue*);
void enqueue(Queue*, int);
int dequeue(Queue*);
int front(Queue*);
int back(Queue*);
int main(){
    Queue *qx = (Queue *)malloc(sizeof(Queue));
    Queue *qy = (Queue *)malloc(sizeof(Queue));
    init(qx);
    init(qy);
    int size;
    scanf("%d", &size);
    int arr[size][size];
    int visited[size][size];
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++){
            scanf("%d", &arr[i][j]);
            visited[i][j] = 0;
        }
    int x, y;
    enqueue(qx, 0);
    enqueue(qy, 0);
    int found = 0;
    while(1){
        if(empty(qx)) break;
        x = dequeue(qx);
        y = dequeue(qy);
        if(visited[y][x]) continue;
        int cur = arr[y][x];
        if(cur == -1){
            found = 1;
            break;
        }
        if(x + cur < size){
            enqueue(qx, x + cur);
            enqueue(qy, y);
        }
        if(y + cur < size){
            enqueue(qx, x);
            enqueue(qy, y + cur);
        }
        visited[y][x] = 1;
    }
    printf(found ? "HaruHaru" : "Hing");
    free(qx);
    free(qy);
    return 0;
}
void init(Queue *queue){
    queue->count = 0;
    queue->first = queue->last = NULL;
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
    newnode->next = NULL;
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
    queue->count--;
    free(del);
    return ret;
}
int front(Queue *queue){
    if(empty(queue)) return -1;
    return queue->last->data;
}
int back(Queue *queue){
    if(empty(queue)) return -1;
    return queue->first->data;
}
