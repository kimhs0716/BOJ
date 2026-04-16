#include <iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        scanf("%d %d", &a, &b);
        while(a != b){
            if(a > b) a /= 2;
            else b /= 2;
        }
        printf("%d\n", 10 * a);
    }
    return 0;
}
