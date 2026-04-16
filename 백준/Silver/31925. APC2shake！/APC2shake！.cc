#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

typedef struct {
	string name;
	int rank;
} p;

bool cmp(const p& p1, const p& p2) {
	return p1.rank < p2.rank;
}

int main() {
    FASTIO;
	
	vector<p> arr;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string name, jaehak, icpc;
		int sh, rank;
		cin >> name >> jaehak >> icpc >> sh >> rank;
		if (jaehak == "jaehak" && icpc == "notyet" && (sh >= 4 || sh == -1))
			arr.push_back({ name, rank });
	}
	sort(arr.begin(), arr.end(), cmp);

	vector<string> ans;
	for (int i = 0; i < min<int>(static_cast<int>(arr.size()), 10); i++) {
		ans.push_back(arr[i].name);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (auto name : ans) cout << name << endl;

	return 0;
}