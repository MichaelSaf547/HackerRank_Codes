#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int pylons(int k, int arr_count, int* arr) {
    
    int res = 0;
    int start = 0;
    int i = 0;
    int prev = -1;
    
    while(start < arr_count)
    {
        i = start + k - 1;
        
        while(i >= arr_count)
        {
            i--;
        }
        
        if(arr[i] == 1)
        {
            res += 1;
            start = i + k;
            prev = i;
        }
        else
        {
            i--;
            while((i > prev) && (arr[i] != 1))
            {
                i--;
            }
            if(i > prev)
            {
                start = i + k;
                res++;
                prev = i;
            }
            else
            {
                res = -1;
                break;
            }
        }
    }
    
    if (res == 0)
    {
        return -1;
    }
    else
    {
        return res;
    } 
}

int main()
{
    int k = 2;
    int n = 7;
    int arr[] = {0, 1, 0, 0, 0, 1, 0};
    int result = pylons(k, n, arr);

    printf("%d\n", result);
    
    k = 3;
    n = 10;
    int arr2[] = {0, 1, 0, 0, 0, 1, 1, 1, 1, 1};
    result = pylons(k, n, arr2);

    printf("%d\n", result);

    return 0;
}
