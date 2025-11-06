# 오른쪽으로 작은 놈
# 왼쪽으로 큰 놈

arr =[3, 2, 1, 4, 7, 6, 10, 5, 8, 9]

for idx in range(len(arr)):
    i, j = 0, idx
    while(i<j):
        while(arr[idx]> arr[i]):
            i+=1
        while(arr[idx]< arr[j]):
            j-=1
        temp = arr[i]
        arr[i] = arr[j]
        arr[j] = temp
    temp = arr[idx]
    arr[idx] = arr[j]
    arr[j] = temp
    
print(arr)
