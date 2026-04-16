#include <iostream>
#define endl '\n'

using namespace std;

int main(){
    int X, n; cin >> X >> n;
    while(n--){
        int p, q; cin >> p >> q;
        X -=  p * q;
    }
    cout << (X ? "No" : "Yes") << endl;
    return 0;
}