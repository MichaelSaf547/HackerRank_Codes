
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* pangrams(char* s) {
    char * res;
    int flag = 1;
    char arr[26] = {0};
    int i = 0;
    
    while(s[i] != '\0')
    {
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            arr[s[i] - 'a']++;
        }
        else if(s[i] == ' ')
        {
            //Do Nothing
        }
        else
        {
            arr[s[i] - 'A']++;
        }
        i++;
    }
    
    for(i = 0; i < 26; i++)
    {
        if(arr[i] == 0)
        {
            flag = 0;
            break;
        }
        else
        {
            //Do nothing
        }
    }
    
    if(flag == 0)
    {
        res = (char *)malloc(sizeof(char) * strlen("not pangram."));
        strcpy(res, "not pangram");
    }
    else
    {
        res = (char *)malloc(sizeof(char) * strlen("pangram."));
        strcpy(res, "pangram");
    }
    
    return res;
}


int main()
{
    char s1[] = "We promptly judged antique ivory buckles for the next prize";      // pangram
    char s2[] = "We promptly judged antique ivory buckles for the prize";           // not pangram

    char* result1 = pangrams(s1);
    char* result2 = pangrams(s2);

    printf("%s\n", result1);
    printf("%s\n", result2);

    return 0;
}
