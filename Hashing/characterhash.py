val = str(input("Enter the string"))

hashArr = [0] * 27


for i in val:
    hashArr[ord(i)-ord('a')] += 1 # ord() returns the ASCII value

# q = list(input("Enter the queries"))
q = int(input("Enter the query length"))
res = [0]*q
for j in range(q):
    n = str(input())
    print(n, ord(n))
    res[j] = (hashArr[ord(n)-ord('a')])
    # print(hashArr[ord(n)-ord('a')])

print(res)

print(hashArr)