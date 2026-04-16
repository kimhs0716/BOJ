#include <iostream>
#include <cmath>
using namespace std;
bool isprime(int);
int main(){
    int a, b;
    cin >> a >> b;
    if(isprime(a) && isprime(a + b * (int)1e6))
        cout << "Yes";
    else cout << "No";
    cout << endl;
}
bool isprime(int n){
    if(n < 2) return false;
    if(n == 2) return true;
    double loop = sqrt(n);
    for(int i = 3; i <= loop; i += 2){
        if(n % i == 0) return false;
    }
    return true;
}
