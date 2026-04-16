#include <iostream>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    int i = 0;
    int cnt = 0;
    while(i < n * m){
        i += n;
        if(i % m == 0) cnt--;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
