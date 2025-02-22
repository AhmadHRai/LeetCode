class Solution {
    public:
        TreeNode* recoverFromPreorder(string traversal) {
            // Stack to manage nodes during reconstruction
            stack<TreeNode*> stack;
            int index = 0; // Index to track the current position in the traversal string
    
            while (index < traversal.size()) {
                // Count the number of dashes to determine the depth of the current node
                int depth = 0;
                while (index < traversal.size() && traversal[index] == '-') {
                    depth++;
                    index++;
                }
    
                // Extract the value of the current node
                int value = 0;
                while (index < traversal.size() && isdigit(traversal[index])) {
                    value = value * 10 + (traversal[index] - '0');
                    index++;
                }
    
                // Create the current node
                TreeNode* node = new TreeNode(value);
    
                // Adjust the stack to the correct depth
                while (stack.size() > depth) {
                    stack.pop(); // Remove nodes until the stack size matches the depth
                }
    
                // Attach the node to its parent if the stack is not empty
                if (!stack.empty()) {
                    if (stack.top()->left == nullptr) {
                        stack.top()->left = node; // Attach as the left child
                    } else {
                        stack.top()->right = node; // Attach as the right child
                    }
                }
    
                // Push the current node onto the stack
                stack.push(node);
            }
    
            // The root is the first node in the stack; remove all other nodes
            while (stack.size() > 1) {
                stack.pop();
            }
    
            return stack.top(); // Return the root node
        }
    }
    /*
    Approach Summary:
        This solution reconstructs a binary tree from a preorder traversal string by using a stack to manage nodes based on their depth. It iteratively extracts node 
        values and depths from the string, adjusts the stack accordingly, and attaches nodes to their parents.
    
    Complexity Analysis:
        Time Complexity: O(N), where N is the length of the traversal string, because each character in the string is processed once.
        Space Complexity: O(N), for storing the stack of nodes.
    */
    