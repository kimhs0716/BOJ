#include <iostream>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;
typedef long long int lld;
int main(){
    FASTIO;
    lld n; cin >> n;
    lld result = 1;
    while(result <= n) result <<= 1;
    result--;
    if(n == result){
        cout << "1\n" << n << endl;
        return 0;
    }
    cout << "2\n" << (result ^ n) << endl << n << endl;
    return 0;
}
