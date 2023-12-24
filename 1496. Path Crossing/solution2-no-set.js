// Define a function named isPathCrossing that takes a string of directions as input and returns a boolean as output
var isPathCrossing = function (path) {
  // Define an object to store the visited coordinates as keys and values
  let map = {};
  // Initialize the current x-coordinate and y-coordinate to zero
  let x = 0,
    y = 0;
  // Convert the current coordinates to a string for hashing
  let coordinates = `${x}:${y}`;
  // Add the origin (0, 0) to the map object
  map[coordinates] = coordinates;
  // Loop through each character in the path string
  for (let i = 0; i < path.length; i++) {
    // Use a switch statement to handle different directions
    switch (path[i]) {
      // If the direction is North, add 1 to the y-coordinate
      case "N": {
        y += 1;
        break;
      }
      // If the direction is West, subtract 1 from the x-coordinate
      case "W": {
        x -= 1;
        break;
      }
      // If the direction is South, subtract 1 from the y-coordinate
      case "S": {
        y -= 1;
        break;
      }
      // If the direction is East, add 1 to the x-coordinate
      case "E": {
        x += 1;
        break;
      }
      // If the direction is invalid, do nothing
      default: {
        break;
      }
    }
    // Convert the current coordinates to a string for hashing
    coordinates = `${x}:${y}`;
    // Check if the current coordinates have been visited before
    if (map[coordinates]) {
      // If yes, return true to indicate that the path is crossing
      return true;
    } else {
      // Otherwise, add the current coordinates to the map object
      map[coordinates] = coordinates;
    }
  }
  // If the loop ends without returning true, return false to indicate that the path is not crossing
  return false;
};

// The time and space complexity are both O(n), where n is the length of the path string. This is because the code loops through each character in the path string once, and uses an object to store the visited coordinates, which can have up to n keys
