#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    int mi = -1;
    int i = 0, s = 0;
    while(i * i < n) i++;
    while(i * i <= m) {
        if(mi == -1) mi = i * i;
        s += i * i;
        i++;
    }
    if(mi != -1)cout << s << endl << mi << endl;
    else cout << "-1\n";
    return 0;
}