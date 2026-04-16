#include <iostream>
using namespace std;
int main(){
    int a, b, c;
    char o1, o2;
    cin >> a >> o1 >> b >> o2 >> c;
    int n1, n2, res1, res2;
    if(o1 == '+') n1 = a + b;
    else if(o1 == '-') n1 = a - b;
    else if(o1 == '*') n1 = a * b;
    else n1 = a / b;
    if(o2 == '+') res1 = n1 + c;
    else if(o2 == '-') res1 = n1 - c;
    else if(o2 == '*') res1 = n1 * c;
    else res1 = n1 / c;

    if(o2 == '+') n2 = b + c;
    else if(o2 == '-') n2 = b - c;
    else if(o2 == '*') n2 = b * c;
    else n2 = b / c;
    if(o1 == '+') res2 = a + n2;
    else if(o1 == '-') res2 = a - n2;
    else if(o1 == '*') res2 = a * n2;
    else res2 = a / n2;
    cout << min(res1, res2) << endl << max(res1, res2) << endl;
    return 0;
}
