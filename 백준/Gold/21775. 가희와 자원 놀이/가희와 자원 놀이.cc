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
	card() {
		id = -1;
		type = "";
		n = -1;
	};
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
		if (players[p].id == -1) {
			players[p] = deck.back();
			deck.pop_back();
		}
		cout << players[p].id << endl;
		if (players[p].type == "next") {
			players[p] = card();
			continue;
		}
		else if (players[p].type == "acquire") {
			if (occupied.find(players[p].n) == occupied.end()) {
				places[p].insert(players[p].n);
				occupied.insert(players[p].n);
				players[p] = card();
			}
		}
		else {
			occupied.erase(players[p].n);
			places[p].erase(players[p].n);
			players[p] = card();
		}
	}

	return 0;
}
