arr = [3, 5, 4, 6, 7, 2, 8, 1]

# 최대 힙 구조로 arr 배치하기
for idx in range(1, len(arr)):
    com = idx
    while True:
        root = (com-1)//2
        
        if arr[root] < arr[com]:
            arr[root], arr[com] = arr[com], arr[root]
        
        com = root
    
        if root==0:
            break

for idx in range(0, len(arr))[::-1]:
    arr[0], arr[idx] = arr[idx], arr[0]
    # 최상위를 가장 아래로! -> 그다음 최상위는 (아래-1) -> 그다음 최상위는 (아래-2) 이걸 반복하여 정렬!
    root = 0
    com = 1
    while True:
        com = 2*root+1 # 루트의 두 자식 중 첫째의 위치
        # 첫째와 둘째 비교. com < idx-1 은 out of index 방지
        if com < idx-1 and arr[com] < arr[com+1]:
            com += 1
        
        # 첫째와 둘째 중 더 큰 녀석과 root의 위치를 바꾼다
        if  com < idx and arr[root] < arr[com]:
            arr[root], arr[com] = arr[com], arr[root]
    
        root = com
        
        if(com > idx):
            break

print(arr)