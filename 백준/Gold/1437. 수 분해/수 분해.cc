#include <iostream>
#define mod 10007

using namespace std;

int main(){
    int n, res = 1;
    cin >> n;
    if(n == 0) cout << "0\n";
    else if(n == 1) cout << "1\n";
    else if(n == 2) cout << "2\n";
    else{
        while(n > 4){
            res *= 3;
            n -= 3;
            res %= mod;
        }
        if(n != 0) res *= n;
        res %= mod;
        cout << res << endl;
    }

    return 0;
}
