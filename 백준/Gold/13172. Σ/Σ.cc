#include <iostream>
#define mod 1000000007
using namespace std;
typedef long long int lld;
lld __pow(lld a, int n, int m){
    if(n == 0) return 1;
    lld res = __pow(a, n / 2, m);
    res *= res;
    res %= m;
    if(n & 1) res *= a;
    res %= m;
    return res;
}
lld gcd(lld a, lld b){
    lld r;
    while(b != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
class Fraction{
public:
    lld ja, mo;
    Fraction(lld j, lld m){
        ja = j;
        mo = m;
    }
    Fraction operator+(Fraction f1){
        return Fraction(ja * f1.mo + mo * f1.ja, mo * f1.mo);
    }
    void simplify(){
        lld g = gcd(ja, mo);
        ja /= g;
        mo /= g;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    lld res = 0;
    while(t--){
        lld n, s;
        cin >> n >> s;
        lld g = gcd(s, n);
        s /= g;
        n /= g;
        res += s * __pow(n, mod - 2, mod) % mod;
        res %= mod;
    }
    cout << res << endl;
    return 0;
}
