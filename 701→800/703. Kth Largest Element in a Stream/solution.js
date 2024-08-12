/**
 * @param {number} k - The k value representing the k-th largest element to find
 * @param {number[]} nums - An array of numbers to initialize the data structure
 */
var KthLargest = function (k, nums) {
  // Initialize a max-heap with a dummy value (Infinity) at index 0
  this.maxHeap = [Infinity];
  // Store the value of k
  this.k = k;

  // Add each number from the initial array into the max-heap
  for (let num of nums) {
    this.add(num);
  }
};

/**
 * @param {number} val - The new value to be added to the max-heap
 * @return {number} - The k-th largest element in the max-heap after adding the new value
 */
KthLargest.prototype.add = function (val) {
  // Add the new value to the end of the max-heap
  this.maxHeap.push(val);

  // Maintain the heap property by shifting the new value up to its correct position
  let i = this.maxHeap.length - 1;
  let p = Math.floor(i / 2); // Calculate the parent index
  while (i > 1 && this.maxHeap[i] < this.maxHeap[p]) {
    // Swap the current element with its parent if it is smaller
    let tmp = this.maxHeap[i];
    this.maxHeap[i] = this.maxHeap[p];
    this.maxHeap[p] = tmp;

    // Update the current index and parent index
    i = p;
    p = Math.floor(i / 2);
  }

  // If the heap has more than k+1 elements, remove the smallest (root) element
  if (this.maxHeap.length > this.k + 1) {
    let r = this.maxHeap[1]; // Store the root element to be replaced
    this.maxHeap[1] = this.maxHeap.pop(); // Replace root with the last element and remove the last element
    let i = 1;

    // Restore the heap property by shifting the new root down to its correct position
    while (i * 2 < this.maxHeap.length) {
      // Check if the right child exists and is smaller than the left child and the current element
      if (
        i * 2 + 1 < this.maxHeap.length &&
        this.maxHeap[i * 2 + 1] < this.maxHeap[i * 2] &&
        this.maxHeap[i * 2 + 1] < this.maxHeap[i]
      ) {
        // Swap with the right child
        let tmp = this.maxHeap[i * 2 + 1];
        this.maxHeap[i * 2 + 1] = this.maxHeap[i];
        this.maxHeap[i] = tmp;
        i = i * 2 + 1;
      }
      // Check if the left child is smaller than the current element
      else if (this.maxHeap[i * 2] < this.maxHeap[i]) {
        // Swap with the left child
        let tmp = this.maxHeap[i * 2];
        this.maxHeap[i * 2] = this.maxHeap[i];
        this.maxHeap[i] = tmp;
        i = i * 2;
      }
      // If the current element is smaller than both children, break the loop
      else {
        break;
      }
    }
  }
  // Return the root element, which is the k-th largest element in the heap
  return this.maxHeap[1];
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * var obj = new KthLargest(k, nums)
 * var param_1 = obj.add(val)
 */

/*
Approach:
1. The KthLargest class maintains a max-heap structure to keep track of the k-th largest element.
2. The constructor initializes the heap with a dummy value and processes the initial array `nums` by adding each element to the heap.
3. The `add` method adds a new value to the heap and adjusts the heap to maintain the correct ordering:
   - It pushes the new value into the heap and shifts it up to its correct position.
   - If the heap size exceeds `k+1`, it removes the smallest element (root) to ensure the heap only contains the k largest elements.
   - Finally, the root of the heap represents the k-th largest element and is returned.
   
Complexity Analysis:
- Time Complexity:
  - Insertion (add method): O(log k) because the heap is maintained with at most `k+1` elements, so each insertion takes log(k) time.
  - Initial construction: O(n log k), where `n` is the number of elements in the initial `nums` array.
- Space Complexity: O(k) for storing up to `k+1` elements in the max-heap.
*/
