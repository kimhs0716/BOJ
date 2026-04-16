#include <iostream>
#include <cmath>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long int lld;
bool isprime(lld n);
lld euler_phi(lld n);
lld gcd(lld a, lld b);
lld dp[50001];
int main() {
    FASTIO;
    lld n; cin >> n;
    lld s = 0;
    for(int i = 2; i <= n; i++) s += euler_phi(i);
    cout << s << endl;
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
    if(n == 1) return dp[n] = 1;
    if(isprime(n)) return dp[n] = n - 1;
    if(dp[n]) return dp[n];
    int i = 1;
    lld nn = n;
    while(true){
        if(!isprime(++i)) continue;
        if(n % i == 0){
            int cnt = 0;
            while(n % i == 0){
                cnt++;
                n /= i;
            }
            lld p_n = pow((lld)i, cnt);
            return dp[nn] = (p_n - p_n / i) * euler_phi(n);
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
