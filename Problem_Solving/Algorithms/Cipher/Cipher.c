
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* cipher(int k, char* s) {
    int s_len = strlen(s);
    int len = s_len - k + 1;
    char * res = (char *)malloc(sizeof(char) * (len + 1));
    int temp_res = 0;
    int i = 0;
    int j = 0;
    
    res[len - 1] = s[s_len - 1];
    temp_res = (s[s_len - 1] - '0');
    
    res[len] = '\0';
    
    for(i = len - 2; i >= 0; i--)
    {
        if((len - i) < k)
        {
            j = 0;
            
            temp_res ^= (s[i + k - 1] - '0');
            
            res[i] = temp_res + '0';
            
            temp_res ^= (s[i + k - 1] - '0');
            
            temp_res ^= (res[i] - '0');
            
        }   
        else
        {
            j = 0;
            temp_res = 0;
            while(j < k - 1)
            {
                temp_res ^= (res[i + k - 1 - j] - '0');
                j++;
            }
            temp_res ^= (s[i + k - 1] - '0');
            
            res[i] = temp_res + '0';
        } 
        
    }
    
    return res;
}

int main()
{
    int k = 4;
    
    char* s = "1110100110";

    char* result = cipher(k, s);        //1001010

    printf("%s\n", result);
    
    k = 3;
    
    s = "1110011011";

    result = cipher(k, s);        //10000101

    printf("%s\n", result);

    return 0;
}

