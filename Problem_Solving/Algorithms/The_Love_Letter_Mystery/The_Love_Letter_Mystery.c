
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int theLoveLetterMystery(char* s) {
    int i = 0;
    int res = 0;
    int len = strlen(s);
    int mid = len >> 1;
    
    while(i < mid)
    {
        res += abs(s[i] - s[len - 1 - i]);
        i++;
    }
    
    return res;
}

int main()
{
    char s[] = "cba";           //2
    char s2[] = "adslkfjas";    //36
    int result = theLoveLetterMystery(s);

    printf("%d\n", result);
    
    result = theLoveLetterMystery(s2);

    printf("%d\n", result);

    return 0;
}
