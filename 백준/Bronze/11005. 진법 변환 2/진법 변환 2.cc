#include<iostream>
using namespace std;
char digit(int n);
void jinbeop(int n, int i);
int main(){
    int n, i;
    cin >> n >> i;
    jinbeop(n, i);
    return 0;
}
char digit(int n){
    if(n < 10) return n + '0';
    return n + 'A' - 10;
}
void jinbeop(int n, int i){
    if(n == 0) return;
    jinbeop(n / i, i);
    printf("%c", digit(n % i));
}
