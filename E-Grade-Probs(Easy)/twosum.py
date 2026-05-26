def twoSum(nums, target):
    # res = [0]*2
    for i in range(len(nums)):
        for j in range(i+1,len(nums)):
            if(nums[i]+nums[j]==target):
                return [i,j]
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