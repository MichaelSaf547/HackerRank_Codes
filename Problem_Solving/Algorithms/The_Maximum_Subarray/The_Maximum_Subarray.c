
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max_negative(int * ptr, int len)
{
    int res = 0x80000000;
    int i = 0;
    for(i = 0; i < len; i++)
    {
        if(ptr[i] > 0)
        {
            res = 1;
            break;
        }
        else
        {
            if(ptr[i] > res)
            {
                res = ptr[i];
            }
        }
    }
    return res;
} 
 
int* maxSubarray(int arr_count, int* arr, int* result_count) {
    *result_count = 2;
    int *res = (int *)malloc(sizeof(int) * 2);
    int i = 0;
    int max = 0xffffffff;
    int max_positive = 0;
    int temp = 0;
    
    temp = max_negative(arr, arr_count);
    if(temp == 1)
    {
        temp = 0;
        for(i = 0; i < arr_count; i++)
        {
            if(arr[i] > 0)
            {
                max_positive += arr[i];
            }
            temp += arr[i];
            if(temp <= 0)
            {
                temp = 0;
            }
            else
            {
                if(temp > max)
                {
                    max = temp;
                }
            }
        }
        res[0] = max;
        res[1] = max_positive;
    }
    else
    {
        res[0] = temp;
        res[1] = temp;
    }
    
    return res;
}

int main()
{
    int n = 6;
    int arr[] = {-1, -2, -3, -4, -5, -6};
    int result_count;
    int* result = maxSubarray(n, arr, &result_count);   // -1 -1

    for (int i = 0; i < result_count; i++) {
        printf("%d", *(result + i));

        if (i != result_count - 1) {
            printf(" ");
        }
    }

    printf("\n");
    
    n = 6;
    int arr2[] = {1, -1, -1, -1, -1, 5};
    result_count;
    result = maxSubarray(n, arr2, &result_count);   // 5 6

    for (int i = 0; i < result_count; i++) {
        printf("%d", *(result + i));

        if (i != result_count - 1) {
            printf(" ");
        }
    }

    printf("\n");

    return 0;
}

