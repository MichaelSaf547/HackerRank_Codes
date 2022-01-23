
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int introTutorial(int V, int arr_count, int* arr) {
    int index = 0;
    
    for(index = 0; index < arr_count; index++)
    {
        if(V == arr[index])
        {
            break;    
        }
    }
    
    return index;
}

int main()
{
    int V = 4;
    
    int n = 6;
    
    int arr[] = {1, 4, 5, 7, 9, 12};
    
    int result = introTutorial(V, n, arr);

    printf("%d\n", result);

    return 0;
}
