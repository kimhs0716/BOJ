#include <iostream>
#define endl '\n'
#define diff 1e-5
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    double x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    double S = 0.5 * ((x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3));
    if(abs(S) < diff) cout << 0;
    else if(S < 0) cout << -1;
    else cout << 1;
    cout << endl;
    return 0;
}
