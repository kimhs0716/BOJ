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
    int n;
    scanf("%d", &n);
    char cmd[6];
    int item;
    for (int i = 0; i < n; i++) {
        scanf("%s", cmd);
        if (strcmp(cmd, "A") == 0) {
            push(stack, 1);
        }
        else {
            item = pop(stack);
            if(item == -1){
                printf("NO");
                return 0;
            }
        }
    }
    if(empty(stack))
        printf("YES");
    else printf("NO");
    return 0;
}
