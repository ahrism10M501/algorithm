arr = [5, 10, 1, 8, 7, 6, 4, 3, 2, 9]

for idx in range(len(arr)-1):
    j = idx
    while(arr[j] > arr[j+1]):
        temp = arr[j]
        arr[j] = arr[j+1]
        arr[j+1] = temp
        print(arr, idx, j)
        j = j-1 if j!=0 else 0 # 예외처리
        
# 문제는 가장 첫 번째 숫자가 가장 작은 수여야만 한다.
