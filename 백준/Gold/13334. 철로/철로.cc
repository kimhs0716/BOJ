#include <bits/stdc++.h>
#pragma warning(disable:4996)
#pragma comment(linker,"/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
using ld = long double;
using pld = pair<ld,ld>;
using vl = vector<ll>;
using vvl = vector<vl>;
using tlll = tuple<ll,ll,ll>;

#ifdef ONLINE_JUDGE
constexpr bool ndebug = true;
#else
constexpr bool ndebug = false;
#endif

void setup() {
    if (!ndebug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    else {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
}

void preprocess() {
    ll i, j, k;
}

struct Point {
    ll x, idx;
};

void solve() {
    ll i, j, k;
    ll n, d; cin>>n;
    vector<Point> pts(n<<1);
    vector<char> status(n, 0);
    for (i=0;i<n;i++) {
        cin>>pts[i<<1].x>>pts[i<<1|1].x;
        pts[i<<1].idx=pts[i<<1|1].idx=i;
    }
    cin>>d;
    sort(pts.begin(), pts.end(), [](const Point &a, const Point &b) {
        return a.x < b.x;
    });
    deque<Point> dq;
    ll cnt=0, ans=0;
    ll idx=0;
    while (idx<2*n) {
        while (dq.size() && dq.front().x+d<pts[idx].x) {
            auto p = dq.front();
            dq.pop_front();
            status[p.idx]--;
            if (status[p.idx]) cnt--;
        }
        auto p = pts[idx++];
        dq.push_back(p);
        if (status[p.idx]) cnt++;
        status[p.idx]++;
        if (cnt>ans) ans=cnt;
        // cout<<idx<<' ';
        // cout<<"(";
        // for (i=0;i<n;i++) cout<<(ll)status[i]<<' ';
        // cout<<")\n";
    }
    cout<<ans<<'\n';
}

int main() {
    setup();
    preprocess();
    ll t = 1;
    // cin >> t;
    for (ll test=1; test<=t; test++) {
        solve();
    }
    return 0;
}