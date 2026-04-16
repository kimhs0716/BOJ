#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}
int main(){
    int a, b; cin >> a >> b;
    b /= gcd(a, b);
    int i = 2, r = 1;
    while(i * i <= b){
        if(b % i == 0){
            while(b % i == 0) b /= i;
            r *= i;
        }
        i++;
    }
    r *= b;
    cout << r << '\n';
    return 0;
}
