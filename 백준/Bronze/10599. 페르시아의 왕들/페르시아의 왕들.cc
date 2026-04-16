#include <iostream>
using namespace std;
int main(){
    while(1){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(a == b && b == c && c == d && a == 0) break;
        cout << c - b << " " << d - a << endl;
    }
    return 0;
}
