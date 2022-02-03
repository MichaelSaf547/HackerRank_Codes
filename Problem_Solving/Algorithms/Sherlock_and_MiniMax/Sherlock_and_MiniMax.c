
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void merge(int * ptr, int l_len, int * left, int r_len, int * right)
{
    int i = 0;
    int j = 0;
    
    while(i < l_len && j < r_len)
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
    
    while(i < l_len)
    {
        ptr[i + j] = left[i];
        i++;
    }
    
    while(j < r_len)
    {
        ptr[i + j] = right[j];
        j++;
    }
}

void mergesort(int * ptr, int len)
{
    if(len > 1)
    {
        int mid = len >> 1;
        int i = 0;
        int *left = (int *)malloc(sizeof(int) * mid);
        int * right = (int *)malloc(sizeof(int) * (len -mid));
        
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
        
        merge(ptr, mid, left, len-mid, right);
        
        free(left);
        free(right);
    }
}


int sherlockAndMinimax(int arr_count, int* arr, int p, int q) {
    int max_col = 0;
    int min_row = 0;
    int i = 0;
    int j = 0;
    int index = 0;
    int mean = 0;
    
    mergesort(arr, arr_count);
   
    i = p;
    
    while(i < q)
    {
        if(i < arr[0])
        {
            min_row = arr[0] - i;
            if(min_row > max_col)
            {
                max_col = min_row;
                index = i;
            }
            i = arr[0] + 1;
        }
        else if(i > arr[arr_count - 1])
        {
            min_row = q - arr[arr_count - 1];
            if(min_row > max_col)
            {
                max_col = min_row;
                index = q;
            }
            i = q;
        }
        else
        {
            while(i > arr[j])
            {
                j++;
            }
            
            mean = ((arr[j] - arr[j - 1]) >> 1) + arr[j - 1];
            if(mean < i)
            {
                min_row = arr[j] - i;
                if(min_row > max_col)
                {
                    max_col = min_row;
                    index = i;
                }
                i = arr[j] + 1;
            }
            else
            {
                if(mean > q)
                {
                    mean = q;
                }
                min_row = mean - arr[j - 1];
                if(min_row > max_col)
                {
                    max_col = min_row;
                    index = mean;
                }
                i = arr[j] + 1;
                    
            }
        }
    }
    
    return index;
}


int main()
{
    int n = 5;
    int arr[] = {12, 10, 50, 24, 40};
    int p = 9;
    int q = 16;

    int result = sherlockAndMinimax(n, arr, p, q);  // 16

    printf("%d\n", result);


    return 0;
}

