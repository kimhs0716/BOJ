#include <iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int res = 0, n, a, b, c, m;
        cin >> n;
        while(n--){
            cin >> a >> b >> c;
            m = max(a, max(b, c));
            res += m * (m > 0);
        }
        cout << res << endl;
    }
    return 0;
}
