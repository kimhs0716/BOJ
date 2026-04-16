#include <iostream>
using namespace std;
typedef long long int lld;
int main(){
    lld n;
    cin >> n;
    lld c, k;
    lld s = 0;
    while(n--){
        scanf("%lld %lld", &c, &k);
        if(k == 0) continue;
        s += k * c;
    }
    cout << s << endl;
    return 0;
}
