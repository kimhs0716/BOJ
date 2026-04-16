#include <iostream>
typedef long long int lld;
using namespace std;
int boss[100001];
lld praise[100001];
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin >> n >> m;
    int b; cin >> b;
    for(int i = 2; i <= n; i++) cin >> boss[i];
    for(int i = 0; i < m; i++) {
        int shain, home; cin >> shain >> home;
        praise[shain] += home;
    }
    for(int i = 1; i <= n; i++){
        praise[i] += praise[boss[i]];
        cout << praise[i] << " ";
    }
    return 0;
}
