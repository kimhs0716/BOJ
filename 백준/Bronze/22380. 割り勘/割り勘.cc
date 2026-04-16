#include <iostream>
using namespace std;
int main(){
    int a, b;
    while(true){
        cin >> a >> b;
        if(a == b && b == 0) break;
        int warikan = 0;
        int warimae = b / a;
        for(int i = 0; i < a; i++){
            int okane;
            cin >> okane;
            warikan += min(okane, warimae);
        }
        cout << warikan << endl;
    }
    return 0;
}
