#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;
int main(){
    FASTIO;
    while(1){
        int n, m; cin >> n >> m;
        if(n == 0) break;
        vector<int> v1, v2;
        while(n--) { int a; cin >> a; v1.push_back(a); }
        while(m--) { int a; cin >> a; v2.push_back(a); }
        int cnt = 0;
        auto i = v1.begin(), j = v2.begin();
        while(i != v1.end() && j != v2.end()){
            if(*i == *j) cnt++;
            if(*i < *j) i++;
            else j++;
        }
        cout << cnt << endl;
    }
    return 0;
}
