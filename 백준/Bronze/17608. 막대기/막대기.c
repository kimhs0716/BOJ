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
    Stack *stack = malloc(sizeof(Stack));
    init(stack);
    int n;
    scanf("%d", &n);
    int a;
    while(n--){
        scanf("%d", &a);
        push(stack, a);
    }
    int c = 0, max = 0;
    while(!empty(stack)){
        a = pop(stack);
        (a > max) && (c++, max = a);
    }
    printf("%d", c);
    return 0;
}
