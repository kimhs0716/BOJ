#include <iostream>
#include <algorithm>

using namespace std;

double distance(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main(){
    int xs, ys; cin >> xs >> ys;
    int xe, ye, dx, dy; cin >> xe >> ye >> dx >> dy;
    if (dx == 0 && dy == 0) {
        cout << xe << ' ' << ye << endl;
        return 0;
    }
    int g = abs(__gcd(dx, dy)); dx /= g, dy /= g;
    double m = distance(xs, ys, xe, ye);
    while(true) {
        //cout << m << ' ' << xe << ' ' << ye << endl;
        xe += dx, ye += dy;
        double d = distance(xs, ys, xe, ye);
        if (m < d) break;
        m = d;
    }
    cout << (xe - dx) << ' ' << (ye - dy) << endl;
    
    return 0;
    
}