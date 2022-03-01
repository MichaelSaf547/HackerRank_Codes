#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

/*
 * Complete the 'sansaXor' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int sansaXor(int arr_count, int* arr) {
    int res = 0;
    if((arr_count & 1) == 0)
    {
        res = 0;
    } 
    else
    {
        int i = 0;
        for(i = 0; i < arr_count; i += 2)
        {
            res ^= arr[i];
        }
    }
    return res;
}

int main()
{

    int n = 4;

    int arr [] = {4, 5, 7, 5};

    int result = sansaXor(n, arr);              // 0

    printf("%d\n", result);
    
    n = 3;

    int arr2 [] = {98, 74, 2};                  // 96

    result = sansaXor(n, arr2);

    printf("%d\n", result);
    
    n = 5;

    int arr3 [] = {98, 74, 2, 120, 6};          // 102

    result = sansaXor(n, arr3);

    printf("%d", result);

    return 0;
}

