#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* nimGame(int pile_count, int* pile) {
    
    char * res;
    int i = 0;
    int sum = 0;
    
    for(i = 0; i < pile_count; i++)
    {
        sum ^= pile[i];
    }
    
    if(sum != 0)
    {
        res = (char *)malloc(sizeof(char) * strlen("first."));
        strcpy(res, "First");
    }
    else
    {
        res = (char *)malloc(sizeof(char) * strlen("second."));
        strcpy(res, "Second");
    }
    
    return res;
}

int main()
{
    int n = 4;
    int pile[] = {1, 3, 5, 7};
    
    char* result = nimGame(n, pile); // Second

    printf("%s\n", result);
    return 0;
}
