#include <iostream>
using namespace std;
int main(){
    int S = 0;
    char ch;
    int h, w; cin >> h >> w;
    for(int i = 0; i < h; i++){
        bool cnt = 0;
        for(int j = 0; j < w; j++){
            cin >> ch;
            if(ch == '/' || ch == '\\'){
                S++;
                cnt ^= 1;
            }
            else{
                if(cnt) S += 2;
            }
        }
    }
    cout << S / 2 << endl;
    return 0;
}
