#include <iostream>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;
typedef long long int lld;
int main(){
    FASTIO;
    int n, k, m; cin >> n >> k >> m;
    int sa[31][k + 1];
    int x[n + 1];
    for(int i = 1; i <= n; i++) cin >> x[i];
    for(int i = 1; i <= k; i++) cin >> sa[0][i];
    for(int i = 1; i < 31; i++){
        for(int j = 1; j <= k; j++){
            sa[i][j] = sa[i - 1][sa[i - 1][j]];
        }
    }
    int j = 0;
    m--;
    while(m){
        if(m & 1){
            for(int i = 1; i <= n; i++){
                x[i] = sa[j][x[i]];
            }
        }
        m >>= 1;
        j++;
    }
    for(int i = 1; i <= n; i++) cout << x[i] << ' ';
    return 0;
}
