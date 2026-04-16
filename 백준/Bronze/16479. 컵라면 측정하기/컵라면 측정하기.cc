#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int k, d1, d2;
    cin >> k >> d1 >> d2;
    cout << k * k - pow((d1 - d2) / 2.0, 2) << endl;
    return 0;
}
