class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        # create a list of pairs (row index, number of soldiers)
        pairs = []
        for i, row in enumerate(mat):
            # count the number of soldiers in each row
            soldiers = 0
            for num in row:
                if num == 1:
                    soldiers += 1
                else:
                    break
            # append the pair to the list
            pairs.append((i, soldiers))
        
        # sort the list by the number of soldiers, then by the row index
        pairs.sort(key=lambda x: (x[1], x[0]))
        
        # return the first k row indices from the sorted list
        return [x[0] for x in pairs[:k]]

""" 
The time complexity of this solution is O(m * n + m * log m), where m is the number of rows and n is the number of columns in the matrix. This is because we need to iterate over each element in the matrix to count the soldiers, which takes O(m * n) time, and then we need to sort the list of pairs, which takes O(m * log m) time.

The space complexity of this solution is O(m), where m is the number of rows in the matrix. This is because we need to store the list of pairs, which has m elements.

Some keynotes or gatchas for this problem are:

We can assume that the matrix is not empty and has valid dimensions, as stated in the constraints.
We can use a built-in function like sum or bisect to count the soldiers or find the first zero in each row, which might improve the readability or performance of the code.
We can use a heap or a priority queue to store the k weakest rows instead of sorting the entire list, which might reduce the time complexity to O(m * n + m * log k).


 """