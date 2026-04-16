#include <iostream>
#include <cmath>
#include <string>
using namespace std;
bool isprime(int);
int main(){
    string str;
    int sum = 0;
    cin >> str;
    for(int i = 0; i < str.length(); i++){
        if(str[i] > 'Z') sum += str[i] - 'a' + 1;
        else sum += str[i] - 'A' + 27;
    }
    //cout << sum << endl;
    cout << "It is ";
    if(!isprime(sum)) cout << "not ";
    cout << "a prime word." << endl;
    return 0;
}
bool isprime(int n){
    if(n == 1) return true;
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    double loop = sqrt(n);
    for(int i = 3; i <= loop + 2; i += 2){
        if(n % i == 0) return false;
    }
    return true;
}
