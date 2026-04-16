#include <iostream>
#include <climits>
using namespace std;
typedef long long int lld;
int arr[1000000];
int n;
lld cut(int h);
int main(){
    int m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int mi = 0;
    int ma = INT_MAX;
    int mid = (mi + ma) / 2;
    while(true){
        //printf("%d %d %d %d\n", mi, mid, ma, cut(mid));
        if(mid == mi || mid == ma){
            cout << mid << endl;
            break;
        }
        //if(cut(mid) < m && cut(mid + 1) >= m) break;
        if(cut(mid) < m) ma = mid;
        else mi = mid;
        mid = (mi + ma) / 2;
    }
	return 0;
}
lld cut(int h){
    lld sum = 0;
    for(int i = 0; i < n; i++){
        sum += (arr[i] - h > 0) ? arr[i] - h : 0;
    }
    return sum;
}
