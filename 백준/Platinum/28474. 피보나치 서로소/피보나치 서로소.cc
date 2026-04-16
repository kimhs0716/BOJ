#include <iostream>
#include <ctime>
#include <vector>
#include <map>
using namespace std;
typedef __int128 lld;

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
                31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
                73, 79, 83, 89, 97, 101, 103, 107, 109, 113};

lld g(lld x, int c, lld num);
lld gcd(lld a, lld b);
bool __isprime(lld num);
vector<lld> pollard_rho(lld num);
lld __pow(int a, lld n, lld mod);
lld __pow(int a, lld n);
lld __pow(lld a, lld n);
lld __abs(lld num);
lld euler_phi(lld num);

int main(){
    srand((unsigned)time(nullptr));
    int t; cin >> t;
    while(t--) {
        long long int n;
        cin >> n;

        cout << (long long int)euler_phi((lld)n) + ((n % 2) ? 0 : (long long int)euler_phi((lld)n / 2)) << endl;
    }

    return 0;
}

lld euler_phi(lld num){
    if(num == 1) return 0;
    if(__isprime(num)) return num - 1;
    vector<lld> divs = pollard_rho(num);
    map<lld, int> m1;
    for(auto iter = divs.begin(); iter < divs.end(); iter++){
        if(m1.find(*iter) == m1.end()) m1.insert({*iter, 1});
        else m1[*iter]++;
    }
    lld res = 1;
    for(const auto &item: m1){
        res *= __pow(item.first, item.second - 1) * (item.first - 1);
    }
    return res;
}

lld g(lld x, int c, lld num){
    return (x * x + c) % num;
}

lld gcd(lld a, lld b){
    while(b != 0){
        lld r = a % b;
        a = b;
        b = r;
    }
    return a;
}

bool __isprime(lld num){
    if(num == 1) return false;
    lld d = num - 1;
    int s = 0;
    while(d % 2 == 0){
        d >>= 1;
        s++;
    }
    for(int idx = 0; idx < 30; idx++){
        int a = primes[idx];
        if(a >= num) break;
        bool passed = false;
        if(__pow(a, d, num) == 1){
            passed = true;
            continue;
        }
        for(lld r = 0; r < s; r++){
            if(__pow(a, __pow(2, r) * d, num) == num - 1){
                passed = true;
                break;
            }
        }
        if(passed == false) return false;
    }
    return true;
}

vector<lld> pollard_rho(lld num){
    if(__isprime(num)){
        vector<lld> res(1, num);
        return res;
    }
    if(num == 4){
        vector<lld> res(2, 2);
        return res;
    }
    while(true){
        int c = rand() % 9 + 1;
        lld x = rand() % 9 + 1;
        lld y = x;
        lld d = 1;
        while(d == 1){
            x = g(x, c, num);
            y = g(g(y, c, num), c , num);
            d = gcd(__abs(x - y), num);
        }
        if(d == num) continue;
        vector<lld> v1, v2;
        v1 = pollard_rho(num / d);
        v2 = pollard_rho(d);
        v1.insert(v1.end(), v2.begin(), v2.end());
        return v1;
    }

}

lld __pow(int a, lld n, lld mod){
    if(n == 0) return 1;
    lld res = __pow(a, n / 2, mod);
    res = res * res % mod;
    if(n & 1) res = res * a % mod;
    return res;
}

lld __pow(int a, lld n){
    if(n == 0) return 1;
    lld res = __pow(a, n / 2);
    res *= res;
    if(n & 1) res *= a;
    return res;
}

lld __pow(lld a, lld n){
    if(n == 0) return 1;
    lld res = __pow(a, n / 2);
    res *= res;
    if(n & 1) res *= a;
    return res;
}


lld __abs(lld num){
    return (num < 0) ? -num : num;
}
