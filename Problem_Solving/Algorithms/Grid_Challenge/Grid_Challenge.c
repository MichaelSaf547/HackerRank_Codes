#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(char * ptr, char *left, char * right)
{
    int i = 0; 
    int j = 0;
    int left_len = strlen(left);
    int right_len = strlen(right);
    while(i < left_len && j < right_len)
    {
        if(left[i] < right[j])
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
    
    while(i < left_len)
    {
        ptr[i + j] = left[i];
        i++;
    }
    
    while(j < right_len)
    {
        ptr[i + j] = right[j];
        j++;
    }
} 

void mergesort(char * ptr)
{
    int len = strlen(ptr);
    if(len > 1)
    {
        int mid = len / 2 ;
        char * left = (char *)malloc(sizeof(char) * (mid + 1));
        char * right = (char *)malloc(sizeof(char) * (len - mid + 1));
        int i = 0;
        
        for(i = 0; i < mid; i++)
        {
            left[i] = ptr[i];
        }
        left[i] = '\0';
        
        for(i = 0; i < len - mid; i++)
        {
            right[i] = ptr[i + mid];
        }
        right[i] = '\0';
        
        mergesort(left);
        mergesort(right);
        
        merge(ptr, left, right);
        
        free(left);
        free(right);
    }
}
 
char* gridChallenge(int grid_count, char** grid) {
    
    char * res = NULL;
    int flag = 1;
    int i = 0;
    int col = 0;
    
    for(i = 0; i < grid_count; i++)
    {
        mergesort(grid[i]);
    }
    
    i = 0;
    while(grid[0][col] != '\0')
    {
        for(i = 0; i < grid_count - 1; i++)
        {
            if(grid[i][col] > grid[i + 1][col])
            {
                flag = 0;
                grid[0][col] = '\0';
            }        
        }
        col++;
    }
    
    if(flag == 1)
    {
        res = (char *)malloc(sizeof(char) * 4);
        strcpy(res, "YES");
    }
    else
    {
        res = (char *)malloc(sizeof(char) * 3);
        strcpy(res, "NO");
    }
    return res;
}

int main()
{
    char ** grid = (char **)malloc(sizeof(char *) * 5);
    int i = 0;
    for(i = 0; i < 5; i++)
    {
    
        grid[i] = (char *)malloc(sizeof(char) * 6);
    }
    
    strcpy(grid[0], "eabcd");
    strcpy(grid[1], "fghij");
    strcpy(grid[2], "olkmn");
    strcpy(grid[3], "trpqs");
    strcpy(grid[4], "xywuv");
        
    char* result = gridChallenge(5, grid);

    printf("%s\n", result);

    return 0;
}

