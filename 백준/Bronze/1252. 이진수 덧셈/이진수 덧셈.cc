#define private public
#include <bitset>
#undef private
#include <x86intrin.h>

#include <bits/stdc++.h>
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx,avx2,fma")

#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;
using ld = long double;

void setup() {
#ifdef KIMHS
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
}

template <typename T>
istream& operator>>(istream &is, vector<T> &arr) {
    for (auto &x: arr) is>>x;
    return is;
}

constexpr ll MOD = 1e9+7;
constexpr ll INF = 2e18;

ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll modpow(ll a, ll b, ll rem){ll p=1;a%=rem;for(;b;b>>=1,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}
pll extended_gcd(ll a, ll b) {
    if (b==0) return {1, 0};
    auto t=extended_gcd(b, a%b);
    return {t.second, t.first-t.second*(a/b)};
}
ll modinverse(ll a, ll m) {
    return (extended_gcd(a, m).first%m+m)%m;
}

void preprocess() {
    ll i, j;
}

template <size_t _Nw>
void _M_do_sub(_Base_bitset<_Nw> &A, const _Base_bitset<_Nw> &B) {
    for (int i=0, c=0;i<_Nw;i++)
        c=_subborrow_u64(c, A._M_w[i], B._M_w[i], (ull*)&A._M_w[i]);
}
template <>
void _M_do_sub(_Base_bitset<1> &A, const _Base_bitset<1> &B) {
    A._M_w -= B._M_w;
}
template <size_t _Nb>
bitset<_Nb> &operator-=(bitset<_Nb> &A, const bitset<_Nb> &B) {
    _M_do_sub(A, B);
    return A;
}
template <size_t _Nb>
inline bitset<_Nb> operator-(const bitset<_Nb> &A, const bitset<_Nb> &B) {
    bitset<_Nb> C(A);
    return C -= B;
}
template <size_t _Nw>
void _M_do_add(_Base_bitset<_Nw> &A, const _Base_bitset<_Nw> &B) {
    for (int i=0, c=0;i<_Nw;i++)
        c=_addcarry_u64(c, A._M_w[i], B._M_w[i], (ull*)&A._M_w[i]);
}
template <>
void _M_do_add(_Base_bitset<1> &A, const _Base_bitset<1> &B) {
    A._M_w += B._M_w;
}
template <size_t _Nb>
bitset<_Nb> &operator+=(bitset<_Nb> &A, const bitset<_Nb> &B) {
    _M_do_add(A, B);
    return A;
}
template <size_t _Nb>
inline bitset<_Nb> operator+(const bitset<_Nb> &A, const bitset<_Nb> &B) {
    bitset<_Nb> C(A);
    return C += B;
}

void solve(ll tc) {
    ll i, j;
    string a, b; cin>>a>>b;
    bitset<100> A(a), B(b);
    auto C=A+B;
    bool flag=true;
    for (i=100;i>=0;i--) {
        if (flag && C[i]==0) continue;
        flag=false;
        cout<<C[i];
    }
    if (flag) cout<<'0';
    cout<<endl;
}

int main() {
    setup();
    preprocess();

    ll testcase = 1;
    // cin >> testcase;
    for (ll i = 1; i <= testcase; i++) {
        solve(i);
    }
}