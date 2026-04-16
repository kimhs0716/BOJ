#include <iostream>
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << fixed, cout.precision(1);
    int n; cin >> n;
    double x1, x, y1, y;
    double prev_x, prev_y;
    cin >> x1 >> y1;
    prev_x = x1, prev_y = y1;
    double s = 0;
    for(int i = 1; i < n; i++){
        cin >> x >> y;
        s += 0.5 * (prev_x * y - prev_y * x);
        prev_x = x, prev_y = y;
    }
    s += 0.5 * (prev_x * y1 - prev_y * x1);
    cout << abs(s) << endl;
    return 0;
}
