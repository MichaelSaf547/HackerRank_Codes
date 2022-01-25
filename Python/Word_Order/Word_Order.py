
num_str = int(input())

str_dict = {}
for i in range(num_str):
    temp_str = input()
    if temp_str not in str_dict.keys():
        str_dict[temp_str] = 1
    else:
        str_dict[temp_str] += 1
        
print(len(str_dict))        
for ele in str_dict:
    print(str_dict[ele], end = ' ')