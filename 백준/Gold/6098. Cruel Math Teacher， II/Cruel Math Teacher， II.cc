#include <iostream>
#include <cmath>
#define diff 1e-4
using namespace std;
typedef long double lf;
lf f(int d, lf *arr, lf x);
int main(){
    int d;
    cin >> d;
    lf *arr = new lf[d + 1];
    for(int i = 0; i <= d; i++)
        cin >> arr[i];
    lf m = -1000000, M = 1000000;
    lf mid = (m + M) / 2;
    while(abs(f(d, arr, mid)) > diff){
        if(f(d, arr, mid) * arr[d] > 0){
            M = mid;
        }
        else m = mid;
        mid = (m + M) / 2;
    }

    cout << (int)(mid * 1000) << endl;
}
lf f(int d, lf *arr, lf x){
    lf res = 0;
    for(int i = 0; i <= d; i++){
        res += arr[i] * pow(x, i);
    }
    return res;
}
