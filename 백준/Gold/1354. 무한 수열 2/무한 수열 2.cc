#include <iostream>
#include <map>
using namespace std;
typedef long long int lld;
map<lld, lld> m;
int p, q, x, y;
lld dp(lld n){
    if(n <= 0) return 1;
    if(m[n] == 0){
        m[n] = (n / p - x > 0) ? dp(n / p - x) : 1;
        m[n] += (n / q - y > 0) ? dp(n / q - y) : 1;
    }
    return m[n];
}
int main(){
   lld n;
   cin >> n;
   cin >> p >> q >> x >> y;
   m[0] = 1;
   cout << dp(n) <<endl;
   return 0;
}
