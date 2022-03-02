
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char** weightedUniformStrings(char* s, int queries_count, int* queries, int* result_count) {
    
    char ** res = (char **)malloc(sizeof(char *) * queries_count);
    int i = 0;
    int j = 0;
    int temp[26] = {0};
    int temp_value = 0;
    
    while(s[i] != '\0')
    {
        if(s[i] == s[i + 1])
        {
            temp_value++;   
        }
        else
        {
            temp_value++;
            if(temp_value > temp[(s[i] - 'a')])
            {
                temp[(s[i] - 'a')] = temp_value;
            }
            temp_value = 0;
        }
        i++;
    }
    
    for(i = 0; i < 26; i++)
    {
        temp[i] = temp[i] * (i + 1);
    }
    
    for(i = 0; i < queries_count; i++)
    {
        for(j = 1; j < 27; j++)
        {
            if((queries[i] % j == 0) && (queries[i] <= temp[j - 1]))
            {
                break;
            }
        }
        if(j == 27)
        {
            res[i] = (char *)malloc(sizeof(char) * 3);
            strcpy(res[i], "No");
        }
        else
        {
            res[i] = (char *)malloc(sizeof(char) * 4);
            strcpy(res[i], "Yes");
        }
    }

    *result_count = queries_count;

    return res;
}

int main()
{
    char* s = "abccddde";

    int queries_count = 6;

    int queries [] = {1, 3, 12, 5, 9, 10};

    int result_count;

    char** result = weightedUniformStrings(s, queries_count, queries, &result_count);

    for (int i = 0; i < result_count; i++) {
        printf("%s", *(result + i));

        if (i != result_count - 1) {
            printf("\n");
        }
    }

    return 0;
}

