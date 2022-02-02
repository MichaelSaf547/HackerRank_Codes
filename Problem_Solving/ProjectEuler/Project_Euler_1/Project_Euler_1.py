

import sys

t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    temp_3 = (n - 1) // 3
    temp_5 = (n - 1) // 5
    temp_15 = (n - 1) // 15
    
    print((temp_3 * 3 * (temp_3 + 1) // 2) + (temp_5 * 5 * (temp_5 + 1) // 2) - (temp_15 * 15 * (temp_15 + 1) // 2))
