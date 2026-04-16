#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>
#include <sstream>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int, int>
#define psi pair<string, int>
#define INF 1e+50
using namespace std;
typedef long long int lld;
int main(){
    FASTIO;
    map<int, bool> m;
    int n;
    while(cin >> n){
        m.clear();
        int cnt = 0;
        while(n--){
            int mask = 0;
            int t; cin >> t;
            while(t){
                mask |= 1 << (t % 10 - 1);
                t /= 10;
            }
            if(m[mask] == false){
                m[mask] = true;
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
