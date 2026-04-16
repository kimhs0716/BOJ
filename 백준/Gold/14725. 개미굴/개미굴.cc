#include <iostream>
#include <map>
#include <string>

#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

typedef struct Node {
	string data;
	map<string, Node> children;

	bool has_child(string& s) {
		return children.find(s) != children.end();
	}

	void add_child(string& s) {
		children.insert({ s, Node(s) });
	}

	Node* find_child(string& s) {
		return &(children.find(s)->second);
	}

	void print(int depth = -1) {
		for (int i = 0; i < depth; i++) cout << "--";
		if (depth != -1) cout << data << endl;
		for (auto iter : children) {
			iter.second.print(depth + 1);
		}
	}

	Node(string data = "") : data(data) {}
} Node;

int main() {
	FASTIO;

	Node root;
	int t; cin >> t;

	while (t--) {
		Node* cur = &root;
		int n; cin >> n;
		while (n--) {
			root;
			string s; cin >> s;
			if (!cur->has_child(s)) {
				cur->add_child(s);
			}
			cur = cur->find_child(s);
		}
	}

	root.print();

	return 0;
}