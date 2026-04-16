#include <bits/stdc++.h>
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx,avx2,fma")

#define endl '\n'
using namespace std;
using ll = long long;
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

constexpr ll MOD = 1e9+7;
constexpr ll INF = 2e18;

void preprocess() {
    ll i, j;
}

void solve(ll tc) {
    // ll i, j;
    ll a, b, c, d, e, f, g, h, i, j, k;
    ll ans=0;
    vvl arr(11, vl(11));
    for (i=0;i<121;i++) cin>>arr[i/11][i%11];
    vl used(11);
    ll t=0;
    for (a=0;a<11;a++) {
        if (arr[a][0]==0) continue;
        used[a]=1;
        t+=arr[a][0];
        for (b=0;b<11;b++) {
            if (used[b] || arr[b][1]==0) continue;
            used[b]=1;
            t+=arr[b][1];
            for (c=0;c<11;c++) {
                if (used[c] || arr[c][2]==0) continue;
                used[c]=1;
                t+=arr[c][2];
                for (d=0;d<11;d++) {
                    if (used[d] || arr[d][3]==0) continue;
                    used[d]=1;
                    t+=arr[d][3];
                    for (e=0;e<11;e++) {
                        if (used[e] || arr[e][4]==0) continue;
                        used[e]=1;
                        t+=arr[e][4];
                        for (f=0;f<11;f++) {
                            if (used[f] || arr[f][5]==0) continue;
                            used[f]=1;
                            t+=arr[f][5];
                            for (g=0;g<11;g++) {
                                if (used[g] || arr[g][6]==0) continue;
                                used[g]=1;
                                t+=arr[g][6];
                                for (h=0;h<11;h++) {
                                    if (used[h] || arr[h][7]==0) continue;
                                    used[h]=1;
                                    t+=arr[h][7];
                                    for (i=0;i<11;i++) {
                                        if (used[i] || arr[i][8]==0) continue;
                                        used[i]=1;
                                        t+=arr[i][8];
                                        for (j=0;j<11;j++) {
                                            if (used[j] || arr[j][9]==0) continue;
                                            used[j]=1;
                                            t+=arr[j][9];
                                            for (k=0;k<11;k++) {
                                                if (used[k] || arr[k][10]==0) continue;
                                                t+=arr[k][10];
                                                // cout<<a<<b<<c<<d<<e<<f<<g<<h<<i<<j<<k<<endl;
                                                ans = max(ans, t);
                                                t-=arr[k][10];
                                            }
                                            t-=arr[j][9];
                                            used[j]=0;
                                        }
                                        t-=arr[i][8];
                                        used[i]=0;
                                    }
                                    t-=arr[h][7];
                                    used[h]=0;
                                }
                                t-=arr[g][6];
                                used[g]=0;
                            }
                            t-=arr[f][5];
                            used[f]=0;
                        }
                        t-=arr[e][4];
                        used[e]=0;
                    }
                    t-=arr[d][3];
                    used[d]=0;
                }
                t-=arr[c][2];
                used[c]=0;
            }
            t-=arr[b][1];
            used[b]=0;
        }
        t-=arr[a][0];
        used[a]=0;
    }
    cout<<ans<<endl;
}

int main() {
    setup();
    preprocess();

    ll testcase = 1;
    cin >> testcase;
    for (ll i = 1; i <= testcase; i++) {
        solve(i);
    }
}