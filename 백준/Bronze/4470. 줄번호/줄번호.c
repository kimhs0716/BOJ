#include <stdio.h>
#include <string.h>
int main(void)
{
  int n, i, j, len;
  char s[51];
  scanf("%d", &n);
  for (i=1;i<=n;i++)
    {
      getchar();             //4470은 getchar() 가 필요한데 29716은 그렇지 않은 이유?
      scanf("%[^\n]s", s);   //4470은 "%[^\n]s", 29716은 " %[^\n]s"로 입력 받아야 하는 이유?
      len = strlen(s);
      printf("%d. ", i);
      for (j=0;j<len;j++)
        printf("%c", s[j]);
      printf("\n");
    }
  return 0;
}