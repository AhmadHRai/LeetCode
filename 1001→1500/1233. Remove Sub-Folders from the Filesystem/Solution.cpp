class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // Sort the folders lexicographically so parent folders come before their subfolders
        sort(folder.begin(), folder.end());

        // Initialize result vector with the first folder
        vector<string> ans;
        ans.push_back(folder[0]);

        // Iterate through remaining folders starting from index 1
        for(int i = 1; i < folder.size(); i++) {
            // Get the last added folder path and add a trailing slash
            // This helps in comparing if current folder is a subfolder
            string lastFolder = ans.back();
            lastFolder.push_back('/');

            // Compare current folder with last added folder
            // compare(0, lastFolder.size(), lastFolder) checks if folder[i] starts with lastFolder
            // If it doesn't start with lastFolder (returns != 0), then it's not a subfolder
            if(folder[i].compare(0, lastFolder.size(), lastFolder) != 0) {
                // If not a subfolder, add to result
                ans.push_back(folder[i]);
            }
        }

        return ans; // Return the list of folders without subfolders
    }
};

/*
Approach:

    This solution employs a greedy algorithm to remove subfolders from a list of folder paths.
    It first sorts the folder paths lexicographically, ensuring that any parent folder appears before its subfolders.
    Then, it iterates through the sorted folder list, using the last added folder to check if the current folder is a subfolder.
    If the current folder does not start with the last added folder followed by a '/', it is added to the result.

Complexity:

    Time Complexity: O(n log n) due to the sorting step, where n is the number of folders.
    Space Complexity: O(n) for storing the result in the vector.

This approach efficiently filters out subfolders while maintaining the original order of the remaining folders.
*/
