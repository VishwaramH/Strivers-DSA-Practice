# Function to count frequency of each element in the array
def countFreq(arr, n):
    # Create a visited list to mark elements that are already processed
    visited = [False] * n

    # Traverse through all elements of the array
    for i in range(n):
        # Skip this element if it's already processed
        if visited[i]:
            continue

        # Count the frequency of arr[i]
        count = 1
        for j in range(i + 1, n):
            if arr[i] == arr[j]:
                visited[j] = True  # Mark arr[j] as processed
                count += 1

        # Output the element and its count
        print(arr[i], count)

if __name__ == "__main__":
    # Input array
    arr = [10, 5, 10, 15, 10, 5]
    n = len(arr)

    # Call the function to count frequencies
    countFreq(arr, n)