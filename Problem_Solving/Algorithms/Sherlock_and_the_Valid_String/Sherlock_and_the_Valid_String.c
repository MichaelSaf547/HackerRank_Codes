
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void merge(int * ptr, int le_len, int *left, int righ_len, int *right)
{
    int i = 0;
    int j = 0;
    
    while(i < le_len && j < righ_len)
    {
        if(left[i] > right[j])
        {
            ptr[i + j] = left[i];
            i++;
        }
        else
        {
            ptr[i + j] = right[j];
            j++;
            
        }
    }
    
    while(i < le_len)
    {
        ptr[i + j] = left[i];
        i++;
    }
    
    while(j < righ_len)
    {
        ptr[i + j] = right[j];
        j++;
    }
} 
 
 
void mergesort(int * ptr, int size)
{
    if(size > 1)
    {
        int mid = size >> 1;
        int * left = (int *)malloc(sizeof(int) * mid);
        int * right = (int *)malloc(sizeof(int) * (size - mid));
        int i = 0;
        
        for(i = 0; i < mid; i++)
        {
            left[i] = ptr[i];
        }
        
        for(i = 0; i < size - mid; i++)
        {
            right[i] = ptr[i + mid];
        }
        
        mergesort(left, mid);
        mergesort(right, size - mid);
        
        merge(ptr, mid, left, size - mid, right);
        
        free(left);
        free(right);
    }
} 
 
char* isValid(char* s) {
    int res_flag = 1;
    int arr[26] = {0};
    char * res = NULL;
    int i = 0;
    int start = 0;
    int temp_start = 0;
    
    while(s[i] != '\0')
    {
        arr[s[i] - 'a']++;
        i++;
    }
    
    mergesort(arr, 26);
    
    start = arr[0];
    
    for(i = 1; i < 26; i++)
    {
        if(arr[i] == 0)
        {
            break;
        }
        else
        {
            if(start != arr[i])
            {
                if(start - arr[i] > 1)
                {
                    if((i == 25  || arr[i + 1] == 0) && arr[i] == 1)
                    {
                        //Do Nothing
                    }
                    else
                    {
                        res_flag = 0;
                        break;    
                    }
                    
                }
                else
                {
                    if(i == 1)
                    {
                        temp_start = 1;
                        start = arr[i];
						// if just the first element is higher, i reduce the start to the second element.
                    }    
                    else if(temp_start == 0)
                    {
                        temp_start = 1;
                    }
                    else if(temp_start == 1)
                    {
                        res_flag = 0;
                        break;
                    }
                }
            }
        }
    }
    
    if(res_flag == 0)
    {
        res = (char *)malloc(sizeof(char) * 3);
        strcpy(res, "NO");
    }
    else 
    {
        res = (char *)malloc(sizeof(char) * 4);
        strcpy(res, "YES");
    }
    return res;
}

int main()
{
    
    char* s = "abcdefghhgfedecba";  //YES 

    char* result = isValid(s);

    printf("%s\n", result);


    return 0;
}
