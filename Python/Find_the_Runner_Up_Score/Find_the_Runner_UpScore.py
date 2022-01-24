if __name__ == '__main__':
    n = int(input())
    arr = map(int, input().split())
    sortedlist = sorted(arr)
    runner_up = -101
    for i in range(-2, -len(sortedlist) - 1, -1):
        
        if sortedlist[i] < sortedlist[-1]:
            runner_up = sortedlist[i]
            break;  
    if(runner_up == -101):
      print('Not Found!')
    else:
      print(runner_up)