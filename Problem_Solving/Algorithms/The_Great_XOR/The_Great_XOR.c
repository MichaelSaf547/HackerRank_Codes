
#include <stdio.h>
#include <stdlib.h>



long theGreatXor(long x) {
    long res = 0;
    int i = 0;
    long temp = 0;
    
    for(i = 0; i < 64; i++)
    {
        temp = 1ul << i;
        if(temp > x)
        {
            break;
        }
        temp ^= x;
        if(temp < x)
        {
            continue;
        }
        else if(temp > x)
        {
            res += 1ul << i;
        }  
        else
        {
            continue;
        } 
        
    }
    
    return res;
}

int main()
{

    long x = 10;

    long result = theGreatXor(x);       // 5

    printf("%ld\n", result);
    
    x = 100;

    result = theGreatXor(x);            // 27

    printf("%ld", result);

    return 0;
}

