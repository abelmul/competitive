# User function Template for python3


class Solution:
    def select(self, arr, length, i):
        # code here
        min_index = i
        for i in range(i, length):
            if arr[min_index] > arr[i]:
                min_index = i
        return min_index

    def selectionSort(self, arr, n):
        # code here
        for i in range(n):
            min_index = self.select(arr, n, i)
            arr[i], arr[min_index] = arr[min_index], arr[i]

        return arr


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        Solution().selectionSort(arr, n)
        for i in range(n):
            print(arr[i], end=" ")
        print()
# } Driver Code Ends
