#include <iostream>
#include <stdio.h>
#include <climits>
#include <cmath>
#define PI 3.14159265358979323846264338327950288419L
#define dif 1e-14
using namespace std;
int a, b, c;
long double f(long double x);
long double my_sin(long double x);
long double ldabs(long double x);
int main(){
    cout << fixed;
    cout.precision(14);
    //cout << my_sin(PI / 4) << endl;
    cin >> a >> b >> c;
    long double m = -100000;
    long double M = 100000;
    long double mid = (m + M) / 2;
    while(1){
        //cout << m << ", " << mid << ", " << M << ", " << f(mid) << endl;
        if(ldabs(f(mid) - c) < (long double)dif) break;
        if(f(mid) < c) m = mid;
        else M = mid;
        mid = (m + M) / 2;
    }
    cout << mid << endl;
    //printf("%.6lf\n", (double)(round(mid * 1000000)) / 1000000);
    return 0;
}
long double f(long double x){
    return x * a + my_sin(x) * b;
}
long double my_sin(long double x){
    while(x > PI || x < -PI){
        if(x > 0) x -= 2 * PI;
        else x += 2 * PI;
    }
    long double res = 0;
    int i = 1;
    long double xx = x;
    long double fac = 1;
    for(int k = 0; k < 100; k++){
        //cout << xx << ", " << fac << ", " << i << endl;
        res += i * xx / fac;
        xx *= x * x;
        fac *= (2 * k + 2) * (2 * k + 3);
        i *= -1;
    }
    return res;
}
long double ldabs(long double x){
    if(x < 0) return -x;
    return x;
}
