#include <iostream>
#include <deque>
#include <sstream>
#include <string>
#include <fstream>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long int lld;
lld eval(lld n1, char op, lld n2);
int main(){
    FASTIO;
    //ifstream fin("D:/Desktop/19591.in");
    deque<lld> nums;
    deque<char> ops;
    lld n; char op;
    string str; cin >> str;
    stringstream ss(str);
    ss >> n; nums.push_back(n);
    while(!ss.eof()){
        ss >> op >> n;
        ops.push_back(op);
        nums.push_back(n);
    }
    while(nums.size() > 1){
        //cout << nums.size() << ", " << ops.size() << endl;
        bool f;
        lld n1 = nums.front(), n2, n3, n4 = nums.back();
        nums.pop_front(); nums.pop_back();
        n2 = nums.front(); n3 = nums.back();
        char op1 = ops.front(), op2 = ops.back();
        lld ret1 = eval(n1, op1, n2), ret2 = eval(n3, op2, n4);
        if((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-')) f = 1;
        else if((op1 == '+' || op1 == '-') && (op2 == '*' || op2 == '/')) f = 0;
        else if(ret1 < ret2) f = 0;
        else f = 1;
        if(f == 1){
            nums.pop_front(); ops.pop_front();
            nums.push_back(n4);
            nums.push_front(ret1);
        }
        else{
            nums.pop_back(); ops.pop_back();
            nums.push_front(n1);
            nums.push_back(ret2);
        }
    }
    cout << nums[0] << endl;
    return 0;
}
lld eval(lld n1, char op, lld n2){
    switch(op){
        case '+':
            return n1 + n2;
        case '-':
            return n1 - n2;
        case '*':
            return n1 * n2;
        case '/':
            return n1 / n2;
    }
}
