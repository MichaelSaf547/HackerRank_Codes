#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long candies(int n, int arr_count, int* arr) {
    long res = 1;
    int i = 0;
    int prev = 1;
    int flag = 0;
    int start_prev = 0;
    
    for(i = 1; i < arr_count; i++)
    {
        if(arr[i] > arr[i - 1])
        {
            prev++;
            res += prev;  
            flag = 0;  
            start_prev = 0;
        }
        else if(arr[i] == arr[i - 1])
        {
            prev = 1;
            res += prev;
            flag = 0;
            start_prev = 0;
        }
        else
        {
            if(flag == 0)
            {
                if(prev == 1)
                {
                    res += 2;
                    flag += 2;
                    start_prev = 0;
                }
                else
                {
                    start_prev = prev;
                    prev = 1;
                    res += prev;
                    flag++;
                }
            }
            else
            {
                if(start_prev == flag + 1)
                {
                    res++;
                    start_prev++;
                }
                res += 1 + flag;
                flag++;
            }
            
        }
        
    }
    
    return res;
}

int main()
{
    int n = 10;
    
    int arr[] = {10, 15, 18, 12, 11, 11, 11, 15, 13, 2};
    
    long result = candies(n, n, arr);

    printf("%ld\n", result);

    return 0;
}

