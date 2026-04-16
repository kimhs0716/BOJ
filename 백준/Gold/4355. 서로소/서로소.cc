#include <iostream>
#include <cmath>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long int lld;
bool isprime(lld n);
lld euler_phi(lld n);
lld gcd(lld a, lld b);
int main() {
    FASTIO;
    lld n; cin >> n;
    while(n){
        if(n == 1) cout << "0\n";
        else cout << euler_phi(n) << endl;
        cin >> n;
    }
    return 0;
}
bool isprime(lld n){
    if(n == 2) return true;
    if(n < 2 || n % 2 == 0) return false;
    lld i = 3;
    while(i * i <= n){
        if(n % i == 0) return false;
        i += 2;
    }
    return true;
}
lld euler_phi(lld n){
    if(n == 1) return 1;
    if(isprime(n)) return n - 1;
    int i = 1;
    while(true){
        if(!isprime(++i)) continue;
        if(n % i == 0){
            int cnt = 0;
            while(n % i == 0){
                cnt++;
                n /= i;
            }
            lld p_n = pow((lld)i, cnt);
            return (p_n - p_n / i) * euler_phi(n);
        }
    }
}
lld gcd(lld a, lld b){
    lld r;
    while (b != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
