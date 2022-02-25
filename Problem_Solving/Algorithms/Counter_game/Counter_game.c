
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 
char* counterGame(unsigned long n) {
    int flag = 1; 
    char * res;
    int i = 0;
    unsigned long temp;
    if(n == 1)
    {
        flag = 1;
    }
    else
    {
        for(i = 63; i >= 0; i--)
        {
            temp = (((unsigned long)1) << i);
            if(temp < n)
            {
                n = n - temp;
                flag ^= 1;
            }
            else if(temp == n)
            {
                if((i & 1) == 1)
                {
                    flag ^= 1;
                    break;
                }
                else
                {
                    break;
                }
            }
            else
            {
                continue;
            } 
        }
    }  
    
    if(flag == 1)
    {
        res = (char *)malloc(sizeof(char) * strlen("Richard."));
        strcpy(res, "Richard");
    }
    else
    {
        res = (char *)malloc(sizeof(char) * strlen("Louise."));
        strcpy(res, "Louise");
    }
    
    return res;
}

int main()
{
    unsigned long n = 660570904136157;

    char* result = counterGame(n);

    printf("%s\n", result);
    
    n = 605846385118282;

    result = counterGame(n);

    printf("%s\n", result);
        
    return 0;
}

