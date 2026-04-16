#include <iostream>
using namespace std;
bool isprime(int n);
bool include(int a, int b);
int main(){
    int a, b, d, cnt = 0;
    cin >> a >> b >> d;
    for(int i = a; i <= b; i++){
        if(isprime(i) && include(i, d)) cnt++;
    }
    cout << cnt << endl;
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
bool include(int a, int b){
    while(a){
        if(a % 10 == b) return true;
        a /= 10;
    }
    return false;
}
