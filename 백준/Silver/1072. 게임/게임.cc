#include <iostream>
#include <climits>
using namespace std;
typedef long long int lld;
int sr(lld g, lld w);
int main(){
    int x, y;
    cin >> x >> y;
    if(x == y){
        cout << -1 << endl;
        return 0;
    }
    //cout << sr(x, y) << endl;
    lld m = 0;
    lld M = INT_MAX;
    lld mid = (m + M) / 2;
    int first = sr(x, y);
    if(first == 99){
        cout << -1 << endl;
        return 0;
    }
    while(true){
        //printf("%lld %lld %lld\n", m, mid, M);
        if(sr(x + mid, y + mid) == first && sr(x + mid + 1, y + mid + 1) > first) break;
        if(sr(x + mid, y + mid) > first) M = mid;
        else m = mid;
        mid = (m + M) / 2;
    }
    cout << mid + 1 << endl;
	return 0;
}
int sr(lld g, lld w){
    return 100 * w / g;
}
