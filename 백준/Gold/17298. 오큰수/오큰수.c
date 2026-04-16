#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
typedef struct Stack {
    Node* first;
    int count;
} Stack;
void init(Stack* stack) {
    stack->first = NULL;
    stack->count = 0;
}
int empty(Stack* stack) {
    return stack->count == 0;
}
void push(Stack* stack, int n) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = n;
    if (empty(stack) == 0)
        newnode->next = stack->first;
    stack->first = newnode;
    stack->count++;
}
int pop(Stack* stack) {
    if (empty(stack)) return -1;
    int res = stack->first->data;
    Node* del = stack->first;
    stack->first = stack->first->next;
    free(del);
    stack->count--;
    return res;
}
int size(Stack* stack) {
    return stack->count;
}
int top(Stack* stack) {
    if (empty(stack)) return -1;
    return stack->first->data;
}
int main() {
    Stack real_stack;
    Stack* stack = &real_stack;
    init(stack);
    int n, a, b;
    scanf("%d", &n);
    int nge[n], arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < n; i++){
        if(empty(stack)) push(stack, i);
        while(!empty(stack) && arr[top(stack)] < arr[i]){
            nge[pop(stack)] = arr[i];
        }
        push(stack, i);
    }
    while(!empty(stack)){
        nge[pop(stack)] = -1;
    }
    for(int i = 0; i < n; i++)
        printf("%d ", nge[i]);
}
