
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int commonChild(char* s1, char* s2) {
    
    int res = 0;
    int s1_len = strlen(s1);
    
    int arr[2][s1_len + 1];
    int i = 0; 
    int j = 0;
    
    for(i = 0; i <= s1_len; i++)
    {
        for(j = 0; j <= s1_len; j++)
        {
            if(i == 0)
            {
                arr[0][j] = 0;
            }
            else if (j == 0)
            {
                arr[1][0] = 0;
            } 
            else if(s1[i - 1] == s2[j - 1]) // the -1 is that i have a row and column just for helping so i remove it from indexing
            {
                arr[i % 2][j] = arr[(i + 1) % 2][j - 1] + 1;
            }
            else
            {
                if(arr[i % 2][j - 1] > arr[(i + 1) % 2][j])
                {
                    arr[i % 2][j] = arr[i % 2][j - 1];
                }
                else
                {
                    arr[i % 2][j] = arr[(i + 1) % 2][j];
                }
            }
        }
    }
    
    return arr[(i - 1) % 2][s1_len];
    
}

int main()
{
    
    char s1[] = "SHINCHAN";

    char s2[] = "NOHARAAA";

    int result = commonChild(s1, s2);

    printf("%d\n", result);

    return 0;
}

