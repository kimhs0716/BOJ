#include <iostream>

using namespace std;

int main(){
    long long N, res = 1;
    cin >> N;
    N--;
     do{
        res = (res * N) % 1000000007LL;
        N -= 2;
    } while (N > 1);

     cout << res;
    return 0;
}