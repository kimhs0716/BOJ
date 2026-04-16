#include <iostream>
using namespace std;
int main(){
    int e, s, m;
    cin >> e >> s >> m;
    int E, S, M;
    E = S = M = 1;
    int year = 1;
    while(e != E || s != S || m != M){
        year++;
        E++;
        S++;
        M++;
        if(E == 16) E = 1;
        if(S == 29) S = 1;
        if(M == 20) M = 1;
    }
    cout << year << endl;
    return 0;
}
