#include <unordered_map>

std::unordered_map<unsigned long long, int> dp;
int solve(int n, int cnt) {
    auto key = (((unsigned long long)n) << 32) | ((unsigned long long)cnt);
    if (dp.count(key)) return dp[key];
    int &ret = dp[key];
    if (n==3) return ret = (cnt==2);
    if (n<3) return 0;
    if (n%3==0) {
        if (cnt<30) ret = solve(n-3, cnt+3);
        if (cnt>=2) ret += solve(n/3, cnt-2);
    }
    else {
        ret = solve(n-n%3, cnt+n%3);
    }
    return ret;
}

int solution(int n) {
    return solve(n, 0);
}