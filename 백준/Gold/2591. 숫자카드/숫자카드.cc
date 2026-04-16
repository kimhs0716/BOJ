#include <iostream>
#include <string>
#include <vector>
#define endl '\n'

using namespace std;

typedef pair<int, int> pii;

int main() {
    string s; cin >> s;
    if(s[0] == '0') cout << 0 << endl;
    else if(s.size() == 1) cout << 1 << endl;
    else {
        vector<pii> dp(s.size());
        dp[0].first = 1, dp[0].second = 0;
        dp[1].first = (s[1] != '0');
        if((s[0] - '0') * 10 + (s[1] - '0') <= 34) dp[1].second = 1;
        for(int i = 2; i < s.size(); i++) {
            if(s[i] != '0') dp[i].first = dp[i - 1].first + dp[i - 1].second;
            int t = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if(10 <= t && t <= 34) dp[i].second = dp[i - 2].first + dp[i - 2].second;
        }
        cout << dp[s.size() - 1].first + dp[s.size() - 1].second << endl;
    }
    return 0;
}