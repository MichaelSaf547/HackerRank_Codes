
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int superDigit(char* n, int k) {
    if(strlen(n) == 1)
    {
        return (n[0] - '0');
    }
    else
    {
        long sum = 0;
        int i = 0;
        char arr[20];
        while(n[i] != '\0')
        {
            sum += (n[i] - '0');
            i++;
        }
        sum *= k;
        sprintf(arr, "%ld", sum);
        return superDigit(arr, 1);
    }
}

int main()
{
    int k = 4;
    char n[] = "9785";
    int result = superDigit(n, k);

    printf("%d\n", result);

    return 0;
}

