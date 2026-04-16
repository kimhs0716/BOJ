#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;
typedef long long int lld;
int main(){
    int a1, a0; cin >> a1 >> a0;
    int c, n0; cin >> c >> n0;
    if(a1 <= c) cout << ((a1 - c) * n0 + a0 <= 0) << endl;
    else cout << "0\n";
    return 0;
}
