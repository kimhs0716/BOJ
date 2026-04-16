#define _GLIBCXX_FILESYSTEM
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int lld;
int main(){
    string s; cin >> s;
    map<string, bool> m;
    int cnt = 0;
    for(int i = 0; i < s.length(); i++) {
        for(int j = i + 1; j <= s.length(); j++) {
            string ss = s.substr(i, j - i);
            if(m[ss] == false) {
                m[ss] = true;
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
