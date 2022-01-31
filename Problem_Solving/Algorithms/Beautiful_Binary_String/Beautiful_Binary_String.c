

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int beautifulBinaryString(char* b) {
int res = 0;
    int i = 0;
    int step = 0;
    
    while(b[i] != '\0')
    {
        if(b[i] == '0' && step == 0)
        {
            step++;
        }
        else if(b[i] == '0' && step == 2)
        {
            res += 1;
            step = 0;
        }
        else if(b[i] == '1' && step == 1)
        {
            step = 2;
        }
        else if(b[i] == '1' && step == 2)
        {
            step = 0;
        }
        i++;
        
    }
    
    return res;
}

int main()
{

    char b[] = "0100101010";

    int result = beautifulBinaryString(b);

    printf("%d\n", result);


    return 0;
}
