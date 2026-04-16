#include <stdio.h>
#define MAX_HEAP_SIZE 100000
int heap_count;
int heap[MAX_HEAP_SIZE];
void push(int data);
int pop();
void swap(int *a, int *b);
int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int cmd;
        scanf("%d", &cmd);
        if(cmd == 0) printf("%d\n", pop());
        else push(cmd);
    }
    return 0;
}
void push(int data){
    heap[++heap_count] = data;
    int child = heap_count;
    int parent = child / 2;
    while(child > 1 && heap[child] > heap[parent]){
        swap(&heap[child], &heap[parent]);
        child = parent;
        parent = child / 2;
    }
}
int pop(){
    if(heap_count == 0) return 0;
    int ret = heap[1];
    swap(&heap[heap_count--], &heap[1]);
    int parent = 1;
    int child = parent * 2;
    if(child + 1 <= heap_count){
        child = (heap[child] > heap[child + 1]) ? child : child + 1;
    }
    while (child <= heap_count && heap[parent] < heap[child]) {
		swap(&heap[parent], &heap[child]);
		parent = child;
		child = child * 2;
		if (child + 1 <= heap_count) {
			child = (heap[child] > heap[child + 1]) ? child : child + 1;
		}
	}
	return ret;
}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
