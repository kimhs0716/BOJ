#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>
#include <sstream>
#include <numeric>
#include <cstdlib>
#include <ctime>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int, int>
#define psi pair<string, int>
#define pll pair<lld, lld>
#define INF 987654321
using namespace std;
typedef long long int lld;
int main(){
    FASTIO;
    int n; cin >> n;
    int cnt = 0;
    vector<int> lis(1);
    lis[0] = -1000000001;
    for(int i = 0; i < n; i++) {
        int t; cin >> t;
        if(lis[cnt] < t){
            lis.push_back(t);
            cnt++;
        }
        else{
            vector<int>::iterator iter = lower_bound(lis.begin(), lis.end(), t);
            *iter = t;
        }
    }
    cout << cnt << endl;
    return 0;
}
