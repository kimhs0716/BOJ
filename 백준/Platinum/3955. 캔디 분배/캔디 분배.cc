#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

ll gcd(ll x, ll y) { return __gcd(x, y); }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
ll mod(ll a, ll b) { return ((a%b) + b) % b; }
ll ext_gcd(ll a, ll b, ll &x, ll &y) { //ax + by = gcd(a, b)
  ll g = a; x = 1, y = 0;
  if (b) g = ext_gcd(b, a % b, y, x), y -= a / b * x;
  return g;
}
ll inv(ll a, ll m){ //return x when ax mod m = 1, fail -> -1
    ll x, y;
    ll g = ext_gcd(a, m, x, y);
    if(g > 1) return -1;
    return mod(x, m);
}

void solve(){
    ll k, c; cin >> k >> c;
    if(k == 1 && c == 1){ cout << 2 << "\n"; return; }
    if(c == 1){
        if(k+1 > 1e9){ cout << "IMPOSSIBLE\n"; return; }
        else{ cout << k+1 << "\n"; return; }
    }
    if(k == 1){ cout << 1 << "\n"; return; }
    if(gcd(k, c) != 1){ cout << "IMPOSSIBLE\n"; return; }
    ll t = inv(c, k);
    if(t > 1e9){ cout << "IMPOSSIBLE\n"; return; }
    cout << t << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t; while(t--) solve();
}