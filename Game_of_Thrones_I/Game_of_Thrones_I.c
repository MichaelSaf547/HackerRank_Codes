#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* gameOfThrones(char* s) {
    int len = strlen(s);
    char * res;
    int flag1 = 0;
    int i = 0;
    int arr[26] = {0};
    
    while(s[i] != '\0')
    {
        arr[s[i] - 'a']++;
        i++;
    }
    
    if(len % 2 == 0)
    {
        for(i = 0; i < 26; i++)
        {
            if(arr[i] % 2 == 1)
            {
                flag1 = 2;
                break;
            }
        }    
        if(flag1 == 0)
        {
            flag1 = 1;
        }
    }
    else
    {
        for(i = 0; i < 26; i++)
        {
            if(arr[i] % 2 == 1)
            {
                if(flag1 == 1)
                {
                    flag1 = 2;
					break;
                }
                else if(flag1 == 0)
                {
                    flag1 = 1; 
                }
            }
        }
    }
    
    if(flag1 != 1)
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
	char test1[] = "aaabbbb"; 			//YES
	char test2[] = "cdefghmnopqrstuvw";	//NO
	char test3[] = "cdcdcdcdeeeef";		//YES
	char test4[] = "jjhhggff";			//YES
	
    char* result1 = gameOfThrones(test1);
    char* result2 = gameOfThrones(test2);
    char* result3 = gameOfThrones(test3);
    char* result4 = gameOfThrones(test4);

    printf("%s\n", result1);
	printf("%s\n", result2);
	printf("%s\n", result3);
	printf("%s\n", result4);

    return 0;
}

