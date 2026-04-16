#include<stdio.h>
int main()
{
	int a[9];
	int max,b = 1;
	for(int i=0; i<9; i++){
		scanf("%d",&a[i]);
	}
	max=a[0];
	for(int j=1; j<9; j++){
		if(max<a[j]){
			max=a[j];
			b=j+1;
		}
	}
	printf("%d\n%d",max,b);
}