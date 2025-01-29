// Disjoint Set Union (DSU)
class Solution {
    class DSU {
    private:
        int N;
        vector<int> size;
        vector<int> representative;

    public:
        // Initialize DSU class, size of each component will be one and each
        // node will be representative of it's own.
        DSU(int N) {
            this->N = N;

            for (int node = 0; node < N; node++) {
                size.push_back(1);
                representative.push_back(node);
            }
        }

        // Returns the ultimate representative of the node.
        int find(int node) {
            if (representative[node] == node) {
                return node;
            }

            return representative[node] = find(representative[node]);
        }

        // Returns true if nodeOne and nodeTwo belong to different component and
        // update the representatives accordingly, otherwise returns false.
        bool doUnion(int nodeOne, int nodeTwo) {
            nodeOne = find(nodeOne);
            nodeTwo = find(nodeTwo);

            if (nodeOne == nodeTwo) {
                return 0;
            } else {
                if (size[nodeOne] > size[nodeTwo]) {
                    representative[nodeTwo] = nodeOne;
                    size[nodeOne] += size[nodeTwo];
                } else {
                    representative[nodeOne] = nodeTwo;
                    size[nodeTwo] += size[nodeOne];
                }
                return 1;
            }
        }
    };

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();

        DSU dsu(N);
        for (auto edge : edges) {
            // If union returns false, we know the nodes are already connected
            // and hence we can return this edge.
            if (!dsu.doUnion(edge[0] - 1, edge[1] - 1)) {
                return edge;
            }
        }

        return {};
    }
};

/* 
Algorithm

    Define DSU (Disjoint Set Union):
        Initialize two arrays:
            size[] to store the size of each component (starts with 1 for each node).
            representative[] to track the representative (or root) of each component (initially, each node is its own representative).
            Find Operation (find):
                For each node, find its ultimate representative (root of the component).
                Path Compression: During the recursive search, update the representative of each visited node to directly point to the root, speeding up future lookups.
            Union Operation (doUnion):
                Check if the two nodes belong to the same component:
                If they already share the same representative, they are part of the same component, so adding this edge would form a cycle. Return false.
                If the nodes belong to different components, union them:
                Attach the smaller component to the larger one (union by size), ensuring the tree remains balanced to minimize depth.

    Iterate Through Edges:
        Process each edge in the list of edges:
            Convert the 1-based indices from the input to 0-based for array indexing.
            Use doUnion to attempt connecting the nodes of the edge.
            If doUnion returns false, it means adding this edge would form a cycle, so return the current edge as the redundant edge.

    If the input is valid, this part of the code should be unreachable. Return an empty list {} in such cases.

Complexity Analysis
    Here, N is the number of nodes and edges in the given graph.

    Time complexity: O(N⋅α(N))
        We iterate over all edges, and for each edge, we invoke the doUnion function, which has a time complexity of O(α(N)), given that both union by size and path compression 
        are employed. Consequently, the overall time complexity of the algorithm is O(N⋅α(N)). It is important to note that α(N) represents the inverse Ackermann function, 
        which grows so slowly that it is often considered asymptotically constant, or O(1).

    Space complexity: O(N)
        The list representative, used to store the representatives, and the list size, used to store the size of each component, will each contain N entries. Therefore, the total space complexity is O(N).
*/