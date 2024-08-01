/**
 * @param {string[]} details - An array of strings where each string contains details about a citizen
 * @return {number} - The count of citizens whose age is greater than 60
 */
var countSeniors = function(details) {
    let count = 0; // Initialize the count of seniors to zero
    // Iterate over each citizen's detail in the details array
    for (let citizen of details) {
        // Extract the age from the string. The age is at characters 11 and 12 (0-indexed) of the string.
        let age = Number(citizen.substring(11, 13));
        // Check if the extracted age is greater than 60
        if(age > 60) {
            count ++; // Increment the count if the condition is met
        }
    }
    return count; // Return the total count of seniors
};

/*
Approach:
- Iterate over each string in the `details` array.
- For each string, extract the age which is located at the 12th and 13th characters of the string.
- Convert the extracted substring to a number.
- Check if this number is greater than 60 and if so, increment the count of seniors.
- Return the total count of seniors.

Complexity Analysis:
- Time Complexity: O(n), where n is the number of strings in the `details` array. We iterate through each string once.
- Space Complexity: O(1), as we use only a constant amount of extra space for the count variable.
*/
