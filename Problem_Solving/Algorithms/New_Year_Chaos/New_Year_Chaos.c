
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int merge (int * ptr, int l_len, int * left, int r_len, int * right)
{
    int i = 0;
    int j = 0;
    int res = 0;
    
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
            res += l_len - i;
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
        res += l_len - i;
    }
    
    return res;
}
 

int mergesort(int * ptr, int len)
{
    if(len > 1)
    {
        int mid = len >> 1;
        int * left = (int *)malloc(sizeof(int) * mid);
        int * right = (int *)malloc(sizeof(int) * (len - mid));
        int i = 0;
        int res = 0;
        
        for(i = 0; i < mid; i++)
        {
            left[i] = ptr[i];
        }
        
        for(i = 0; i < (len - mid); i++)
        {
            right[i] = ptr[i + mid];
        }
        
        res += mergesort(left, mid);
        res += mergesort(right, len - mid);
        
        res += merge(ptr, mid, left, len - mid, right);
        
        return res;
    }
    else
    {
        return 0;
    }
}

void minimumBribes(int q_count, int* q) {
    int i = 0;
    int temp = 0;
    int flag = 0;
    
    for(i = 0; i < q_count; i++)
    {
        if(q[i] - (i + 1) > 2)
        {
            flag = 1;
            break;
        }
    }

    if(flag == 1)
    {
        printf("Too chaotic\n");
    }
    else
    {
        temp = mergesort(q, q_count);
        
        printf("%d\n", temp);
    }
}


int main()
{
    int n = 8;
    
    int q[] = {5, 1, 2, 3, 7, 8, 6, 4};
    
    minimumBribes(n, q);    // Too chaotic
    
    int q2[] = {1, 2, 5, 3, 7, 8, 6, 4};

    minimumBribes(n, q2);   // 7

    return 0;
}
