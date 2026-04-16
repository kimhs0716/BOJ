#include <iostream>
#include <cstring>
using namespace std;
bool isprime[1000001];
int main(){
    memset(isprime, 1, 1000000);
    int i = 0;
    while(i * i <= 1000000) {
        //cout << "[#DEBUG] " << i << endl;
        i += 2;
        if(isprime[i] == 0) continue;
        int j = 2;
        while(i * j <= 1000000) {
            isprime[i * j] = 0;
            j++;
        }
        if(i == 2) i--;
    }
    int t;
    while(true){
        scanf("%d", &t);
        if(t == 0) break;
        int i = 3;
        while(true){
            if(isprime[i] && isprime[t - i]){
                printf("%d = %d + %d\n", t, i, t - i);
                break;
            }
            i += 2;
        }
    }
    return 0;
}
