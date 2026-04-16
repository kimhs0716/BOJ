#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <map>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long int lld;
int main(){
    FASTIO;
    int n, m, cnt = 0; cin >> n >> m;
    map<string, bool> smap;
    while(n--){
        string s; cin >> s;
        smap[s] = 1;
    }
    while(m--){
        string s; cin >> s;
        if (smap[s]) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
