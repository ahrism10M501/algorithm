arr = [1, 10, 5, 8, 7, 6, 4, 3, 2, 9]

for idx in range(len(arr)):
    for idx2 in range(len(arr)-idx-1):
        if arr[idx2] > arr[idx2+1]:
            temp = arr[idx2+1]
            arr[idx2+1] = arr[idx2]
            arr[idx2] = temp

print(arr)