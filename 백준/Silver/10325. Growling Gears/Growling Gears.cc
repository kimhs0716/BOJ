#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int max_idx = 1;
        double max_torque = 0;
        for(int i = 1; i <= n; i++){
            int a, b, c;
            cin >> a >> b >> c;
            double torque = c + (double)b * b / 4 / a;
            if(torque > max_torque){
                max_idx = i;
                max_torque = torque;
            }
        }
        cout << max_idx << endl;
    }
    return 0;
}
