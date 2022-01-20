#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getInvCount(int * ptr, int n)
{
    int inv_count = 0;
    int i;
    int j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (ptr[i] > ptr[j])
            {
                inv_count++;
            }
        }    
    }    

    return inv_count;
}

char* larrysArray(int A_count, int* A) {
    char * res;
    int flag = 0;
    int temp;
    int i;
    
    temp = getInvCount(A, A_count);
    
    if(temp % 2 == 0)
    {
        flag = 1;
    }
    
    if(flag == 0)
    {
        res = (char *)malloc(sizeof(char) * strlen("NO."));
        strcpy(res, "NO");
    }
    else
    {
        res = (char *)malloc(sizeof(char) * strlen("YES."));
        strcpy(res, "YES");
    }
    return res;
}

int main()
{
    int len = 6;

    int arr[6] = {1, 6, 5, 2, 4, 3};

    char* result = larrysArray(len, arr);

    printf("%s\n", result);

    return 0;
}