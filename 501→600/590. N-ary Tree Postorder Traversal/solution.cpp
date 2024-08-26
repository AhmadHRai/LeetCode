/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    // Function to perform postorder traversal of an n-ary tree
    vector<int> postorder(Node* root) {
        if (root == NULL) return {}; // Return an empty vector if the root is null

        vector<int> res; // Vector to store the values of nodes in postorder
        stack<Node*> stk; // Stack to help with the traversal
        stk.push(root); // Start with the root node

        while (!stk.empty()) {
            Node* temp = stk.top(); // Get the top node from the stack
            stk.pop(); // Remove the top node from the stack
            for (int i = 0; i < temp->children.size(); i++) {
                stk.push(temp->children[i]); // Push all children of the current node onto the stack
            }
            res.push_back(temp->val); // Visit the current node and add its value to the result vector
        }

        reverse(res.begin(), res.end()); // Reverse the result vector to get the correct postorder sequence
        return res; // Return the vector with node values in postorder
    }
};

/*
Approach Summary:
- Perform a postorder traversal of an n-ary tree using an iterative approach with a stack.
- Use a stack to traverse the tree in a depth-first manner, pushing all children of each node onto the stack.
- After traversal, reverse the collected node values to achieve the postorder sequence.

Time Complexity:
- O(n), where n is the number of nodes in the tree. Each node is processed once.

Space Complexity:
- O(n), where n is the number of nodes in the tree. The space is used for the result vector and the stack.
*/
