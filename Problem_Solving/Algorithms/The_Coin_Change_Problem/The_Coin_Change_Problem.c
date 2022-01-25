
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



long getWays(int n, int c_count, long* c) {
    
    int i = 0;
    int j = 0;
    long arr[c_count][n + 1];
    
    long temp_1 = 0;
    long temp_2 = 0;
    
    for(i = 0; i < c_count; i++)
    {
        arr[i][0] = 1;
    }
    
    for(i = 0; i < c_count; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(i != 0)
            {
                temp_1 = arr[i - 1][j];
            }
            else 
            {
                temp_1 = 0;
            }
            
            if(j - c[i] >= 0)
            {
                temp_2 = arr[i][j - c[i]];
            }
            else
            {
                temp_2 = 0;
            }
            arr[i][j] = temp_1 + temp_2;
        }
    }
    
    return arr[c_count - 1][n];
}

int main()
{
    int n = 4;
    int m = 3;
    long c[] = {1, 2, 3}; // 4

    long ways = getWays(n, m, c);

    printf("%ld\n", ways);
    
    n = 10;
    m = 4;
    long c2[] = {2, 5, 3, 6}; // 5
    
    ways = getWays(n, m, c2);

    printf("%ld\n", ways);

    return 0;
}

