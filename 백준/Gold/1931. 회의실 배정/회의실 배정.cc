#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct {
    int start;
    int end;
} time;
bool cmp(time a, time b);
int main(){
	int n;
	cin >> n;
	vector<time> t(n);
	for(int i = 0; i < n; i++){
        cin >> t[i].start >> t[i].end;
	}
	sort(t.begin(), t.end(), cmp);
	int cnt = 0, m = 0;
	for(int i = 0; i < n; i++){
        if(m <= t[i].start){
            m = t[i].end;
            cnt++;
        }
	}
	cout << cnt << endl;
	return 0;
}
bool cmp(time a, time b){
    if(a.end == b.end) return a.start < b.start;
    return a.end < b.end;
}
