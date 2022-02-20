
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int len_int(unsigned long num)
{
    int res = 0;
    while(num != 0)
    {
        res++;
        num /= 10;
    }
    return res;
}

void separateNumbers(char* s) {
    
    unsigned long start = s[0] - '0';
    unsigned long search_for;
    
    int i = 0;
    int len = strlen(s);
    int rest_len = len - 1;
    int number_len = 1;
    char temp[40];
    int flag = 0;
    
    if(start == 0)
    {
        flag = 0;
    }
    else
    {
        search_for = start + 1;
        sprintf(temp, "%lu", search_for);
        i = 1;
        
        while(s[i] != '\0')
        {
            if(rest_len >= number_len)
            {
                
                if(strstr(&(s[i]), temp) == &(s[i]))
                {
                    number_len = len_int(search_for);
                    i += number_len;
                    search_for++;
                    sprintf(temp, "%lu", search_for);
                    flag = 1;
                }
                else
                {
                    if(flag == 1)
                    {
                        flag = 0;
                        int j = 0;
                        start = 0;
                        for(j = 0; j < i; j++)
                        {
                            start = start * 10 + (s[j] - '0');
                        }
                        
                        search_for = start + 1;
                        sprintf(temp, "%lu", search_for);
                    
                        number_len = len_int(search_for);
                    }
                    else
                    {
                        start = start * 10 + (s[i] - '0');
                        i++;
                        
                        search_for = start + 1;
                        sprintf(temp, "%lu", search_for);
                    
                        number_len = len_int(search_for);
                        
                    } 
                }
            }
            else
            {
                flag = 0;
                break;
            } 
            rest_len = len - i;
        }
        
    }
    
    if(flag == 0)
    {
        printf("NO\n");
    }
    else
    {
        printf("YES %lu\n", start);
    } 
}

int main()
{
    char* s = "99910001001";

    separateNumbers(s);


    return 0;
}

