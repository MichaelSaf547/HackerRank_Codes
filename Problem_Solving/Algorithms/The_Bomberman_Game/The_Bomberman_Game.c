#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bomberMan_3(int grid_count, char** grid)
{
    int i = 0;
    int j = 0;
    
    for(i = 0; i < grid_count; i++)
    {
        j = 0;
        while(grid[i][j] != '\0')
        {
            if(grid[i][j] == 'O')
            {
                if(grid_count == 1)
                {
                    if(strlen(grid[0]) == 1)
                    {
                        grid[i][0] = 'x';
                        
                    }
                    else if(j == 0)
                    {
                        if(grid[0][1] != 'O')
                        {
                            grid[0][1] = 'x';
                        }
                        grid[i][j] = 'x';
                    }
                    else if(grid[0][j+1] == '\0')
                    {
                        grid[0][j - 1] = 'x';
                        grid[i][j] = 'x';
                    }
                    else
                    {
                        if(grid[0][j + 1] != 'O')
                        {
                            grid[0][j + 1] = 'x';    
                        }
                        if(grid[0][j - 1] != 'O')
                        {
                            grid[0][j - 1] = 'x';    
                        }
                        grid[i][j] = 'x';
                    }
                }
                else if(i == 0)
                {
                    if(strlen(grid[0]) == 1)
                    {
                        grid[i][0] = 'x';
                        if(grid[1][0] != 'O')
                        {
                            grid[1][0] = 'x';
                        }
                    }
                    else if(j == 0)
                    {
                        if(grid[0][1] != 'O')
                        {
                            grid[0][1] = 'x';
                        }
                        if(grid[1][0] != 'O')
                        {
                            grid[1][0] = 'x';
                        }
                        grid[i][j] = 'x';
                    }
                    else if(grid[0][j+1] == '\0')
                    {
                        grid[0][j - 1] = 'x';
                        if(grid[1][j] != 'O')
                        {
                            grid[1][j] = 'x';    
                        }
                        grid[i][j] = 'x';
                    }
                    else
                    {
                        if(grid[0][j + 1] != 'O')
                        {
                            grid[0][j + 1] = 'x';    
                        }
                        if(grid[0][j - 1] != 'O')
                        {
                            grid[0][j - 1] = 'x';    
                        }
                        if(grid[1][j] != 'O')
                        {
                            grid[1][j] = 'x';
                        }
                        grid[i][j] = 'x';
                    }
                }
                else if(i == grid_count - 1)
                {
                    if(strlen(grid[0]) == 1)
                    {
                        grid[i][0] = 'x';
                    }
                    else if(j == 0)
                    {
                        if(grid[i][1] != 'O')
                        {
                            grid[i][1] = 'x';    
                        }
                        grid[i - 1][0] = 'x';
                        grid[i][j] = 'x';
                    }
                    else if(grid[0][j+1] == '\0')
                    {
                        grid[i][j - 1] = 'x';
                        grid[i - 1][j] = 'x';
                        grid[i][j] = 'x';
                    }
                    else
                    {
                        if(grid[i][j + 1] != 'O')
                        {
                            grid[i][j + 1] = 'x';    
                        }
                        if(grid[i][j - 1] != 'o')
                        {
                            grid[i][j - 1] = 'x';    
                        }
                        
                        grid[i - 1][j] = 'x';
                        grid[i][j] = 'x';
                    }
                }
                else
                {
                    if(strlen(grid[0]) == 1)
                    {
                        grid[i][0] = 'x';
                        grid[i - 1][0] = 'x';
                        if(grid[i + 1][0] != 'O')
                        {
                            grid[i + 1][0] = 'x';
                        }
                    }
                    else if(j == 0)
                    {
                        if(grid[i][j + 1] != 'O')
                        {
                            grid[i][j + 1] = 'x';    
                        }
                        if(grid[i + 1][j] != 'O')
                        {
                            grid[i + 1][j]= 'x';    
                        } 
                        grid[i - 1][j] = 'x';
                        grid[i][j] = 'x';
                    }
                    else if(grid[0][j+1] == '\0')
                    {
                        if(grid[i][j - 1] != 'O')
                        {
                            grid[i][j - 1] = 'x';    
                        }
                        if(grid[i + 1][j] != 'O')
                        {
                            grid[i + 1][j]= 'x';    
                        }
                        grid[i - 1][j] = 'x';
                        grid[i][j] = 'x';
                    }
                    else
                    {
                        if(grid[i + 1][j] != 'O')
                        {
                            grid[i + 1][j] = 'x';
                        }
                        if(grid[i][j + 1] != 'O')
                        {
                            grid[i][j + 1] = 'x';
                        }
                        grid[i - 1][j] = 'x';
                        grid[i][j - 1] = 'x';
                        grid[i][j] = 'x';
                        
                    }
                }
            }
            
            j++;
            
        }
    }
    
    for(i = 0; i < grid_count; i++)
    {
        j = 0;
        while(grid[i][j] != '\0')
        {
            if(grid[i][j] == '.')
            {
                grid[i][j] = 'O'; 
            }
            else if(grid[i][j] == 'x')
            {
                grid[i][j] = '.';
            }
            j++;
        }
    }
    
} 

void bomberMan_a(int grid_count, char** grid)
{
    int i = 0;
    int j = 0;
    
    for(i = 0; i < grid_count; i++)
    {
        j = 0;
        while(grid[i][j] != '\0')
        {
            grid[i][j] = 'O';
            j++;
        }
    }
}

char** bomberMan(int n, int grid_count, char** grid, int* result_count) {
    
    if((n % 2) == 0)
    {
        bomberMan_a(grid_count, grid);
    }
    else
    {
        if(n == 1)
        {
            // Do nothing
        }    
        else
        {
            if((n % 4) == 1)
            {
                bomberMan_3(grid_count, grid);
                bomberMan_3(grid_count, grid);
            }
            else if((n % 4) == 3)
            {
                bomberMan_3(grid_count, grid); 
            }
        }
    }
    
    
    *result_count = grid_count;
    return grid;
}

int main()
{
    
    int r = 6;

    int c = 7;

    int n = 3;
    
    int  i = 0;
    
    char** grid = malloc(r * sizeof(char*));

    for (i = 0; i < r; i++) {
        grid[i] = (char* )malloc(sizeof(char) * (c + 1));
    }
    
    strcpy(grid[0], ".......");
    strcpy(grid[1], "...O...");
    strcpy(grid[2], "....O..");
    strcpy(grid[3], ".......");
    strcpy(grid[4], "OO.....");
    strcpy(grid[5], "OO.....");

    int result_count;
    grid = bomberMan(n, r, grid, &result_count);

    for (int i = 0; i < result_count; i++) {
        printf("%s", *(grid + i));

        if (i != result_count - 1) {
            printf("\n");
        }
    }

    printf("\n");
    
    for(i = 0; i < r; i++)
    {
        free(grid[i]);
    }
    free(grid);
    
    return 0;
}

