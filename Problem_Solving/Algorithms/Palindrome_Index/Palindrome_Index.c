
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int palindromeIndex(char* s) {
    int i = 0;
    int res = -1;
    int len = strlen(s);
    int mid = len >> 1;
     
    while(i < mid)
    {
        if(s[i] != s[len - 1 - i])
        {
            if(s[i] == s[len - 2 - i] && s[i + 2] != s[len - 2 - i])
            {
                res = len - 1 - i;
                break;
            }
            
            else if(s[i + 1] == s[len - 1 - i])
            {
                res = i;
                break;
            }
            
            else if(s[i] == s[len - 2 - i])
            {
                res = len - 1 - i;
                break;
            }
            
        }
        i++;
    }
     
    
    return res;
}

int main()
{
    char s[] = "hgygsvlfwcwnswtuhmyaljkqlqjjqlqkjlaymhutwsnwcflvsgygh";     //8

    int result = palindromeIndex(s);

    printf("%d\n", result);
    
    return 0;
}


