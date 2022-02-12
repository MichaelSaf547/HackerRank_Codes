#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void merge(int * ptr, int left_len, int *left, int right_len, int * right)
{
    int i = 0; 
    int j = 0;
    
    while(i < left_len && j < right_len)
    {
        if(left[i] < right[j])
        {
            ptr[i + j] = left[i];
            i++;
        }
        else
        {
            ptr[i + j] = right[j];
            j++;
        }
    }
    
    while(i < left_len)
    {
        ptr[i + j] = left[i];
        i++;
    }
    
    while(j < right_len)
    {
        ptr[i + j] = right[j];
        j++;
    }
} 

void mergesort(int * ptr, int len)
{
    
    if(len > 1)
    {
        int mid = len / 2 ;
        int * left = (int *)malloc(sizeof(int) * mid);
        int * right = (int *)malloc(sizeof(int) * (len - mid));
        int i = 0;
        
        for(i = 0; i < mid; i++)
        {
            left[i] = ptr[i];
        }
        
        for(i = 0; i < len - mid; i++)
        {
            right[i] = ptr[i + mid];
        }
        
        mergesort(left, mid);
        mergesort(right, len - mid);
        
        merge(ptr, mid, left, len - mid, right);
        
        free(left);
        free(right);
    }
}

int Exist(int * ptr, int len, int target)
{
    int low = 0;
    int high = len - 1;
    int mid = (high - low) >> 1;
    
    while(low <= high)
    {
        if(ptr[mid] == target)
        {
            return 1;
        }
        else if(ptr[mid] < target)
        {
            low = mid + 1;
            mid = (high + low) >> 1;
        }
        else
        {
            high = mid - 1;
            mid = (high + low) >> 1;
        }
    }
    
    return 0;
}

int pairs(int k, int arr_count, int* arr) {
    int i = 0;
    int res = 0;
    
    mergesort(arr, arr_count);
    
    for(i = 0; i < arr_count - 1; i++)
    {
        if(Exist(&(arr[i + 1]), (arr_count - i - 1), arr[i] + k) == 1)
        {
            res++;
        }
    }
    
    return res;
}

int main()
{
    int n = 7;
    int k = 2;
    int arr[] = {1, 3, 5, 8, 6, 4, 2};
    
    int result = pairs(k, n, arr);  // 5

    printf("%d\n", result);


    return 0;
}

