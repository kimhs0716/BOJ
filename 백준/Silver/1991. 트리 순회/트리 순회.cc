#include <iostream>
using namespace std;
char arr[26][2];
void search_1(char node);
void search_2(char node);
void search_3(char node);
int main(){
    int n; cin >> n;
    char ch, left, right;
    for(int i = 0; i < n; i++){
        scanf(" %c %c %c", &ch, &left, &right);
        arr[ch - 'A'][0] = left;
        arr[ch - 'A'][1] = right;
    }
    search_1('A');
    printf("\n");
    search_2('A');
    printf("\n");
    search_3('A');
    return 0;
}
void search_1(char node){
    if(node == '.') return;
    printf("%c", node);
    search_1(arr[node - 'A'][0]);
    search_1(arr[node - 'A'][1]);
}
void search_2(char node){
    if(node == '.') return;
    search_2(arr[node - 'A'][0]);
    printf("%c", node);
    search_2(arr[node - 'A'][1]);
}
void search_3(char node){
    if(node == '.') return;
    search_3(arr[node - 'A'][0]);
    search_3(arr[node - 'A'][1]);
    printf("%c", node);
}
