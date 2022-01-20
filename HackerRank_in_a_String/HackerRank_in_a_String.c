#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* hackerrankInString(char* s) {
    int flag = 0;
    int i = 0;
    char * res;
    char test[11] = "hackerrank";
    int test_index = 0;
    while(flag == 0 && s[i] != '\0')
    {
        if(s[i] == test[test_index])
        {
            test_index++;
        }
        if(test_index == 10)
        {
            flag = 1;
        }
        i++;
    }
    
    if(flag == 0)
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
	char s[] = "hereiamstackerrank"; 	//YES
	char t[] = "hackerworld";			//NO

	char* result1 = hackerrankInString(s);
	char* result2 = hackerrankInString(t);

	printf("%s\n", result1);
	printf("%s\n", result2);

    return 0;
}

