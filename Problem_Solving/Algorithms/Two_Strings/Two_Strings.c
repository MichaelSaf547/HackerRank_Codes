
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* twoStrings(char* s1, char* s2) {
    int res_flag = 0;
    char* res = NULL;
    char i[] = "a";
    
    while(i[0] <= 'z')
    {
        if(strstr(s1, i) != NULL && strstr(s2, i) != NULL)
        {
            res_flag = 1;
            break;
        }
        i[0] = i[0] + 1;
    }
    
    if(res_flag == 0)
    {
        res = (char *)malloc(sizeof(char) * 3);
        strcpy(res, "NO");
    }
    else
    {
        res = (char *)malloc(sizeof(char) * 4);
        strcpy(res, "YES");
    }
    
    return res;
}

int main()
{

    char s1[] = "wouldyoulikefries";

    char s2[] = "abcabcabcabcabcabc";

    char* result = twoStrings(s1, s2);

    printf("%s\n", result);

    return 0;
}

