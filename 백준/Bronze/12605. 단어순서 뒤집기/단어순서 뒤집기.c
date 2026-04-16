#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
    char data[26];
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
void push(Stack* stack, char* item) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    strcpy(newnode->data, item);
    if (empty(stack) == 0)
        newnode->next = stack->first;
    stack->first = newnode;
    stack->count++;
}
int pop(Stack* stack) {
    if (empty(stack)) return -1;
    printf("%s ", stack->first->data);
    Node* del = stack->first;
    stack->first = stack->first->next;
    free(del);
    stack->count--;
    return 0;
}
int size(Stack* stack) {
    return stack->count;
}
int top(Stack* stack) {
    if (empty(stack)) return -1;
    return stack->first->data;
}
int main() {
    int n;
    scanf("%d", &n);
    char a[26];
    for (int i = 1; i <= n; i++) {
        Stack* stack = malloc(sizeof(Stack));
        init(stack);
        scanf(" %[^\n]s", a);
        char* ptr = strtok(a, " ");
        while (ptr != NULL) {
            push(stack, ptr);
            ptr = strtok(NULL, " ");
        }
        printf("Case #%d: ", i);
        while (!empty(stack)) pop(stack);
        free(stack);
        printf("\n");
    }
    return 0;
}
