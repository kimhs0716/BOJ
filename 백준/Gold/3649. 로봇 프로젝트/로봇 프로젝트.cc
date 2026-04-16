#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#define endl '\n'
using namespace std;
typedef long long int lld;
int compare(lld a, lld b){
    if(a < b) return -1;
    return 1;
}
int main(){
    int x;
    while(scanf("%d", &x) != EOF){
        x *= 10000000;
        int n;
        scanf("%d", &n);
        vector<int> v(n);
        for(int i = 0; i < n; i++) scanf("%int", &v[i]);
        sort(v.begin(), v.end());

        bool found = 0;
        int b1, b2;
        for(int i = 0; i < n; i++){
            if(binary_search(v.begin(), v.end(), x - v[i]) == false) continue;
            auto iter = lower_bound(v.begin(), v.end(), x - v[i]);
            //cout << v[i] << " " << *iter << endl;
            if(v[i] == *iter && count(v.begin(), v.end(), v[i]) == 1) continue;
            found = 1;
            b1 = v[i], b2 = *iter;
            break;
        }

        if(found) printf("yes %d %d\n", b1, b2);
        else printf("danger\n");
    }

    return 0;
}
