#include <iostream>
#include <string>
#define endl '\n'
using namespace std;
bool ispal(string s){
    int len = s.length();
    for(int i = 0; i < len; i++){
        if(s[i] != s[len - i - 1]) return 0;
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while(t--){
        int k; cin >> k;
        string arr[k];
        for(int i = 0; i < k; i++) cin >> arr[i];
        bool found = 0;
        for(int i = 0; i < k; i++){
            for(int j = 0; j < k; j++){
                if(i == j) continue;
                if(ispal(arr[i] + arr[j])){
                    cout << arr[i] + arr[j] << endl;
                    found = 1;
                    break;
                }
            }
            if(found) break;
        }
        if(!found) cout << 0 << endl;
    }
}
