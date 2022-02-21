
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void change(int * ptr, int len, int change_num, int change_with)
{
    int i = 0;
    for(i = 0; i < len; i++)
    {
        if(ptr[i] == change_num)
        {
            ptr[i] = change_with;
            break;
        }
    }
}
 
int* largestPermutation(int k, int arr_count, int* arr, int* result_count) {
    
    int i = 0;
    int key = arr_count;
    
    for(i = arr_count; (i > 0) && k > 0; i--)
    {
        if(arr[arr_count - i] != key)
        {
            change(&(arr[arr_count - i]), i, key, arr[arr_count - i]);
            arr[arr_count - i] = key;
            k--;
            key--;
        }
        else
        {
            key--;
        }
    }
    
    *result_count = arr_count;
    return arr;
}

int main()
{
    int k = 2;
    int n = 5;
    int arr[] = {4, 2, 3, 5, 1};
    int result_count;
    int* result = largestPermutation(k, n, arr, &result_count); // 5 4 3 2 1

    for (int i = 0; i < result_count; i++) {
        printf("%d", *(result + i));

        if (i != result_count - 1) {
            printf(" ");
        }
    }

    printf("\n");
    return 0;
}

