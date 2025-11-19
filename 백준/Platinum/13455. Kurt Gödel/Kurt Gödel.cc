#include <bits/stdc++.h>
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx,avx2,fma")

using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;
using ld = long double;
using ull = unsigned long long;

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

constexpr ll MOD = 1e9+7;
constexpr ll INF = 2e18;

ll modpow(ll n, ll k, ll m) {
    ll ret=1;
    n%=m;
    while (k) {
        if (k&1) ret=ret*n%m;
        n=n*n%m;
        k>>=1;
    }
    return ret;
}

ll modinv(ll n, ll p) {
    return modpow(n, p-2, p);
}

void preprocess() {
    ll i, j;
}

void solve(ll tc){
    ll i, j;
    ll l, r, p;
    while (true) {
        cin>>l>>r>>p;
        if (!l) break;
        array<ll, 8> primes {2, 3, 5, 7, 11, 13, 17, 19};
        bool f=false;
        for (i=0;i<l;i++) {
            if (p==primes[i]) {
                if (r==0) {
                    cout<<"ambiguous\n";
                }
                else {
                    cout<<"not a word\n";
                }
                f=true;
            }
            if (f) break;
        }
        if (f) continue;
        // array<ll, 8> inv;
        // for (i=0;i<8;i++) inv[i]=modinv(primes[i], p);
        array<array<ll, 26>, 8> pe;
        for (i=0;i<8;i++) {
            pe[i][0] = primes[i];
            for (j=1;j<26;j++) pe[i][j] = pe[i][j-1]*primes[i]%p;
        }
        unordered_map<ll, pair<array<ll, 4>, bool>> left, right;
        // left[1]={{0, 0, 0, 0}, false};
        for (ll a=1;a<=26;a++) {
            for (ll b=1;b<=26;b++) {
                for (ll c=1;c<=26;c++) {
                    for (ll d=1;d<=26;d++) {
                        if (l==1) {
                            if (b!=1 || c!=1 || d!=1) continue;
                            if (left.contains(pe[0][a-1])) left[pe[0][a-1]].second=true;
                            else left[pe[0][a-1]] = {{a, 0, 0, 0}, false};
                        }
                        if (l==2) {
                            if (c!=1 || d!=1) continue;
                            ll key = pe[0][a-1]*pe[1][b-1]%p;
                            if (left.contains(key)) left[key].second=true;
                            else left[key] = {{a, b, 0, 0}, false};
                        }
                        if (l==3) {
                            if (d!=1) continue;
                            ll key = pe[0][a-1]*pe[1][b-1]%p*pe[2][c-1]%p;
                            if (left.contains(key)) left[key].second=true;
                            else left[key] = {{a, b, c, 0}, false};
                        }
                        if (l>=4) {
                            ll key = pe[0][a-1]*pe[1][b-1]%p*pe[2][c-1]%p*pe[3][d-1]%p;
                            if (left.contains(key)) left[key].second=true;
                            else left[key] = {{a, b, c, d}, false};
                        }
                    }
                }
            }
        }
        if (l<=4) right[1]={{0, 0, 0, 0}, false};
        for (ll a=1;a<=26;a++) {
            for (ll b=1;b<=26;b++) {
                for (ll c=1;c<=26;c++) {
                    for (ll d=1;d<=26;d++) {
                        if (l==5) {
                            if (b!=1 || c!=1 || d!=1) continue;
                            if (right.contains(pe[4][a-1])) right[pe[4][a-1]].second=true;
                            else right[pe[4][a-1]] = {{a, 0, 0, 0}, false};
                        }
                        if (l==6) {
                            if (c!=1 || d!=1) continue;
                            ll key = pe[4][a-1]*pe[5][b-1]%p;
                            if (right.contains(key)) right[key].second=true;
                            else right[key] = {{a, b, 0, 0}, false};
                        }
                        if (l==7) {
                            if (d!=1) continue;
                            ll key = pe[4][a-1]*pe[5][b-1]%p*pe[6][c-1]%p;
                            if (right.contains(key)) right[key].second=true;
                            else right[key] = {{a, b, c, 0}, false};
                        }
                        if (l>=8) {
                            ll key = pe[4][a-1]*pe[5][b-1]%p*pe[6][c-1]%p*pe[7][d-1]%p;
                            if (right.contains(key)) right[key].second=true;
                            else right[key] = {{a, b, c, d}, false};
                        }
                    }
                }
            }
        }
        // cout<<left.size()<<endl;
        // cout<<right.size()<<endl;
        // for (auto &it: left) {
        //     cout<<it.first<<": ";
        //     cout<<it.second.first[0]<<' ';
        //     cout<<it.second.first[1]<<' ';
        //     cout<<it.second.first[2]<<' ';
        //     cout<<it.second.first[3]<<' ';
        //     cout<<endl;
        // }
        bool found=false, ambi=false;
        array<ll, 4> left_ans, right_ans;
        for (auto &it: left) {
            ll cand = r * modinv(it.first, p) % p;
            if (!right.contains(cand)) continue;
            auto &rarr = right[cand];
            // cout<<it.first<<' '<<cand<<endl;
            // cout<<it.second.second<<endl;
            if (it.second.second || rarr.second) {
                found=true, ambi=true;
            }
            else {
                if (found) ambi=true;
                found=true;
                left_ans=it.second.first;
                right_ans=rarr.first;
            }
            if (ambi) break;
        }
        if (ambi) cout<<"ambiguous\n";
        else if (!found) cout<<"not a word\n";
        else {
            for (i=0;i<min(l, 4LL);i++) cout<<(char)(64+left_ans[i]);
            for (i=0;i<min(l-4, 4LL);i++) cout<<(char)(64+right_ans[i]);
            cout<<endl;
        }
    }
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