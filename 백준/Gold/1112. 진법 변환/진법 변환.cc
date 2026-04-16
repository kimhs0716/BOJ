#include <iostream>
#define endl '\n'
using namespace std;
typedef long long int lld;
int sign(lld n){
    return n < 0 ? -1 : n ? 1 : 0;
}
void trans(lld x, int b){
    if(x == 0) return;
    lld q = x / b;
    int m = x % b;
    if(m < 0){
        q += 1;
        m += sign(b) * b;
    }
    trans(q, b);
    cout << m;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    lld x; int b; cin >> x >> b;
    if(x == 0){
        cout << "0\n";
        return 0;
    }
    if(x < 0 && b > 0) cout << "-", trans(-x, b);
    else trans(x, b);
    cout << endl;
    return 0;
}
