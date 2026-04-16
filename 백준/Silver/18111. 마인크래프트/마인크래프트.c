#include <stdio.h>
int arr[501][501];
int main(){
    int n, m, b;
    int max = -1;
    int min = 501;
    int time_result = 99999999;
    int block_height = 99999999;
    scanf("%d %d %d", &n, &m, &b);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
            if (min > arr[i][j])
                min = arr[i][j];
            if (max < arr[i][j])
                max = arr[i][j];
        }
    }
    for (int i = min; i <= max; i++)
    {
        int time = 0;
        int block = b;
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                int height = arr[j][k] - i;
                if (height > 0)
                {
                    time = time + height * 2;
                    block = block + height;
                }
                else if (height < 0)
                {
                    time = time - height;
                    block = block + height;
                }
            }
        }
        if (block >= 0)
        {
            if (time <= time_result)
            {
                time_result = time;
                block_height = i;
            }
        }
    }
    printf("%d %d", time_result, block_height);
    return 0;
}
