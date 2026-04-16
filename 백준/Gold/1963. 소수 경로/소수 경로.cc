#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
bool isprime(int n);
int main() {
    bool visited[10000];
    int t;
    cin >> t;
    while(t--){
        memset(visited, 0, 10000 * sizeof(bool));
        int a, b;
        cin >> a >> b;
        queue<pair<int, int>> q;
        q.push({a, 0});
        pair<int, int> item;
        int num;
        do{
            item = q.front();
            num = item.first;
            //cout << q.size() << ", " << item.first << ", " << item.second << endl;
            int d = item.second + 1;
            q.pop();
            if(num < 1000) continue;
            if(isprime(num) == false) continue;
            if(visited[num]) continue;
            visited[num] = true;
            for(int i = 0; i < 10; i++){
                q.push({num % 1000 + i * 1000, d});
                q.push({num / 1000 * 1000 + i * 100 + num % 100, d});
                q.push({num / 100 * 100 + i * 10 + num % 10, d});
                q.push({num / 10 * 10 + i, d});
            }
        }while(num != b);
        cout << item.second << endl;
    }
	return 0;
}
bool isprime(int n){
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    int i = 3;
    while(i * i <= n){
        if(n % i == 0) return false;
        i++;
    }
    return true;
}
