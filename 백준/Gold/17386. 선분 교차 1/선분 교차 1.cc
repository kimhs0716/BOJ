#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>
#include <sstream>
#include <numeric>
#include <cstdlib>
#include <ctime>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int, int>
#define psi pair<string, int>
#define pll pair<lld, lld>
#define INF 987654321
using namespace std;
typedef long long int lld;
typedef struct {
    lld x, y;
} point;
typedef struct {
    point p1, p2;
} line;
int ccw(const point &p1, const point &p2, const point &p3);
bool cross(line &l1, line &l2);
int cmp(const point &p1, const point &p2);
void swap(point &p1, point &p2);
int main(){
    //FASTIO;
    point p1, p2, p3, p4;
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    cin >> p3.x >> p3.y >> p4.x >> p4.y;
    line l1, l2;
    l1.p1 = p1; l1.p2 = p2;
    l2.p1 = p3; l2.p2 = p4;
    cout << cross(l1, l2) << endl;
    return 0;
}
int ccw(const point &p1, const point &p2, const point &p3){
    lld cp = (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
    if(cp > 0) return 1;
    if(cp < 0) return -1;
    return 0;
}
void swap(point &p1, point &p2){
    point tmp;
    tmp = p1;
    p1 = p2;
    p2 = tmp;
}
bool cross(line &l1, line &l2){
    lld l1_l2 = ccw(l1.p1, l1.p2, l2.p1) * ccw(l1.p1, l1.p2, l2.p2);
    lld l2_l1 = ccw(l2.p1, l2.p2, l1.p1) * ccw(l2.p1, l2.p2, l1.p2);

    if(l1_l2 == 0 && l2_l1 == 0){
        if(cmp(l1.p2, l1.p1)) swap(l1.p1, l1.p2);
        if(cmp(l2.p2, l2.p1)) swap(l2.p1, l2.p2);
        return cmp(l2.p1, l1.p2) && cmp(l1.p1, l2.p2);
    }

    return (l1_l2 <= 0) && (l2_l1 <= 0);
}
int cmp(const point &p1, const point &p2){
    if(p1.x == p2.x) return p1.y <= p2.y;
    return p1.x <= p2.x;
}
