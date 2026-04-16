#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;
typedef long long int lld;
int str2num(string s);
string num2str(int n);
int main(){
    //FASTIO;
    map<int, int> m;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        string a; int b;
        cin >> a >> b;
        m[str2num(a)] += b;
    }
    vector<int> v;
    for(auto i: m) v.push_back(i.first);
    sort(v.begin(), v.end());
    for(auto i: v){
        cout << num2str(i) << ' ' << m[i] << endl;
    }
    return 0;
}
int str2num(string s){
    int ret = 0;
    for(int i = 0; i < s.length(); i++){
        ret *= 36;
        if('0' <= s[i] && s[i] <= '9') ret += s[i] - '0';
        else ret += s[i] - 'A' + 10;
    }
    return ret;
}
string num2str(int n){
    if(n == 0) return "0";
    string ret = "";
    int s = pow(36, 4);
    while(n){
        int r = n / s;
        n %= s;
        s /= 36;
        if(r == 0) continue;
        if(r < 10) ret += '0' + r;
        else ret += 'A' + r - 10;
    }
    return ret;
}
