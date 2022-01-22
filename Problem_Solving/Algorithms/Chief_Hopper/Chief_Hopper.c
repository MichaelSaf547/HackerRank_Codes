
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int chiefHopper(int arr_count, int* arr) {
    
    int res = 0;
    int i = arr_count - 2;
    int sub = arr[arr_count - 1];
    int even_flag = 1;
    
    if(sub % 2 == 1)
    {
        even_flag = 0;
    }
    
    for(; i >= 0; i--)
    {
        
        sub = sub >> 1;
        sub += arr[i];
        
        if(even_flag == 1)
        {
            if(sub % 2 == 1)
            {
                even_flag = 0;
            }
        }
    }
    
    
    if(even_flag == 1)
    {
        res = (sub >> 1);
    }
    else
    {
        res = (sub >> 1) + 1;
    }
    
    
    return res;
}

int main()
{
    
    int n = 5;
    int arr[] = {3, 4, 3, 2, 4};
    
    int result = chiefHopper(n, arr);
    
    printf("%d\n", result);

    return 0;
}
