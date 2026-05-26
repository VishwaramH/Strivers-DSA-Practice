def binarySearch(arr, search):
    low, high = 0, len(arr)-1

    while(low<=high):
        mid = (low+high)//2
        if(arr[mid]==search):
            return mid
        elif(arr[mid]<search):
            low = mid+1
        elif(arr[mid]>search):
            high = mid-1
    return -1

num = int(input("Enter array size: "))
arr = []
for i in range(num):
    arr.append(int(input()))
search = int(input("Enter the search value\n"))
print("Search element found in index: ",binarySearch(arr,search))