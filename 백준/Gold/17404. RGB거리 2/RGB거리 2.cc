#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long int lld;
typedef struct {
    int R, G, B;
} price;
constexpr int INF = 2'000'000;
int cache[1001][3];
int solve(vector<price> &v, int cur, int prev, int first);
int n;
int main(){
    int ans = 2e9;
    //FASTIO;
    cin >> n;
    vector<price> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].R >> v[i].G >> v[i].B;
    }
    memset(cache, -1, sizeof(int) * 1001 * 3);
    ans = min<int>(ans, v[0].R + solve(v, 1, 0, 0));
    memset(cache, -1, sizeof(int) * 1001 * 3);
    ans = min<int>(ans, v[0].G + solve(v, 1, 1, 1));
    memset(cache, -1, sizeof(int) * 1001 * 3);
    ans = min<int>(ans, v[0].B + solve(v, 1, 2, 2));
    cout << ans << endl;
    return 0;
}
int solve(vector<price> &v, int cur, int prev, int first){
    if(cur == n) {
        if (prev == first) return INF;
        else return 0;
    }
    int &ret = cache[cur][prev];
    if(ret != -1) return ret;
    //prev: R
    if(prev == 0){
        ret = min<int>(v[cur].G + solve(v, cur + 1, 1, first), v[cur].B + solve(v, cur + 1, 2, first));
    }
    //prev: G
    if(prev == 1){
        ret =  min<int>(v[cur].R + solve(v, cur + 1, 0, first), v[cur].B + solve(v, cur + 1, 2, first));
    }
    //prev: B
    if(prev == 2){
        ret =  min<int>(v[cur].R + solve(v, cur + 1, 0, first), v[cur].G + solve(v, cur + 1, 1, first));
    }
    return ret;
}
