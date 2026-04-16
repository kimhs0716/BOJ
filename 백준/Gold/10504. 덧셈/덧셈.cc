#include <iostream>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(n & 1){
            if(n == 1) cout << "IMPOSSIBLE\n";
            else cout << n << " = " << n / 2 << " + " << n / 2 + 1 << endl;
            continue;
        }
        bool found = 0;
        int i = 3;
        while(true){
            if(i & 1){
                if(n / i - i / 2 <= 0) break;
                if(n % i == 0){
                    found = 1;
                    break;
                }
                i++;
            }
            else{
                if(n / i - i / 2 <= -1) break;
                if(2 * n % i == 0 && n % i){
                    found = 1;
                    break;
                }
                i++;
            }
        }
        if(found == 0) cout << "IMPOSSIBLE\n";
        else{
            cout << n << " = ";
            if(i & 1) for(int j = 0; j < i - 1; j++) cout << n / i - i / 2 + j << " + ";
            else for(int j = 0; j < i - 1; j++) cout << n / i - i / 2 + j + 1 << " + ";
            cout << n / i + i / 2 << endl;
        }
    }
    return 0;
}
