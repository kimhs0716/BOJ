#include <stdio.h>
int cube(int n){
    return n * n * n;
}
int main(){
    for(int a = 2; a <= 100; a++){
        for(int b = 2; b <= a; b++){
            for(int c = b; c < a; c++){
                for(int d = c; d < a; d++){
                    if(cube(a) == cube(b) + cube(c) + cube(d)){
                        printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
                    }
                }
            }
        }
    }
    return 0;
}
