
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* morganAndString(char* a, char* b) {
    int a_len = strlen(a);
    int b_len = strlen(b);
    a = (char *)realloc(a, sizeof(char) * (a_len + 1));
    b = (char *)realloc(b, sizeof(char) * (b_len + 1));
    
    a[a_len] = 'z';
    b[b_len] = 'z';
    
    char * res = (char *)malloc(sizeof(char) * (a_len + b_len +1));
    int i = 0;
    int j = 0;
    int temp_cmp = 0;
    while(i < a_len && j < b_len)
    {
        if(a[i] < b[j])
        {
            res[i + j] = a[i];
            i++;
        }
        else if(a[i] == b[j])
        {
            temp_cmp = strcmp(&(a[i]), &(b[j]));
            if(temp_cmp == 0)
            {
                res[i + j] = a[i];
                i++;
            }
            else if(temp_cmp < 0)
            {
                res[i + j] = a[i];
                i++;
            }
            else
            {
                res[i + j] = b[j];
                j++;
            }
            
        }
        else
        {
            res[i + j] = b[j];
            j++;
        }
    }
    
    while(i < a_len)
    {
        res[i + j] = a[i];
        i++;
    }
    
    while(j < b_len)
    {
        res[i + j] = b[j];
        j++;
    }
    
    res[i + j] = '\0';
    
    return res;
}

int main()
{

    char* a = (char *)malloc(sizeof(char) * strlen("Jack."));
    strcpy(a, "JACK");
    
    char* b = (char *)malloc(sizeof(char) * strlen("DANIEL."));
    strcpy(b, "DANIEL");

    char* result = morganAndString(a, b);

    printf("%s\n", result);


    return 0;
}
