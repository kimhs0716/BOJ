#include <iostream>
using namespace std;
typedef long long lld;
int main(){
    int t;
    cin >> t;
    while(t--){
        lld n;
        cin >> n;
        if(n % 3 == 2 || n % 9 == 0)
            cout << "TAK\n";
        else cout << "NIE\n";
    }
    return 0;
}