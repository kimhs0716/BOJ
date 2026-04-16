#include<bits/stdc++.h>
#include<immintrin.h>
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast,unroll-loops")
using namespace std;

#ifdef ONLINE_JUDGE
constexpr bool ndebug = true;
#else
constexpr bool ndebug = false;
#endif

void setup() {
    if(!ndebug) {
        freopen("boj.in", "r", stdin);
        freopen("boj.out", "w", stdout);
    }
    else {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
}

void preprocess() {
    // ll i, j, k;

}

alignas(32) int chk[2000][2000], tmp[8];
// alignas(32) int arr[100'000], tmp[8];
void solve(int testcase){
    int i, j, k;
    int n; cin >> n;
    vector<string> arr(n);
    for (i=0;i<n;i++) {
        cin>>arr[i];
        for (j=0;j<i;j++) {
            for (k=0;k<4;k++) {
                chk[i][j]|=(arr[i][k]==arr[j][k])<<k;
            }
        }
    }
    int ans=0;
    for (i=0;i<n;i++) {
        for (j=0;j<i;j++) {
            int pivot=chk[i][j];
            k=0;
            int r=j;
            while (r&7) --r,ans+=(chk[i][r]==pivot&chk[j][r]==pivot);
            __m256i cnt=_mm256_setzero_si256();
            while (k<r) {
                __m256i chk_i=_mm256_load_si256((__m256i*)&chk[i][k]);
                __m256i chk_j=_mm256_load_si256((__m256i*)&chk[j][k]);
                // __m256i chk_i=_mm256_load_si256((__m256i*)((chk+i)+k));
                // __m256i chk_j=_mm256_load_si256((__m256i*)((chk+j)+k));
                chk_i=_mm256_cmpeq_epi32(chk_i, _mm256_set1_epi32(pivot));
                chk_j=_mm256_cmpeq_epi32(chk_j, _mm256_set1_epi32(pivot));
                chk_i=_mm256_and_si256(chk_i, chk_j);
                cnt=_mm256_sub_epi32(cnt,chk_i);
                k+=8;
            }
            _mm256_store_si256((__m256i*)tmp, cnt);
            ans += accumulate(tmp, tmp+8, 0);
        }
    }
    cout<<ans<<'\n';
}

int main() {
    setup();
    preprocess();
    int t = 1;
    // cin >> t;
    for (int testcase = 1; testcase <= t; testcase++){
        solve(testcase);
    }
    return 0;
}