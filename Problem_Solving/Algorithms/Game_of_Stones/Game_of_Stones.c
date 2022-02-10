
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* gameOfStones(int n) {
    char arr[n];
    int i = 0;
    char * res;
    
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 1;
    arr[4] = 1;
    
    for(i = 5; i < n; i++)
    {
        if(arr[i - 2] && arr[i - 3] && arr[i - 5] == 1)
        {
            arr[i] = 0;
        }
        else
        {
            arr[i] = 1;
        }
    }
    
    if(arr[n - 1] == 0)
    {
        res = (char *)malloc(sizeof(char) * strlen("second."));
        strcpy(res, "Second");
    }
    else
    {
        res = (char *)malloc(sizeof(char) * strlen("first."));
        strcpy(res, "First");
    }
    return res;
}

int main()
{
    int t = 8;
    int n[8] = {1, 2, 3, 4, 5, 6, 7, 10};
    int i = 0;
    for(i = 0; i < t; i++)
    {
        printf("%s\n", gameOfStones(n[i]));    
    }
    
    return 0;
}
