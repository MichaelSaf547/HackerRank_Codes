
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is copied from geeksforgeeks site

void getZarr(char * str, int *Z)
{
    int n = strlen(str);
    int L, R, k;
 
    // [L,R] make a window which matches with prefix of s
    L = R = 0;
    for (int i = 1; i < n; ++i)
    {
        // if i>R nothing matches so we will calculate.
        // Z[i] using naive way.
        if (i > R)
        {
            L = R = i;
 
            // R-L = 0 in starting, so it will start
            // checking from 0'th index. For example,
            // for "ababab" and i = 1, the value of R
            // remains 0 and Z[i] becomes 0. For string
            // "aaaaaa" and i = 1, Z[i] and R become 5
            while (R<n && str[R-L] == str[R])
            {    
				R++;
			}
            
			Z[i] = R-L;
            R--;
        }
        else
        {
            // k = i-L so k corresponds to number which
            // matches in [L,R] interval.
            k = i-L;
 
            // if Z[k] is less than remaining interval
            // then Z[i] will be equal to Z[k].
            // For example, str = "ababab", i = 3, R = 5
            // and L = 2
            if (Z[k] < R-i+1)
			{
				Z[i] = Z[k];
			}
			
            // For example str = "aaaaaa" and i = 2, R is 5,
            // L is 0
            else
            {
                // else start from R and check manually
                L = i;
                while (R<n && str[R-L] == str[R])
				{
					R++;
				}
                Z[i] = R-L;
                R--;
            }
        }
    }
}


long stringSimilarity(char* s) {
    long res = 0; 
    int i = 1;
    int len = strlen(s);
    res = len;
    
    int ptr[len];
    
    getZarr(s, ptr);
    
   
    for(i = 1; i < len; i++)
    {
        res += ptr[i];
    }
    
    
    return res;
}

int main()
{
    char s[] = "aaaaaa"; // 6 + 5 + 4 + 3 + 2 + 1 = 21

    long result = stringSimilarity(s);

    printf("%ld\n", result);
    
    char s2[] = "ababaa"; // 6 + 0 + 3 + 0 + 1 + 1 = 11

    result = stringSimilarity(s2);

    printf("%ld\n", result);

    return 0;
}



/*Above main*/


/*
int compare_F(char * compare, char * to_compare)
{
    int res = 0;
    int i = 0;
    
    while(compare[i] != '\0')
    {
        if(compare[i] == to_compare[i])
        {
            res++;
            i++;
        }
        else
        {
            break;
        }
    }
    return res;
}
*/


/*Inside main*/

 /*
while(s[i] != '\0')
{
	while(s[i + s_step] == s[s_step])
	{
		res += 1;
		s_step++;    
	}
	s_step = 0;
	i++;
}
*/