#include <iostream>
using namespace std;
int main(){
    int five = 0;
    int n;
    cin >> n;
    int i = 5, k = 1;
    while(i <= n){
        five += (n / i);
        k++;
        i *= 5;
    }
    cout << five << endl;
    return 0;
}
