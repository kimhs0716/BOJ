#include <iostream>
using namespace std;
typedef struct{
    int day, month, year;
} date;
typedef struct {
    char name[16];
    date bd;
} student;
int cmp(student s1, student s2);
int main(){
    int n;
    cin >> n;
    student oldest, youngest;
    n--;
    student temp;
    cin >> temp.name >> temp.bd.day >> temp.bd.month >> temp.bd.year;
    oldest = youngest = temp;
    while(n--){
        cin >> temp.name >> temp.bd.day >> temp.bd.month >> temp.bd.year;
        if(cmp(oldest, temp)){
            oldest = temp;
        }
        if(!cmp(youngest, temp)){
            youngest = temp;
        }
    }
    cout << youngest.name << endl << oldest.name << endl;
    return 0;
}
int cmp(student s1, student s2){
    if(s1.bd.year > s2.bd.year) return 1;
    if(s1.bd.year < s2.bd.year) return 0;
    if(s1.bd.month > s2.bd.month) return 1;
    if(s1.bd.month < s2.bd.month) return 0;
    if(s1.bd.day > s2.bd.day) return 1;
    return 0;
}
