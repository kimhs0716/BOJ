#include <iostream>
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while(t--){
        int dst; cin >> dst;
        int addh, addt, mint, addo, mino;
        addh = addt = mint = addo = mino = 0;
        addh = dst / 60;
        dst %= 60;
        if(dst > 35){
            addh++;
            mint = 6 - (dst + 5) / 10;
            dst %= 10;
            if(dst >= 5){
                mino = 10 - dst;
            }
            else{
                addo = dst;
            }
        }
        else{
            addt = (dst + 4) / 10;
            dst %= 10;
            if(dst >= 6) mino = 10 - dst;
            else addo = dst;
        }
        cout << addh << ' ' << addt << ' ' << mint << ' ' << addo << ' ' << mino << endl;
    }
    return 0;
}
