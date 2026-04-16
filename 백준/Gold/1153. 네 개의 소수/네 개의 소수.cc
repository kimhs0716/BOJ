#include <iostream>
bool isprime(int n);
using namespace std;
int main(){
    int n;
    cin >> n;
    if(n < 8){
        cout << -1 << endl;
        return 0;
    }
    for(int a = 2; a < n; a++){
        if(!isprime(a)) continue;
        for(int b = a; b < n; b++){
            if(!isprime(b)) continue;
            for(int c = b; c < n; c++){
                if(!isprime(c)) continue;
                int d = n - a - b - c;
                if(isprime(d)){
                    printf("%d %d %d %d\n", a, b, c, d);
                    return 0;
                }
            }
        }
    }
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
