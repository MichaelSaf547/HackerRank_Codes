
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stringConstruction(char* s) {
    int res = 0;
    int i = 0;
    char temp[26] = {0};
    
    while(s[i] != '\0')
    {
        temp[(s[i] - 'a')] = 1;
        i++;
    }
    
    for(i = 0; i < 26; i++)
    {
        if(temp[i] != 0)
        {
            res++;
        }
    }
    
    return res;
}

int main()
{
    char* s = "baab";

    int result = stringConstruction(s);

    printf("%d\n", result);
    
    s = "abcd";

    result = stringConstruction(s);

    printf("%d\n", result);
    
    s = "abbababgd";

    result = stringConstruction(s);

    printf("%d\n", result);

    return 0;
}

