
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char fing_char(char * s, char search)
{
    char res = 0;
    int i = 0;
    while(s[i] != '\0')
    {
        if(s[i] == search)
        {
            res = 1;
            break;
        }
        else
        {
            i++;
        }
    }
    
    return res;
}

int gemstones(int arr_count, char** arr) {
    
    int res = 0;
    char flags[26] = {0};
    int i = 0;
    int j = 0;
    int len_short_str = 1000;
    int temp_len = 0;
    int index_short = -1;
    
    for(i = 0; i < arr_count; i++)
    {
        temp_len = strlen(arr[i]);
        if(temp_len < len_short_str)
        {
            len_short_str = temp_len;
            index_short = i;
        }
        else
        {
            continue;
        }
    }
    
    i = 0;
    while(arr[index_short][i] != '\0')
    {
        
        if(flags[arr[index_short][i] - 'a'] == 0)
        {
            flags[arr[index_short][i] - 'a'] = 1;
            len_short_str = 1;
            for(j = 0; j < arr_count; j++)
            {
                if(j != index_short)
                {
                    temp_len = fing_char(arr[j], arr[index_short][i]);
                    if(temp_len == 1)
                    {
                        len_short_str++;
                    }
                    else 
                    {
                        break;
                    }
                }
            }
            if(len_short_str == arr_count)
            {
                res += 1;
            }
            i++;
        }
        else
        {
            i++;
        } 
    }
    
    return res;
}

int main()
{
    
    int n = 3;
    int len = 0;
    int i = 0;
    char **arr;
    
    printf("Enter the number of strings: ");
    scanf("%d", &n);
    
    
    arr = (char **)malloc(sizeof(char *) * n);
    
    for(i = 0; i < n; i++)
    {
        printf("Enter the length of string %d: ", (i+1));
        scanf("%d", &len);
        arr[i] = (char *)malloc(sizeof(char) * len);
    }
    
    for(i = 0; i < n; i++)
    {
        printf("Enter string %d: ", (i + 1));
        scanf("%s", arr[i]);
    }
    
    
    int result = gemstones(n, arr);

    printf("%d\n", result);

    

    return 0;
}

