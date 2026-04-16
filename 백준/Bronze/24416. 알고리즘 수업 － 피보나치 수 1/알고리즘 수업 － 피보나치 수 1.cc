#include <iostream>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;
int cnt = 0;
void fib(int n) {
    if(n == 1 || n == 2){
        cnt++;
        return;
    }
    return fib(n - 1), fib(n - 2);
}
int main(){
    FASTIO;
    int n; cin >> n;
    fib(n);
    cout << cnt << ' ' << n - 2 << endl;
    return 0;
}
