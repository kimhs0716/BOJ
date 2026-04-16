#include <iostream>
#define MAX_SIZE 100
class matrix {
public:
    int r, c;
    int arr[MAX_SIZE][MAX_SIZE];
    matrix(int n, int m);
    void print();
    void input();
    matrix mul(matrix mat);
    matrix add(matrix mat);
};
matrix::matrix(int n, int m){
    r = n;
    c = m;
}
void matrix::print(){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}
void matrix::input(){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++)
            scanf("%d", &arr[i][j]);
    }
}
matrix matrix::add(matrix mat){
    matrix res(r, mat.c);
    for(int i = 0; i < r; i++){
        for(int j = 0; j < mat.c; j++){
            res.arr[i][j] = arr[i][j] + mat.arr[i][j];
        }
    }
    return res;
}
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    matrix m1(n, m);
    m1.input();
    matrix m2(n, m);
    m2.input();
    m1.add(m2).print();
    return 0;
}
