#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100001

int arr[MAX];
char p[MAX];
char buf[4 * MAX + 2];

void prt_arr(int start, int end, int flag) {
	if (start < end) {
		printf("[");
		if (flag) {  //뒤집어져있으면 뒤에서부터 출력
			int i = end - 1;
			while (i > start) {
				printf("%d,", arr[i]);
				i--;
			}
			printf("%d", arr[start]);  //마지막 요소는 콤마 없다
		}

		else {
			int i = start;
			while (i < end - 1) {   //아니라면 그대로
				printf("%d,", arr[i]);
				i++;
			}
			printf("%d", arr[end - 1]); //마지막 요소는 콤마 없다
		}
		printf("]\n");
	}

	else if (start == end) {
		printf("[]\n");
	}

	else
		printf("error\n");
}

int main()
{
	int T, start = 0, end;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) 
	{
		start = 0;
		scanf("%s", p);
		scanf("%d", &end);
		scanf("%s", buf);

		
		char* token = strtok(buf, "[,]");
		int k = 0;
		while (token != NULL) {
				arr[k] = atoi(token);
				token = strtok(NULL, "[,]");
				k++;
		}

		int j = 0;
		int R_flag = 0; //뒤집어짐 표시;
		while (p[j] != '\0' && start <= end) {
			if (p[j] == 'R')
				R_flag = (R_flag + 1) % 2;
			else{
				if (R_flag)  //뒤집어져 있으면 끝을 지운다
					end--;
				else
					start++;   //아니면 앞을 지운다.
			}
			j++;
		}

		prt_arr(start, end, R_flag);
	}
	return 0;
}