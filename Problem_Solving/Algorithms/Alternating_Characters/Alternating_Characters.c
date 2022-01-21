#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int alternatingCharacters(char* s) {
    int res = 0;
    int i = strlen(s) - 1;
    
    while(i != 0)
    {
        if(s[i] == s[i - 1])
        {
            i--;
            res++;
        }
        else
        {
            i--;
        }
    }
    
    return res; 
}

int main()
{
    char s1 [] = "ABABBAAB"; // 2
    char s2 [] = "AAABBB"; // 4
    char s3 [] = "ABBABBAA"; // 3
    
    printf("%d\n", alternatingCharacters(s1));
    printf("%d\n", alternatingCharacters(s2));
    printf("%d\n", alternatingCharacters(s3));
    
    return 0;
}
