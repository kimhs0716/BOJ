#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long int lld;
lld solve(vector<lld> &heights, int lo, int hi);
int main(){
    FASTIO;
    int n; cin >> n;
    vector<lld> heights(n);
    for(int i = 0; i < n; i++) cin >> heights[i];
    cout << solve(heights, 0, n) << endl;
    return 0;
}
//lo는 포함, hi는 포함 X
lld solve(vector<lld> &heights, int lo, int hi){
    int mid = (lo + hi) / 2;
    //cout << lo << ':' << mid << ':' << hi << endl;
    if(lo + 1 == hi) return heights[lo];
    lld left_max = solve(heights, lo, mid);
    lld right_max = solve(heights, mid, hi);
    lld ret = max<lld>(left_max, right_max);
    lld mid_max = heights[mid];
    lld height_min = heights[mid];
    int left = mid, right = mid;
    while(left != lo || right != hi - 1){
        if(left == lo || (right != hi - 1 && (heights[left - 1] <= heights[right + 1]))){
            right++;
            height_min = min<lld>(height_min, heights[right]);
        }
        else{
            left--;
            height_min = min<lld>(height_min, heights[left]);
        }
        mid_max = max<lld>(mid_max, height_min * (right - left + 1));
    }
    //printf("lo: %d, hi: %d, hm: %lld, left: %d, right: %d, ret: %lld, mm: %lld\n", lo, hi, height_min, left, right, ret, mid_max);
    return max<lld>(ret, mid_max);
}
