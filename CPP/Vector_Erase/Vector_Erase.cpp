#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	
    int length;
    std::vector<int> values;
    int x;
    int a, b;
    int i;
    int temp;
    
    std::cin >> length;
    
    for(i = 0; i < length; i++)
    {
        std::cin >> temp;
        values.push_back(temp);
    }
    
    std::cin >> x;
    std::cin >> a >> b;
    
    values.erase(values.begin() + x - 1);
    
    values.erase(values.begin() + a - 1, values.begin() + b - 1);
    
    std::cout << values.size()<<endl;
    
    for(std::vector<int>::iterator it = values.begin(); it != values.end(); it++)
    {
        std::cout << *it << " ";
    }
     
    return 0;
}
