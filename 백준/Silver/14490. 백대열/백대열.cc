#include <iostream>
#include <numeric>
using namespace std;
int main(){
    int a, b;
    char c;
    cin >> a >> c >> b;
    cout << a / gcd(a, b) << c << b / gcd(a, b) << endl;
    return 0;
}