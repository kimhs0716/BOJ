#include <iostream>
using namespace std;
bool isprime(int n);
bool issprime(int n);
void dfs(int depth);
int res, n;
int main(){
    cin >> n;
    res = 0;
    dfs(0);
    return 0;
}
bool isprime(int n){
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    int i = 3;
    while(i * i <= n){
        if(n % i == 0) return false;
        i += 2;
    }
    return true;
}
void dfs(int depth){
    if(depth == n)
        printf("%d\n", res);
    for(int i = 0; i < 10; i++){
        if(isprime(res * 10 + i) == false) continue;
        res = res * 10 + i;
        dfs(depth + 1);
        res /= 10;
    }
}
