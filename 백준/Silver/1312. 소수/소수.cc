#include <iostream>
#define endl '\n'
using namespace std;
int main() {
    int a, b, n; cin >> a >> b >> n;
    a %= b;
    while(--n) {
        a *= 10;
        //cout << a / b;
        a %= b;
    }
    cout << (a * 10) / b << endl;
    return 0;
}
