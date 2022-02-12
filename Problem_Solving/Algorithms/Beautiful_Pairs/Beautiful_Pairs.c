
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int beautifulPairs(int A_count, int* A, int B_count, int* B) {
    int BArr[1001] = {0};
    int i = 0;
    int res = 0;
    
    for(i = 0; i < B_count; i++)
    {
        BArr[B[i] - 1]++;
    }
    
    for(i = 0; i < A_count; i++)
    {
        if(BArr[A[i] - 1] != 0)
        {
            res += 1;
            BArr[A[i] - 1]--;
        }
    }
    
    if(res == B_count)
    {
        res--;
    }
    else
    {
        res++;
    } 
    
    return res;
}

int main()
{
    int n = 6;
    
    int A[] = {3, 5, 7, 11, 5, 8};
    
    int B[] = {5, 7, 11, 10, 5, 8};
        
    int result = beautifulPairs(n, A, n, B);  //6

    printf("%d\n", result);

    return 0;
}
