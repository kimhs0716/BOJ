#include<stdio.h>

int main(){
  int q[100000];
  for(int i=0;i<100000;i++){
    q[i] =0;
  }
  int p= 0;
  int K;
  int all=0;
  scanf("%d",&K);
  for(int i=0;i<K;i++){
    int answer;
    scanf("%d",&answer);
    if(answer==0){
      if(p!=0){
        p-=1;
      }
      q[p]=0;
    }
    else{
      q[p] =answer;
      p+=1;
    }
  }
  for(int i=0;i<100000;i++){
    all+=q[i];
  }
  printf("%d\n",all);
  return 0;
}