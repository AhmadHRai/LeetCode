// Define a function named isPathCrossing that takes a string of directions as input and returns a boolean as output
var isPathCrossing = function (directions) {
  // Define an object that maps each direction to a pair of coordinates changes
  let coordinateChanges = {
    N: [0, 1], // North means adding 1 to the y-coordinate
    S: [0, -1], // South means subtracting 1 from the y-coordinate
    W: [-1, 0], // West means subtracting 1 from the x-coordinate
    E: [1, 0], // East means adding 1 to the x-coordinate
  };

  // Define a set to store the visited coordinates
  let visited = new Set();
  // Add the origin (0, 0) to the visited set
  visited.add("0,0");
  // Initialize the current x-coordinate and y-coordinate to zero
  let x = 0;
  let y = 0;

  // Loop through each character in the directions string
  for (let direction of directions) {
    // Get the corresponding coordinate change for the current direction
    let change = coordinateChanges[direction];
    // Get the change in x-coordinate and y-coordinate
    let deltaX = change[0];
    let deltaY = change[1];

    // Update the current x-coordinate and y-coordinate by adding the changes
    x += deltaX;
    y += deltaY;

    // Convert the current coordinates to a string for hashing
    let hash = `${x},${y}`;

    // Check if the current coordinates have been visited before
    if (visited.has(hash)) {
      // If yes, return true to indicate that the path is crossing
      return true;
    }
    // Otherwise, add the current coordinates to the visited set
    visited.add(hash);
  }

  // If the loop ends without returning true, return false to indicate that the path is not crossing
  return false;
};
