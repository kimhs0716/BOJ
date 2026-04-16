#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    int n;
    cin >> n;
    int num;
    cin >> num;
    maxheap.push(num);
    for(int i = 1; i < n; i++){
        printf("%d\n", maxheap.top());
        scanf("%d", &num);
        if(num < maxheap.top()){
            maxheap.push(num);
        }
        else{
            minheap.push(num);
        }
        if(maxheap.size() == minheap.size() + 2){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if(maxheap.size() + 1 == minheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    printf("%d\n", maxheap.top());
    return 0;
}
