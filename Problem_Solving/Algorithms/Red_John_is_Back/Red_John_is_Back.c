
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int fact[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};

int nCr(int n, int r)
{
    int res = 1;
    int i = n;
    int com;
    int div;
    
    if(n - r > r)
    {
        com = n - r;
        div = r;
    }
    else
    {
        com = r;
        div = n - r;
    }
    
    for(i = n; i > com; i--)
    {
        res *= i;
    }
    
    res /= fact[div];
    
    return res;
}

int isPrime(int num)
{
	if(num <= 1)
	{
		return 0;
	}
	
    else if(num == 2 || num == 3)
    {
        return 1;
    }
    else
    {
        int i = 0;
    
        for(i = 2; i <= (int)sqrt(num) + 1; i++)
        {
            if(num % i == 0)
            {
                return 0;
            }
        }
    }
    
    return 1;
}

int redJohn(int n) {
    if(n < 4)
    {
        return 0;
    }
    else
    {
        int division = n >> 2;
        int mod;
        int i = 1;
        int sum_of_poss = 1;
        int res = 0;
        
        for(i = 1; i <= division; i++)
        {
            mod = n - (i << 2);
            sum_of_poss += nCr(mod + i, i);
        }
        
        for(i = sum_of_poss; i > 1; i--)
        {
            res += isPrime(i);
        }
        return res;
    }
}

int main()
{
    int n = 10;
    
    int result = redJohn(n);    // 6 Prime numbers in 14 possibilities 

    printf("%d\n", result);

    n = 12;
    
    result = redJohn(n);    // 9 Prime numbers in 26 possibilities 

    printf("%d\n", result);

    return 0;
}
