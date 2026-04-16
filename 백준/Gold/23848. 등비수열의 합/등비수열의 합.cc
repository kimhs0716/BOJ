#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main(){
    long long int N;
    cin >> N;
    vector<long long int> divs;
    long long int K, a, r;
    for(long long int i = 1; i * i <= N; i++){
        if(N % i) continue;
        divs.push_back(i);
        divs.push_back(N / i);
    }
    for(int idx = 0; idx < divs.size(); idx++){
        a = divs[idx];
        //printf("idx: %d a: %lld\n", idx, a);
        N /= a;
        for(r = 2; 1 + r * (1 + r) <= N + 1; r++){
            long long int s = 0, c = 1, n;
            for(n = 0; s < N; n++){
                s += c;
                c *= r;
            }
            //printf("n: %lld, s: %lld, c: %lld, r: %d\n", n, s, c, r);
            if(s == N){
                cout << n << endl;
                c = a;
                for(int i = 0; i < n; i++){
                    cout << c << " ";
                    c *= r;
                }
                return 0;
            }
        }
        N *= a;
    }
    cout << "-1\n";
    return 0;
}
