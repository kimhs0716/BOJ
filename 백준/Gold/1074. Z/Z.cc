#include <iostream>
typedef long long int lld;
using namespace std;
lld pow(int a, int b);
int dfs(int r, int c, lld s);
int main(){
    int n, r, c;
    cin >> n >> r >> c;
    cout << dfs(r, c, pow(2, n)) << endl;
    return 0;
}
int dfs(int r, int c, lld s){
    if(s == 1) return 0;
    if(r < s / 2 && c < s / 2) return dfs(r, c, s / 2);
    if(r < s / 2 && c >= s / 2) return s * s / 4 + dfs(r, c - s / 2, s / 2);
    if(r >= s / 2 && c < s / 2) return s * s / 2 + dfs(r - s / 2, c, s / 2);
    if(r >= s / 2 && c >= s / 2) return 3 * s * s / 4 + dfs(r - s / 2, c - s / 2, s / 2);
}
lld pow(int a, int b){
    lld res = 1;
    while(b--) res *= a;
    return res;
}
