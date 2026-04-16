#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <string>
#include <map>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long int lld;
int main(){
    FASTIO;
    int d, m; cin >> d >> m;
    lld l = 1, g = 1;
    while(d--){
        int a; cin >> a;
        l = lcm(l, a);
    }
    m--;
    cin >> g;
    while(m--){
        int a; cin >> a;
        g = gcd(g, a);
    }
    //cout << l << ' ' << g << endl;
    if(g % l) cout << 0 << endl;
    else{
        g /= l;
        int cnt = 0;
        for(int i = 1; i * i <= g; i++){
            if(g % i == 0) cnt += 2;
            if(i * i == g) cnt -= 1;
        }
        cout << cnt << endl;
    }
    return 0;
}
