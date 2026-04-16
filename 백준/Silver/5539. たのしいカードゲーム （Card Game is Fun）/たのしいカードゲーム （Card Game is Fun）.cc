#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>
#include <map>
#define endl '\n'
using namespace std;
int find(vector<int>::iterator begin, vector<int>::iterator end, int target, int start) {
    auto iter = begin + start;
    int ret = 0;
    while (iter < end) {
        if(*iter == target) return ret + start;
        ret++, iter++;
    }
    return -1;
}
int main(){
    int na, nb; cin >> na >> nb;
    vector<int> a(na), b(nb);
    for(int i = 0; i < na; i++) cin >> a[i];
    for(int i = 0; i < nb; i++) cin >> b[i];
    int M = 0;
    for(int i = 0; i < nb; i++) {
        int cur = 0, idx = -1;
        for(int j = i; j < nb; j++){
            if((idx = find(a.begin(), a.end(), b[j], idx + 1)) == -1){
                break;
            }
            cur++;
        }
        M = max<int>(M, cur);
    }
    cout << M << endl;

    return 0;
}
