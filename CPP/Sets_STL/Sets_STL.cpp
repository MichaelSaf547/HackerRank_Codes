#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    
    int length;
    int query;
    int digit;
    int i;
    std::set<int> setvalues;
    
    std::cin >> length;
    
    for(i = 0; i < length; i++)
    {
        std::cin >> query>>digit;
        
        switch (query) 
        {
            case 1:
            {
                setvalues.insert(digit);
                break;
            }
            case 2:
            {
                setvalues.erase(digit);
                break;
            }
            case 3:
            {
                std::set<int>::iterator it = setvalues.find(digit);
                if(it == setvalues.end())
                {
                    std::cout << "No"<<std::endl;
                }
                else 
                {
                    std::cout << "Yes" << std::endl;
                }
                break;
            }
        }
    }
       
    return 0;
}



