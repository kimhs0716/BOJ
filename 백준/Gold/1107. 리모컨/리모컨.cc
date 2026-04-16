#include <iostream>
#define MAX 1000000
using namespace std;
int available[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
int btncnt(int n);
int main(){
    int n, broken;
    cin >> n >> broken;
    for(int i = 0; i < broken; i++){
        int num;
        cin >> num;
        available[num] = 0;
    }
    int m = abs(n - 100);
    for(int i = 0; i < MAX; i++){
        if(btncnt(i)){
            m = min(m, abs(i - n) + btncnt(i));
        }
    }
    cout << m << endl;
    return 0;
}
int btncnt(int n){
    if(n == 0) return available[0];
    int len = 0;
    while(n){
        if(available[n % 10] == 0) return 0;
        n /= 10;
        len++;
    }
    return len;
}
