#include <bits/stdc++.h>

#include <utility>
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx,avx2,fma")

using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;
using ld = long double;
using vd = vector<ld>;
using ull = unsigned long long;
using vp = vector<pll>;
using vvp = vector<vp>;
using tlll = array<ll, 3>;

#define endl '\n'

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

template <typename T>
ostream& operator<<(ostream &os, vector<T> arr) {
    if (arr.size()==0) return os<<"()";
    os<<'(';
    for (ll i=0;i<arr.size()-1;i++) os<<arr[i]<<' ';
    if (arr.size()) os<<arr.back();
    return os<<')';
}

constexpr ll MOD = 1e9+7;
// constexpr ll MOD = 998'244'353;
constexpr ll INF = 1e15;
constexpr ld eps = 1e-8;

void preprocess() {
    ll i, j;
}

void solve(ll tc){
    ll i, j;
    // select(A[], p, r, q) { # A[p..r]에서 q번째 작은 원소를 찾는다.
    //     if (p = r) then return A[p];
    //     t <- partition(A, p, r);  # 분할
    //     k <- t - p + 1;           # 기준원소가 전체에서 k번째 작은 원소임
    //     if (q < k) then return select(A, p, t - 1, q);  # 왼쪽 그룹으로 범위를 좁힘
    //     else if (q = k) then return A[t];               # 기준원소가 찾는 원소임
    //     else return select(A, t + 1, r, q - k);         # 오른쪽 그룹으로 범위를 좁힘
    // }
    //
    // partition(A[], p, r) {
    //     x <- A[r];    # 기준원소
    //     i <- p - 1;   # i는 x보다 작거나 같은 원소들의 끝 지점
    //     for j <- p to r - 1  # j는 아직 정해지지 않은 원소들의 시작 지점
    //         if (A[j] ≤ x) then A[++i] <-> A[j]; # i값 증가 후 A[i] <-> A[j] 교환
    //     if (i + 1 ≠ r) then A[i + 1] <-> A[r];  # i + 1과 r이 서로 다르면 A[i + 1]과 A[r]을 교환
    //     return i + 1;
    // }
    ll n, q, k; cin>>n>>q>>k;
    vl arr(n); cin>>arr;
    function<ll(ll, ll)> partition = [&arr, &k](ll p, ll r) {
        ll x = arr[r];
        ll i = p-1;
        for (ll j=p;j<r;j++) {
            if (arr[j]<=x) {
                swap(arr[++i], arr[j]);
                --k;
                if (k==0) {
                    cout<<min(arr[i], arr[j])<<' ';
                    cout<<max(arr[i], arr[j])<<endl;
                }
            }
        }
        if (i+1!=r) {
            swap(arr[i+1], arr[r]);
            --k;
            if (k==0) {
                cout<<min(arr[i+1], arr[r])<<' ';
                cout<<max(arr[i+1], arr[r])<<endl;
            }
        }
        return i+1;
    };
    function<void(ll, ll, ll)> select = [&partition, &select](ll p, ll r, ll q) {
        if (p==r) return;
        ll t = partition(p, r);
        ll x = t-p+1;
        if (q<x) select(p, t-1, q);
        else if (q==x) return;
        else select(t+1, r, q-x);
    };
    select(0, n-1, q);
    if (k>0) cout<<"-1\n";
}

int main() {
    setup();
    preprocess();

    ll testcase = 1;
    // cin >> testcase;
    for (ll i = 1; i     <= testcase; i++) {
        solve(i);
    }
}
