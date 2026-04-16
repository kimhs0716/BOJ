#include <iostream>
#include <map>
using namespace std;
typedef long long int lld;
map<lld, lld> m;
int p, q;
lld dp(lld n){
    if(m.find(n) == m.end() || m[n] == 0){
        m[n] = dp(n/p) + dp(n/q);
    }
    return m[n];
}
int main(){
   lld n;
   cin >> n;
   cin >> p >> q;
   m[0] = 1;
   cout << dp(n) <<endl;
   return 0;
}
