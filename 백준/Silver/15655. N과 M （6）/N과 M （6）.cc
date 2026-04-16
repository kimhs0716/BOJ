#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long int lld;
int m;
void solve(vector<int> &candidate, vector<int> &sellected, int last);
int main(){
    //FASTIO;
    int n; cin >> n >> m;
    bool input[10001] = {0, };
    for(int i = 0; i < n; i++){
        int t; cin >> t;
        input[t] = 1;
    }
    vector<int> cand;
    for(int i = 1; i <= 10000; i++){
        if(input[i]) cand.push_back(i);
    }
    vector<int> sellected;
    solve(cand, sellected, -1);
    return 0;
}
void solve(vector<int> &candidate, vector<int> &sellected, int last){
    if(sellected.size() == m){
        for(auto i: sellected) cout << i << ' ';
        cout << endl;
        return;
    }
    for(int i = last + 1; i < candidate.size(); i++){
        sellected.push_back(candidate[i]);
        solve(candidate, sellected, i);
        sellected.pop_back();
    }
    return;
}
