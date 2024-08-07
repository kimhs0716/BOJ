#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

using namespace std;

using vi = vector<int>;
using si = set<int>;
using card = struct card {
	int id;
	string type;
	int n;
};

int main() {
	FASTIO;

	int n, t; cin >> n >> t;
	
	vi turn(t); 
	for (int i = 0; i < t; i++) cin >> turn[i];

	vector<card> deck(t);
	for (int i = 0; i < t; i++) {
		cin >> deck[i].id >> deck[i].type;
		if (deck[i].type == "next") continue;
		cin >> deck[i].n;
	}
	reverse(deck.begin(), deck.end());

	vector<card> players(n);
	vector<si> places(n);
	si occupied;

	for (int i = 0; i < t; i++) {
		int p = turn[i] - 1;
		if (players[p].id == 0) {
			players[p] = deck.back();
			deck.pop_back();
		}
		card& c = players[p];
		cout << c.id << endl;
		if (c.type == "next") {
			c = card();
			continue;
		}
		else if (c.type == "acquire") {
			if (occupied.find(c.n) == occupied.end()) {
				places[p].insert(c.n);
				occupied.insert(c.n);
				c = card();
			}
		}
		else {
			occupied.erase(c.n);
			places[p].erase(c.n);
			c = card();
		}
	}

	return 0;
}
