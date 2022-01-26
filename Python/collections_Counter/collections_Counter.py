from collections import Counter

nub_shoes = int(input())

shoe_list = Counter(input().split())

num_cus = int(input())
res = 0
for i in range(num_cus):
    size,price = input().split()
    if size in shoe_list.keys():
        res += int(price)
        if shoe_list[size] == 1:
            del shoe_list[size]
        else:
            shoe_list[size] = shoe_list[size] - 1

print(res)
