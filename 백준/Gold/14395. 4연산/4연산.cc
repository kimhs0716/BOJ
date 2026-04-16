#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main() {
    queue<pair<long, string>> q;
    long s, t;
    cin >> s >> t;
    if(s == t){
        cout << "0\n";
        return 0;
    }
    q.push({s, ""});
    pair<long, string> item;
    bool visited_0 = false;
    bool visited_1 = false;
    do{
        if(q.empty()){
            cout << "-1\n";
            return 0;
        }
        item = q.front();
        q.pop();
        if(visited_0 == true && item.first == 0) continue;
        if(visited_1 == true && item.first == 1) continue;
        if(item.first == 1) visited_1 = true;
        if(item.first * item.first <= t) q.push({item.first * item.first, item.second + "*"});
        if(2 * item.first <= t) q.push({2 * item.first, item.second + "+"});
        if(visited_0 == false) { q.push({0, item.second + "-"}); visited_0 = true; }
        if(item.first != 0) q.push({1, item.second + "/"});
    }while(item.first != t);
    cout << item.second << endl;
	return 0;
}
