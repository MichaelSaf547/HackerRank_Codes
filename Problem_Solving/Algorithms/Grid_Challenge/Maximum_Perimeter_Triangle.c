
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

int* maximumPerimeterTriangle(int sticks_count, int* sticks, int* result_count) {
    
    int i = sticks_count - 1;
    int flag = 1;
    int * res = NULL;
    
    mergesort(sticks, sticks_count);
    for(i = sticks_count - 1; i > 1; i--)
    {
        if(sticks[i] < sticks[i - 1] + sticks[i - 2])
        {
            break;
        }
    }
    if(i == 1)
    {
        flag = 0;
    }
    
    if(flag == 1)
    {
        res = (int *)malloc(sizeof(int) * 3);
        *result_count = 3;
        res[0] = sticks[i - 2];
        res[1] = sticks[i - 1];
        res[2] = sticks[i];
    }
    else
    {
        res = (int *)malloc(sizeof(int) * 1);
        *result_count = 1;
        res[0] = -1;
    }
    
    return res;
}

int main()
{

    int result_count;
    int n = 5;
    int sticks[] = {1, 1, 1, 3, 3};
    int* result = maximumPerimeterTriangle(n, sticks, &result_count);

    for (int i = 0; i < result_count; i++) {
        printf("%d", *(result + i));

        if (i != result_count - 1) {
            printf(" ");
        }
    }
    printf("\n");

    n = 3;
    sticks[0] = 2;
    sticks[1] = 3;
    sticks[2] = 5;
    result = maximumPerimeterTriangle(n, sticks, &result_count);

    for (int i = 0; i < result_count; i++) {
        printf("%d", *(result + i));

        if (i != result_count - 1) {
            printf(" ");
        }
    }

    return 0;
}
