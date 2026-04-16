#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> tok;
vector<string> numstr;

// simulate k=0 (no rules): only numeric
int match0() {
    for (int i = 1; i <= n; i++) {
        if (tok[i] != numstr[i])
            return i - 1;
    }
    return n;
}

// simulate k=1 with rule (d1 -> s1)
int match1(int d1) {
    string s1;
    bool has1 = false;
    for (int i = 1; i <= n; i++) {
        if (i % d1 == 0) {
            if (!has1) {
                if (tok[i].size() != 4) return i - 1;
                for (char c : tok[i])
                    if (c < 'a' || c > 'z') return i - 1;
                s1 = tok[i];
                has1 = true;
            } else {
                if (tok[i] != s1) return i - 1;
            }
        } else {
            if (tok[i] != numstr[i]) return i - 1;
        }
    }
    return n;
}

// simulate k=2 with rules (d1 -> s1) and (d2 -> s2), d1<d2
int match2(int d1, int d2) {
    string s1, s2;
    bool has1 = false, has2 = false;
    for (int i = 1; i <= n; i++) {
        bool m1 = (i % d1 == 0);
        bool m2 = (i % d2 == 0);
        if (m1 && m2) {
            // both rules apply
            if (has1 && has2) {
                if (tok[i] != s1 + s2) return i - 1;
            } else if (has1 && !has2) {
                // derive s2 from concat
                if (tok[i].size() != 8) return i - 1;
                if (tok[i].substr(0,4) != s1) return i - 1;
                s2 = tok[i].substr(4,4);
                has2 = true;
            } else if (!has1 && has2) {
                // derive s1 from concat
                if (tok[i].size() != 8) return i - 1;
                if (tok[i].substr(4,4) != s2) return i - 1;
                s1 = tok[i].substr(0,4);
                has1 = true;
            } else {
                // derive both from first concat
                if (tok[i].size() != 8) return i - 1;
                s1 = tok[i].substr(0,4);
                s2 = tok[i].substr(4,4);
                has1 = has2 = true;
            }
        } else if (m1) {
            // only rule1
            if (!has1) {
                if (tok[i].size() != 4) return i - 1;
                for (char c : tok[i])
                    if (c < 'a' || c > 'z') return i - 1;
                s1 = tok[i];
                has1 = true;
            } else {
                if (tok[i] != s1) return i - 1;
            }
        } else if (m2) {
            // only rule2
            if (!has2) {
                if (tok[i].size() != 4) return i - 1;
                for (char c : tok[i])
                    if (c < 'a' || c > 'z') return i - 1;
                s2 = tok[i];
                has2 = true;
            } else {
                if (tok[i] != s2) return i - 1;
            }
        } else {
            // no rule
            if (tok[i] != numstr[i]) return i - 1;
        }
    }
    return n;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--) {
        cin >> n;
        tok.assign(n+1, "");
        for (int i = 1; i <= n; i++) {
            cin >> tok[i];
        }
        // precompute numeric strings
        numstr.assign(n+1, "");
        for (int i = 1; i <= n; i++) {
            numstr[i] = to_string(i);
        }

        // k = 0
        int ans = match0();
        if (ans == n) {
            cout << ans << "\n";
            continue;
        }

        // k = 1
        for (int d1 = 1; d1 <= n; d1++) {
            if (tok[d1].size() == 4) {
                bool ok = true;
                for (char c : tok[d1]) {
                    if (c < 'a' || c > 'z') {
                        ok = false;
                        break;
                    }
                }
                if (!ok) continue;
                ans = max(ans, match1(d1));
                if (ans == n) break;
            }
        }
        if (ans == n) {
            cout << ans << "\n";
            continue;
        }

        // k = 2
        // prune by only trying d1 up to ans+1
        for (int d1 = 1; d1 <= n; d1++) {
            if (d1 > ans + 1) break;
            if (tok[d1].size() != 4) continue;
            bool ok = true;
            for (char c : tok[d1]) {
                if (c < 'a' || c > 'z') {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;
            for (int d2 = d1 + 1; d2 <= n; d2++) {
                ans = max(ans, match2(d1, d2));
                if (ans == n) break;
            }
            if (ans == n) break;
        }

        cout << ans << "\n";
    }

    return 0;
}
