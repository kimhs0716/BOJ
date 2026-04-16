#include <iostream>
using namespace std;
int gcd(int a, int b);
int main(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int mo = b * d;
	int ja = a * d + b * c;
	int g = gcd(mo, ja);
	cout << ja / g << " " << mo / g << endl;
	return 0;
}
int gcd(int a, int b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
