

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int towerBreakers(int n, int m) {
    if(m == 1)
    {
        return 2;
    }
    else
    {
        if(n % 2 == 0)
        {
            return 2;
        }
        else
        {
            return 1;
        }
    }
    
}

int main()
{

    int n = 1000;

    int m = 1;

    int result = towerBreakers(n, m);

    printf("%d\n", result);
    
    n = 11;

    m = 10;

    result = towerBreakers(n, m);

    printf("%d\n", result);

    return 0;
}

