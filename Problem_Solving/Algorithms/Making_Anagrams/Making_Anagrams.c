
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int makingAnagrams(char* s1, char* s2) {
    int arr1[26] = {0};
    int arr2[26] = {0};
    int i = 0;
    int res = 0;
    
    while(s1[i] != '\0')
    {
        arr1[s1[i] - 'a']++;
        i++;
    }
    
    i = 0;
    while(s2[i] != '\0')
    {
        arr2[s2[i] - 'a']++;
        i++;
    }
    
    for(i = 0; i < 26; i++)
    {
        if(arr1[i] != arr2[i])
        {
            res += abs(arr2[i] - arr1[i]);
        }
    }
    
    return res;
}

int main()
{
    char s1[] = "absdjkvuahdakejfnfauhdsaavasdlkj";
    
    char s2[] = "djfladfhiawasdkjvalskufhafablsdkashlahdfa";
    
    int result = makingAnagrams(s1, s2);

    printf("%d\n", result);

    return 0;
}
