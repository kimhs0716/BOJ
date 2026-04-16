#include <iostream>
using namespace std;
int tri(int);
int main(){
    int t;
    cin >> t;
    while(t--){
        int res = 0, n;
        cin >> n;
        while(n--){
            res += (n + 1) * tri(n + 2);
        }
        cout << res << endl;
    }
    return 0;
}
int tri(int n){
    return n * (n + 1) / 2;
}
