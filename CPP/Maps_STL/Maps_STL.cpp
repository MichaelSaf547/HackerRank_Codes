#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    std::map<string, int> students;
    int N;
    int i;
    int temp;
    string name;
    int res;
    
    std::cin >> N;
    
    for(i = 0; i < N; i++)
    {
        std::cin >> temp;
        switch(temp)
        {
            case 1:
            {
                std::cin >> name >> res;
                std::map<string, int>::iterator it;
                it = students.find(name);
                if(it == students.end())
                {
                    students.insert(make_pair(name, res));
                }
                else
                {
                    students[name] += res;
                } 
                break;
            }
            case 2:
            {
                std::cin >> name;
                students.erase(name);
                break;
            }
            case 3: 
            {
                std::cin >> name;
                std::cout << students[name] << std::endl;
                break;
            }
        }
    }   
    return 0;
}

