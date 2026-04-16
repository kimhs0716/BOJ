#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;

using elem = array<ll, 10>;

elem add(const elem &a, const elem &b) {
    elem ret;
    for (ll i=0;i<10;i++)
        ret[i] = a[i]+b[i];
    return ret;
}

elem sub(const elem &a, const elem &b) {
    elem ret;
    for (ll i=0;i<10;i++)
        ret[i] = a[i]-b[i];
    return ret;
}

bool check(const elem &a) {
    for (ll i=0;i<10;i++) {
        if (a[i]>=2) return false;
    }
    return true;
}

void preprocess() {
#ifdef KIMHS
    freopen("boj.in", "r", stdin);
    freopen("boj.out", "w", stdout);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
}

void solve(ll tc) {
    ll i, j;
    ll r, c; cin>>r>>c;
    vvl arr(r, vl(c));
    for (auto &x: arr) {
        string s; cin>>s;
        for (i=0;i<c;i++) {
            x[i] = s[i]-'0';
        }
    }
    vector pre(r+1, vector<elem>(c+1));
    for (i=1;i<=r;i++) {
        for (j=1;j<=c;j++) {
            pre[i][j] = pre[i][j-1];
            pre[i][j] = add(pre[i][j], pre[i-1][j]);
            pre[i][j] = sub(pre[i][j], pre[i-1][j-1]);
            pre[i][j][arr[i-1][j-1]]++;
        }
    }
    // for (ll x : pre[1][1]) cout<<x<<' '; cout<<endl;
    // for (ll x : pre[1][2]) cout<<x<<' '; cout<<endl;
    ll ans = 0;
    for (i=0;i<r;i++) {
        for (j=0;j<c;j++) {
            for (ll h=1;h<=10;h++) {
                for (ll w=1;w*h<=10;w++) {
                    if (i+h>=r+1 || j+w>=c+1) continue;
                    elem cur = pre[i+h][j+w];
                    cur = sub(cur, pre[i][j+w]);
                    cur = sub(cur, pre[i+h][j]);
                    cur = add(cur, pre[i][j]);
                    // cout<<i<<' '<<j<<' '<<h<<' '<<w<<": ";
                    // for (ll x : cur) cout<<x<<' ';
                    // cout<<endl;
                    if (check(cur)) ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
}

int main() {
    preprocess();
    ll testcase = 1;
    // cin >> testcase;
    for (ll tc = 1; tc <= testcase; tc++) {
        solve(tc);
    }
}