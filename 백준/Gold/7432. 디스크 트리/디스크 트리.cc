#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

vector<string> split(const string& s, char del) {
    vector<string> ret;
    string token;
    stringstream ss(s);
    while (getline(ss, token, del)) {
        ret.push_back(token);
    }
    return ret;
}

class Node {
public:
    string name;
    map<string, Node*> children;
    Node(string s) {
        name = s;
        children = map<string, Node*>();
    }
    void print(int depth = -1) {
        if (name != "root") cout << string(depth, ' ') << name << endl;
        for (auto it : children) it.second->print(depth + 1);
    }
};

int main() {
    FASTIO;

    Node* root = new Node("root");

    int n; cin >> n; 
    while (n--) {
        string path; cin >> path;
        Node* cwd = root;
        auto s = split(path, '\\');
        for (string dir : s) {
            if (cwd->children.find(dir) == cwd->children.end()) {
                cwd->children.insert({ dir, new Node(dir) });
            }
            cwd = cwd->children.find(dir)->second;
        }
    }

    root->print();

    return 0;
}
