#include <iostream>
#include <cmath>
#include <vector>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long int lld;
bool isprime(lld n);
lld euler_phi(lld n);
lld gcd(lld a, lld b);
vector<lld> divs(lld n){
    vector<lld> ret;
    lld i;
    for(i = 1; i * i < n; i++){
        if(n % i == 0){
            ret.push_back(i);
            ret.push_back(n / i);
        }
    }
    if(i * i == n) ret.push_back(i);
    return ret;
}
int main() {
    //FASTIO;
    lld n; cin >> n;
    vector<lld> v = divs(n);
    bool found = 0;
    for(auto x = v.begin(); x < v.end(); x++){
        if(*x * euler_phi(*x) == n) { found = 1; cout << *x << endl; }
    }
    if(!found) cout << "-1\n";
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
