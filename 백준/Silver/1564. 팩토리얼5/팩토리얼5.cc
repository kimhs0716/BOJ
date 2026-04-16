#include <iostream>
typedef unsigned long long int ulld;
using namespace std;
int main(){
    int n;
    cin >> n;
    ulld res = 1;
    for(int i = 1; i <= n; i++){
        res *= i;
        while(res % 10 == 0) res /= 10;
        res %= 1000000000000;
    }
    res %= 100000;
    printf("%05lld\n", res);
    return 0;
}
