if __name__ == '__main__':
    N = int(input())
    List = []
    
    for i in range(N):
        temp = input().split()
        if temp[0] == 'append':
            List.append(int(temp[1]))
        elif temp[0] == 'insert':
            List.insert(int(temp[1]), int(temp[2]))
        elif temp[0] == 'print':
            print(List)
        elif temp[0] == 'remove':
            List.remove(int(temp[1]))
        elif temp[0] == 'sort':
            List.sort()
        elif temp[0] == 'reverse':
            List.reverse();
        elif temp[0] == 'pop':
            List.pop();
        else:
            print('Wrong input')