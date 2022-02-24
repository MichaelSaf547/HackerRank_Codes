#include <stdio.h>
#include <stdlib.h>

int find_max_index(int *ptr, int len)
{
    int res = 0;
    int i = 0;
    for(i = 1; i < len; i++)
    {
        if(ptr[res] < ptr[i])
        {
            res = i;
        }
    } 
    return res;
}


long stockmax(int prices_count, int* prices) {
    long res = 0;
    int i = 0;
    int j = 0;
    int temp = 0;
    
    for(i = 0; i < prices_count - 1; i++)
    {
        if(temp <= i)
        {
            temp = find_max_index(&(prices[i + 1]), prices_count - i - 1); 
            temp += (i + 1);
        }
        if(prices[temp] > prices[i])
        {
            res += (prices[temp] - prices[i]);
        }
                
    }
    
    return res;
}

int main()
{
    int n = 5;
    
    int prices[] = {5, 4, 3, 4, 5};
    
    long result = stockmax(n, prices);      // 4

    printf("%ld\n", result);
    
    n = 4;
    
    int prices2[] = {1, 2, 3, 4};
    
    result = stockmax(n, prices2);      // 6

    printf("%ld\n", result);

    return 0;
}

