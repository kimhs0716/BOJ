#include <bits/stdc++.h>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef pair<int, int> pii;
class debugstream {
public:
	ostream& os;
	debugstream(ostream& os) :os(os) {}
	template <typename T>
	ostream& operator<<(const T& obj) {
		return os << "#[DEBUG]: " << obj;
	}
};
class Album {
public:
	unordered_map<string, Album*> child_map;
	priority_queue<string, vector<string>, greater<string>> child_min_heap; // ascending
	priority_queue<string> child_max_heap; // descending
	unordered_map<string, bool> photo_map;
	priority_queue<string, vector<string>, greater<string>> photo_min_heap; // ascending
	priority_queue<string> photo_max_heap; // descending
	Album* parent;
	pii size;
	string name;
	Album(Album* parent, string name) :name(name), parent(parent) {
		size = { 0, 0 };
	}
	pii rmalb() {
		pii result = size;
		for (auto iter = child_map.begin(); iter != child_map.end(); iter++) {
			pii temp = iter->second->rmalb();
			result.first += temp.first;
			result.second += temp.second;
		}
		delete this;
		return result;
	}
	void dir() {
		cout << "===== dir =====\n";
		cout << "name: " << name << endl;
		cout << "size: " << size.first << ' ' << size.second << endl;
		cout << "child: ";
		for (auto it = child_map.begin(); it != child_map.end(); it++) {
			cout << it->second->name << ' ';
		}
		cout << endl;
		cout << "photo: ";
		for (auto it = photo_map.begin(); it != photo_map.end(); it++) {
			cout << it->first << ' ';
		}
		cout << endl;
		cout << "===============\n";
	}
};
int main() {
	//ifstream cin("Desktop/20541.in");
	//debugstream cout(cout);
	FASTIO;
	Album* const home = new Album(nullptr, "album");
	Album* cwd = home;
	int n; cin >> n;
	while (n--) {
		string cmd, arg;
		cin >> cmd >> arg;
		if (cmd == "mkalb") {
			if (cwd->child_map.find(arg) != cwd->child_map.end()) {
				cout << "duplicated album name\n";
			}
			else {
				Album *new_album = new Album(cwd, arg);
				cwd->child_map.insert({ arg, new_album });
				cwd->child_max_heap.push(arg);
				cwd->child_min_heap.push(arg);
				cwd->size.first++;
			}
		}
		else if (cmd == "rmalb") {
			pii result = { 1, 0 };
			if (cwd->size.first != 0) {
				if (arg == "-1") {
					string target_name = cwd->child_min_heap.top();
					cwd->child_min_heap.pop();
					while (cwd->child_map.find(target_name) == cwd->child_map.end()) {
						target_name = cwd->child_min_heap.top();
						cwd->child_min_heap.pop();
					}
					pii temp =  cwd->child_map[target_name]->rmalb();
					result.first += temp.first;
					result.second += temp.second;
					cwd->child_map.erase(target_name);
					cwd->size.first--;
				}
				else if (arg == "1") {
					string target_name = cwd->child_max_heap.top();
					cwd->child_max_heap.pop();
					while (cwd->child_map.find(target_name) == cwd->child_map.end()) {
						target_name = cwd->child_max_heap.top();
						cwd->child_max_heap.pop();
					}
					pii temp = cwd->child_map[target_name]->rmalb();
					result.first += temp.first;
					result.second += temp.second;
					cwd->child_map.erase(target_name);
					cwd->size.first--;
				}
				else if (arg == "0") {
					result = { cwd->size.first, 0 };
					while (!cwd->child_max_heap.empty()) cwd->child_max_heap.pop();
					while (!cwd->child_min_heap.empty()) cwd->child_min_heap.pop();
					for (auto it = cwd->child_map.begin(); it != cwd->child_map.end(); it++) {
						pii temp = it->second->rmalb();
						result.first += temp.first;
						result.second += temp.second;
					}
					cwd->child_map.clear();
					cwd->size.first = 0;
				}
				else {
					if (cwd->child_map.find(arg) != cwd->child_map.end()) {
						pii temp = cwd->child_map.find(arg)->second->rmalb();
						result.first += temp.first;
						result.second += temp.second;
						cwd->child_map.erase(arg);
						cwd->size.first--;
					}
					else {
						result = { 0, 0 };
					}
				}
			}
			else {
				result = { 0, 0 };
			}
			cout << result.first << ' ' << result.second << endl;
		}
		else if (cmd == "insert") {
			if (cwd->photo_map.find(arg) != cwd->photo_map.end()) {
				cout << "duplicated photo name\n";
			}
			else {
				cwd->photo_map.insert({ arg, true });
				cwd->photo_max_heap.push(arg);
				cwd->photo_min_heap.push(arg);
				cwd->size.second++;
			}
		}
		else if (cmd == "delete") {
			int result = 0;
			if (cwd->size.second != 0) {
				if (arg == "-1") {
					string target_name = cwd->photo_min_heap.top();
					cwd->photo_min_heap.pop();
					while (cwd->photo_map.find(target_name) == cwd->photo_map.end()) {
						target_name = cwd->photo_min_heap.top();
						cwd->photo_min_heap.pop();
					}
					cwd->photo_map.erase(target_name);
					result += 1;
				}
				else if (arg == "1") {
					string target_name = cwd->photo_max_heap.top();
					cwd->photo_max_heap.pop();
					while (cwd->photo_map.find(target_name) == cwd->photo_map.end()) {
						target_name = cwd->photo_max_heap.top();
						cwd->photo_max_heap.pop();
					}
					cwd->photo_map.erase(target_name);
					result = 1;
				}
				else if (arg == "0") {
					while (!cwd->photo_max_heap.empty()) cwd->photo_max_heap.pop();
					while (!cwd->photo_min_heap.empty()) cwd->photo_min_heap.pop();
					cwd->photo_map.clear();
					result = cwd->size.second;
				}
				else {
					if (cwd->photo_map.find(arg) != cwd->photo_map.end()) {
						cwd->photo_map.erase(arg);
						result = 1;
					}
				}
				cwd->size.second -= result;
			}
			cout << result << endl;
		}
		else {
			if (arg == "..") {
				if (cwd->parent) cwd = cwd->parent;
			}
			else if (arg == "/") {
				cwd = home;
			}
			else {
				if (cwd->child_map.find(arg) != cwd->child_map.end()) {
					cwd = cwd->child_map.find(arg)->second;
				}
			}
			cout << cwd->name << endl;
		}
		//cwd->dir();
	}
	//cwd->dir();

	return 0;
}
