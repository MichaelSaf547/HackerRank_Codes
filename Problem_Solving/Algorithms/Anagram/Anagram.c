#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int anagram(char* s) {
    
    if(strlen(s) % 2 == 1)
    {
        return -1;
    }
    else
    {
        int res = 0;
        int mid = strlen(s) >> 1;
        int arr_first [26] = {0};
        int arr_second [26] = {0};
        int i = 0;        
        
        while(s[i + mid] != '\0')
        {
            arr_first[s[i] - 'a']++; // if s[i] == 'a' --> s[i] - 'a' = 0 --> index zero and so on.
            arr_second[s[i + mid] - 'a']++;
            i++;
        }
        
        for(i = 0; i < 26; i++)
        {
            if(arr_second[i] > arr_first[i])
            {
                res += arr_second[i] - arr_first[i];
            }
        }
        
        return res;
    } 
}


int main()
{
    char s[] = "fdhlvosfpafhalll";

    int result = anagram(s);

    printf("%d\n", result);
    return 0;
}
