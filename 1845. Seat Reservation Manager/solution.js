class SeatManager {
  constructor(n) {
    this.last = 0;
    this.pq = [];
  }

  reserve() {
    if (this.pq.length === 0) {
      return ++this.last;
    } else {
      this.pq.sort((a, b) => a - b);
      return this.pq.shift();
    }
  }

  unreserve(seatNumber) {
    if (seatNumber === this.last) {
      this.last--;
    } else {
      this.pq.push(seatNumber);
    }
  }
}

/* 
Approach
The approach we've taken is a combination of a Counter and Min-Heap strategy.

    Counter (last): This keeps track of the latest continuous seat that's been reserved. For example, if seats 1, 2, and 3 are reserved and no unreservations have been made, last 
    will be 3. Min-Heap (pq): This is used to keep track of seats that have been unreserved and are out of the continuous sequence. For instance, if someone reserves seats 1, 2, 
    and 3, and then unreserves seat 2, then seat 2 will be added to the min-heap.

The logic for the reserve and unreserve functions is as follows:

    reserve:
        If the min-heap is empty, simply increment the last counter and return it.
        If the min-heap has seats (i.e., there are unreserved seats), pop the smallest seat from the heap and return it.

    unreserve:
        If the seat being unreserved is the last seat in the continuous sequence, decrement the last counter.
        Otherwise, add the unreserved seat to the min-heap.

Complexity
    Time complexity:
        reserve: Average O(1)(when using the counter), but O(log ⁡n) (when using the min-heap).
        unreserve: O(log ⁡n) (due to the min-heap operation).

    Space complexity: O(n)O. This is the worst-case scenario where all seats have been reserved and then unreserved, filling up the min-heap.
*/
