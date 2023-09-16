class Solution(object):
    def minimumEffortPath(self, heights):
        m, n = len(heights), len(heights[0])
        dist = [[math.inf] * n for _ in range(m)]
        dist[0][0] = 0
        minHeap = [(0, 0, 0)] # distance, row, col
        DIR = [0, 1, 0, -1, 0]

        while minHeap:
            d, r, c = heappop(minHeap)
            if d > dist[r][c]: continue  # this is an outdated version -> skip it
            if r == m - 1 and c == n - 1:
                return d  # Reach to bottom right
            
            for i in range(4):
                nr, nc = r + DIR[i], c + DIR[i+1]
                if 0 <= nr < m and 0 <= nc < n:
                    newDist = max(d, abs(heights[nr][nc] - heights[r][c]))
                    if dist[nr][nc] > newDist:
                        dist[nr][nc] = newDist
                        heappush(minHeap, (dist[nr][nc], nr, nc))


"""
Approach
    If we observe, this problem is to find the shortest path from a source cell (0, 0) to a destination cell (m-1, n-1). Here, total path cost is defined as maximum absolute difference in heights between two consecutive cells of the path.
    Thus, we could use Dijikstra's algorithm which is used to find the shortest path in a weighted graph with a slight modification of criteria for the shortest path, which costs O(E log V), where E is number of edges E = 4*M*N, V is number of veritices V = M*N

Complexity
    Time: O(ElogV) = O(M*N log M*N), where M <= 100 is the number of rows and N <= 100 is the number of columns in the matrix.
    Space: O(M*N)
 """