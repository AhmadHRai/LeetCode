// This function takes four parameters: n, leftChild, rightChild, and validateBinaryTreeNodes
// The function returns true if the given input represents a valid binary tree with n nodes, and false otherwise
const validateBinaryTreeNodes = (n, left, right) => {
  // Create an array of size n and fill it with -1 values
  // This array will store the parent index of each node in the tree
  let parent = Array(n).fill(-1);
  // Define a helper function that performs a depth-first search on the tree
  // The function takes an index i as input and returns a boolean value
  // The function will decrement the value of n for each visited node
  // The function will return true if all the nodes in the subtree rooted at node i are valid, and false otherwise
  let dfs = (i) => {
    return i >= 0 && --n && dfs(left[i]) & dfs(right[i]);
  };
  // Loop through all the nodes from 0 to n - 1
  for (let i in left) {
    // Check if the left or right child of node i already has a parent in the parent array
    // If so, it means that the node has more than one parent, which is not allowed in a binary tree
    // In this case, return false
    if ((left[i] >= 0 && parent[left[i]] >= 0) || (right[i] >= 0 && parent[right[i]] >= 0)) return false;
    // Otherwise, update the parent array with the left and right children of node i as keys and node i as their value
    // Indicating that node i is their parent
    parent[left[i]] = i;
    parent[right[i]] = i;
  }
  // Find the index of the node that has no parent in the parent array, which should be the root of the tree
  // Call the dfs function with this index as input, and check if it returns true
  // If so, it means that the tree is valid and connected
  // Also check if the value of n is zero after the dfs function
  // If so, it means that all the nodes in the tree have been visited exactly once, which implies that there are no cycles or isolated nodes in the tree
  // Return the logical AND of these two conditions as the final result
  return dfs(parent.indexOf(-1)) || !n;
};

/* 
The time complexity is O(n) because the code loops through all the nodes once, and performs a constant time operation for each node. The dfs function also visits each node once, 
and does not repeat any computation. Therefore, the total number of operations is proportional to n, which is O(n).
The space complexity is O(n) because the code creates an array of size n to store the parent information, and uses a recursive function that may use up to O(n) stack space in the 
worst case. The array and the stack are the only additional memory used by the code, and their size is proportional to n, which is O(n).
*/
