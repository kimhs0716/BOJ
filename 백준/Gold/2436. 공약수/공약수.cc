#include <iostream>
using namespace std;
typedef long long int lld;
lld gcd(lld a, lld b){
    lld r;
    while(b != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
lld lcm(lld a, lld b){
    return a * b / gcd(a, b);
}
lld int_sqrt(lld n){
    lld i = 1;
    while(i * i < n) i++;
    return i;
}
int main(){
    lld G, L; cin >> G >> L;
    lld AB = G * L;
    lld s = int_sqrt(AB);
    while(1){
        while(AB % s) s--;
        if(gcd(s, AB / s) == G && lcm(s, AB / s) == L){
            cout << s << " " << AB / s << endl;
            return 0;
        }
        s--;
    }
    return 0;
}
