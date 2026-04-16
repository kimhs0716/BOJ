#include <iostream>
#include <vector>
#include <cstring>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long int lld;
int solve(vector<int> &v, int cur);
int cache[1001];
int n;
int main(){
    //FASTIO;
    memset(cache, -1, 4004);
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    cout << solve(v, n) << endl;
    return 0;
}
int solve(vector<int> &v, int cur){
    if(cur == 0) return 0;
    int &ret = cache[cur];
    if(ret != -1) return ret;
    for(int i = 1; i <= cur; i++){
        ret = max<int>(ret, solve(v, cur - i) + v[i - 1]);
    }
    return ret;
}
