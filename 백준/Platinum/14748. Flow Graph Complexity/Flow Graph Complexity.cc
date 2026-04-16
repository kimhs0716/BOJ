#include <bits/stdc++.h>
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
ostream& operator<<(ostream &os, vector<T> &arr) {
    if (arr.size()==0) return os<<"()";
    os<<'(';
    for (ll i=0;i<arr.size()-1;i++) os<<arr[i]<<' ';
    if (arr.size()) os<<arr.back();
    return os<<')';
}

constexpr ll MOD = 1e9+7;
// constexpr ll MOD = 998'244'353;
constexpr ll INF = 2e18;

void preprocess() {
    ll i, j, k;
}

bool check(string &str, ll s, ll e) {
    // cout<<s<<' '<<e<<' '<<str.substr(s, e-s+1)<<endl;
    if (s==e) return str[s]=='S';
    if (str[s]=='L' || str[s]=='B') {
        if (str[s+1]=='(') {
            ll left=s+2;
            ll right=left;
            ll cnt=1;
            while (cnt) {
                if (str[right]=='(') cnt++;
                if (str[right]==')') cnt--;
                right++;
            }
            right -= 2;
            if (!check(str, left, right)) return false;
            if (right+1==e) return true;
            if (str[right+2]!=',') return false;
            return check(str, right+3, e);
        }
        else if (str[s+1]=='[') {
            ll left=s+2;
            ll right=left;
            ll cnt=1;
            while (cnt) {
                if (str[right]=='[') cnt++;
                if (str[right]==']') cnt--;
                right++;
            }
            right -= 2;
            if (!check(str, left, right)) return false;
            if (right+1==e) return true;
            if (str[right+2]!=',') return false;
            return check(str, right+3, e);
        }
        else return false;
    }
    if (str[s]=='S') {
        if (str[s+1]==',') return check(str, s+2, e);
        else return false;
    }
    return false;
}

void solve(ll tc) {
    ll n;
    cin>>n;
    string a;
    cin.ignore();
    getline(cin,a);

    vector<char> st;
    string str;
    bool flag=true;
    for (auto ch: a) {
        if (ch!=' ') str+=ch;
        if (ch=='(' || ch=='[') st.push_back(ch);
        if (ch==')') {
            if (st.size() && st.back()=='(') st.pop_back();
            else flag=false;
        }
        if (ch==']') {
            if (st.size() && st.back()=='[') st.pop_back();
            else flag=false;
        }
        if (!flag) break;
    }
    if (st.size()) flag=false;
    if (!flag || !check(str, 0, str.size()-1)) {
        cout<<"-1\n";
        return;
    }

    ll comma=0;
    ll L=0;
    ll B=0;
    ll S=0;
    st.clear();

    for (ll i=0;i<a.size();i++) {
        if (a[i]==',') {
            comma++;
        }
        else if (a[i]=='L') {
            L++;
        }
        else if (a[i]=='B') {
            B++;
        }
        else if (a[i]=='S') {
            S++;
        }
        else if (a[i]==' ' || a[i]=='(' || a[i]==')' || a[i]=='[' || a[i]==']') {
            continue;
        }
        else {
            cout<<-1<<'\n';
            return;
        }
    }

    ll forward = comma+L*2+B*3;
    ll backward = L;
    ll V = L+L+B+B+S;
    cout<<forward+backward*n-V+2;
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