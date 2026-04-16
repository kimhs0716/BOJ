#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n){
        int res = 1;
        for(int i = 0; i < n; i++){
            int a, b;
            cin >> a >> b;
            res *= a;
            res -= b;
        }
        cout << res << endl;
        cin >> n;
    }
    return 0;
}
