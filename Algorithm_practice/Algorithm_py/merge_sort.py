arr = [3, 4, 2, 5, 1]

def merge(data, init, middle, finish):
    sorted = []
    i = init
    j = middle+1
    while i <= middle and  j <= finish: # 절반 기준으로 i나 j가 절반이나 끝을 넘어가지 않는다면
        if data[i] <= data[j]: # 만약 i번째 데이터가 j번째 데이터보다 작으면 i를 먼저 배열에 넣기
            sorted.append(data[i])
            i += 1
        else:
            sorted.append(data[j]) # j 데이터가 i데이터 보다 작으면 j데이터를 넣기
            j += 1 # 현재 j 는 넣고, 같은 i에게 현재 j를 비교!
    
    sorted.extend(data[i:middle+1])
    sorted.extend(data[j:finish+1])
    # 위 while 조건문에서 끝나는 이유가 i= middle+1 이므로
    # 위처럼 슬라이싱하면 둘 중 하나는 아무것도 추가되지 않는다.
    
    for idx, val in enumerate(sorted):
        data[init + idx] = val

def mergeSort(data, init, finish):
    if init < finish:
        middle = (init+finish)//2
        mergeSort(data, init, middle)
        mergeSort(data, middle+1, finish)
        merge(data, init, middle, finish)
    
mergeSort(arr, 0, len(arr)-1)
print(arr)

