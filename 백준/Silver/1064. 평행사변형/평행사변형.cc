#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int xa{0}, ya{0}, xb{0}, yb{0}, xc{0}, yc{0};

    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    if((xa == xb && ya == yb) || (xa == xc && ya == yc) || (xb == xc && yb == yc)) {
        cout << -1.0 << endl;
        return 0;
    } else if(xa == xb) {
        if(xa == xc) {
            cout << -1.0 << endl;
            return 0;
        }
    } else if(ya == yb) {
        if(ya == yc) {
            cout << -1.0 << endl;
            return 0;
        }
    } else if((yc - ya) * (xb - xa) == (yb - ya) * (xc -xa)) {
        cout << -1.0 << endl;
        return 0;
    }

    long double ab{sqrt(pow((xb - xa), 2) + pow((yb - ya), 2))}, bc{sqrt(pow((xc - xb), 2) + pow((yc - yb), 2))}, ca{sqrt(pow((xa - xc), 2) + pow((ya - yc), 2))};

    cout << fixed;
    cout.precision(15);

    //cout << "#[DEBUG]: " << ab << ' ' << bc << ' ' << ca << endl;

    long double M = max<long double>(max<long double>(ab, bc), ca);
    long double m = min<long double>(min<long double>(ab, bc), ca);

    cout << (M - m) * 2 << endl;
    
    return 0;
}