
'''
Using Lomuto scheme to implement partition, 
or say Quick sort
https://rust-algo.club/sorting/quicksort/
Given a int pivot, return new array, 
those numbers smaller than pivot will be on the left side of pivot 
and bigger numbers be on the right side.
'''

def swap(arr, a, b):
    temp = arr[a]
    arr[a] = arr[b]
    arr[b] = temp
    return arr


def partition(arr, pivot):
    l = 0
    _len = len(arr)
    r = _len - 1
    for k in range(_len):
        if arr[k] == pivot:
            arr = swap(arr, k, r)   #pivot will be arr[r]
            break
            
    i = 0
    for j in range(_len):
        if arr[j] <= pivot:
            arr = swap(arr, i, j)
            i += 1
    
    arr = swap(arr, i, r)
    return arr






if __name__ == '__main__':
    arr = [3,2,1,5,6,4] 
    pivot = 3
    new_arr = partition(arr, pivot)
    print(new_arr)