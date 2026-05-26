def twoSum(nums, target):
    seen = {}
    for i, num in enumerate(nums):
        complement = target - num
        if complement in seen:
            print(seen, complement)
            return [seen[complement], i]
        seen[num] = i
    # return res

# [2,7,11,15]
# 9

# [3,2,3]
# 6
num = int(input("Enter array size: "))
arr = []
for i in range(num):
    arr.append(int(input()))
target = int(input("Enter the target value"))

print(twoSum(arr,target))