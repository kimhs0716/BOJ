#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
int isEmpty(Stack* stack) {
    return stack->count == 0;
}
void push(Stack* stack, int n) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = n;
    if (isEmpty(stack) == 0)
        newnode->next = stack->first;
    stack->first = newnode;
    stack->count++;
}
int pop(Stack* stack) {
    if (isEmpty(stack)) return -1;
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
    if (isEmpty(stack)) return -1;
    return stack->first->data;
}
int main() {
    Stack real_stack;
    Stack* stack = &real_stack;
    init(stack);
    int n;
    scanf("%d", &n);
    char cmd[6];
    int item;
    for (int i = 0; i < n; i++) {
        scanf("%s", cmd);
        if (strcmp(cmd, "push") == 0) {
            scanf("%d", &item);
            push(stack, item);
        }
        else if (strcmp(cmd, "pop") == 0) {
            printf("%d\n", pop(stack));
        }
        else if (strcmp(cmd, "size") == 0) {
            printf("%d\n", size(stack));
        }
        else if (strcmp(cmd, "top") == 0) {
            printf("%d\n", top(stack));
        }
        else printf("%d\n", isEmpty(stack));
    }
}
