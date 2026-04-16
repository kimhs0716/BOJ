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

template <typename T>
ostream& operator<<(ostream &os, vector<T> &arr) {
    for (auto &x: arr) os<<x<<' ';
    return os;
}

constexpr ll MOD = 1e9+7;
constexpr ll INF = 2e18;

void preprocess() {
    ll i, j;
}

struct Point {
    ll x, y, idx;
    bool operator<(const Point &rhs) const {
        if (x==rhs.x) return y<rhs.y;
        return x<rhs.x;
    }
    Point operator-(const Point &rhs) const {
        return Point(x-rhs.x, y-rhs.y);
    }
};

ll outer(Point a, Point b) {
    return a.x*b.y-a.y*b.x;
}

ll ccw(Point &p1, Point &p2, Point &p3) {
    return outer(p2-p1, p3-p1);
}

void solve(ll testcase) {
    ll i, j;
    ll n; cin>>n;
    bool flag=false;
    map<ll, vector<Point>> xmap, ymap;
    vector<Point> arr(n);
    vector<pll> edge(n, {-1, -1});
    for (i=0;i<n;i++) {
        Point p; cin>>p.x>>p.y;
        p.idx=i;
        arr[i]=p;
        xmap[p.x].push_back(p);
        ymap[p.y].push_back(p);
    }
    for (auto &[x, vp]: xmap) {
        if (vp.size()&1) flag=true;
        if (flag) break;
        sort(vp.begin(), vp.end());
        for (i=0;i<vp.size();i+=2) {
            edge[vp[i].idx].first=vp[i+1].idx;
            edge[vp[i+1].idx].first=vp[i].idx;
        }
    }
    for (auto &[y, vp]: ymap) {
        if (vp.size()&1) flag=true;
        if (flag) break;
        sort(vp.begin(), vp.end());
        for (i=0;i<vp.size();i+=2) {
            edge[vp[i].idx].second=vp[i+1].idx;
            edge[vp[i+1].idx].second=vp[i].idx;
        }
    }
    for (i=0;i<n;i++) if (edge[i].first==-1 || edge[i].second==-1) flag=true;
    vl polygon;
    polygon.push_back(0);
    vl vis(n);
    vis[0]=1;
    ll cur=0;
    ll nxt;
    while (cur!=edge[0].second) {
        if (flag) break;
        // cout<<cur<<' ';
        nxt=edge[cur].first;
        if (vis[nxt]) {
            nxt=edge[cur].second;
            if (vis[nxt]) flag=true;
        }
        polygon.push_back(nxt);
        vis[nxt]=1;
        cur=nxt;
    }
    // cout<<endl;
    // for (i=0;i<n;i++) cout<<polygon[i]<<' '; cout<<endl;
    // for (i=0;i<n;i++) {
    //     pll x=edge[i];
    //     cout<<i<<": "<<x.first<<' '<<x.second<<endl;
    // }
    if (accumulate(vis.begin(), vis.end(), 0LL)!=n) flag=true;
    // cout<<flag<<endl;
    for (i=0;i<n;i++) {
        if (flag) break;
        for (j=i+1;j<n;j++) {
            if (flag) break;
            Point p1=arr[polygon[i]], p2=arr[polygon[(i+1)%n]];
            Point p3=arr[polygon[j]], p4=arr[polygon[(j+1)%n]];
            if (p1.x==p2.x && p3.x==p4.x) continue;
            if (p1.y==p2.y && p3.y==p4.y) continue;
            if (ccw(p1, p2, p3)*ccw(p1, p2, p4)<0 && ccw(p3, p4, p1)*ccw(p3, p4, p2)<0) flag=true;
        }
    }
    if (flag) cout<<"NO\n";
    else cout<<"YES\n";
    // if (!flag)
    //     for (i=0;i<n;i++) {
    //         cout<<arr[polygon[i]].x<<' ';
    //         cout<<arr[polygon[i]].y<<endl;
    //     }
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