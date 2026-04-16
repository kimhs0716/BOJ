#include <iostream>
using namespace std;
inline int five_square(int n){ return n * n * n * n * n; }
int main() {
    int n;
    cin >> n;
    int s = 0;
    while(n){
        s += five_square(n % 10);
        n /= 10;
    }
    cout << s << endl;
    return 0;
}
