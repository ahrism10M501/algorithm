arr = [1, 10, 5, 8 , 7, 6, 4, 3, 2, 9]
idx = 0

for i, num1 in enumerate(arr):
    min = 11
    for j, num2 in enumerate(arr[i:]):
        if min > num2: # 가장 작은 값 찾기
            min = num2
            idx = i+j

    temp = num1 # 서로 위치 바꾸기
    arr[i] = min
    arr[idx] = temp

print(arr)

# 시간 복잡도, 10+ 9+ 8+ 7 ... +1 = 10*(10+1)/2 -> N*(N+1)/2 -> O(N*N)