#include <iostream>
#define mod 1000000007
using namespace std;
int cache[51];
int main(){
    cache[0] = cache[1] = 1;
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++){
        cache[i] = (cache[i - 1] + cache[i - 2] + 1) % mod;
    }
    cout << cache[n] << endl;
    return 0;
}
