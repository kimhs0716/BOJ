/*
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
    int n, a;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        if(a == 0) pop(stack);
        else push(stack, a);
    }
    int s = 0;
    while(1){
        a = pop(stack);
        if(a == -1) break;
        s += a;
    }
    printf("%d", s);
}
*/
#include <stdio.h>
int main(){
    int n, c;
    scanf("%d", &n);
    char str[51];
    for(int i = 0; i < n; i++){
        scanf("%s", str);
        int i = 0;
        c = 0;
        int cor = 1;
        while(str[i]){
            if(c < 0){
                cor = 0;
                break;
            }
            if(str[i] == '(') c++;
            else c--;
            i++;
        }
        if(c != 0) cor = 0;
        printf(cor ? "YES\n" : "NO\n");
    }
    return 0;
}
