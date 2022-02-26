

#include <stdio.h>
#include <stdlib.h>



long andProduct(long a, long b) {
    long res = 0;
    long diff = b - a;
    if(diff == 0)
    {
        res = a;
    }
    else
    {
        int i = 0;
        int temp = 0;
        for(i = 0; i < 64; i++)
        {
            temp = (1ul << i);
            if(temp == diff)
            {
                res = a >> i;
                res = res << i;
                break;
            }
            else if(temp < diff)
            {
                continue;
            }
            else
            {
                a = a >> i;
                a = a << i;
                res = a & b;
                break;
            } 
            
        }
    } 
    
    return res;
}

int main()
{

    long a = 10;

    long b = 14;

    long result = andProduct(a, b);         // 8

    printf("%ld\n", result);
    
    a = 17;

    b = 23;

    result = andProduct(a, b);         // 16

    printf("%ld", result);

    return 0;
}

