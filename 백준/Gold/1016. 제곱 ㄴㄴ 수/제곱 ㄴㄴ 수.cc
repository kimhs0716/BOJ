#include <iostream>
#include <vector>
using namespace std;
typedef long long int lld;
bool isprime(lld n){
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    lld i = 3;
    while(i * i <= n){
        if(n % i == 0) return false;
        i += 2;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    lld m, M;
    cin >> m >> M;

    lld a = M - m + 1;

    vector<bool> arr(a, false);
    lld i = 2;

    while(i * i <= M){
        lld n = m / (i * i);
        if(m % (i * i) ) n++;
        while(n * i * i <= M){
            if(!arr[n * i * i - m]){
                arr[n * i * i - m] = true;
                a--;
            }
            n++;
        }
        i++;
    }

    cout << a << endl;

    return 0;
}
