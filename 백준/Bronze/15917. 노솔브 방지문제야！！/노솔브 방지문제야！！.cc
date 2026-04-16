#include <iostream>
using namespace std;
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        if((n & (-n)) == n) printf("1\n");
        else printf("0\n");
    }
    return 0;
}
