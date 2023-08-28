var MyStack = function () {
  this.queue1 = [];
  this.queue2 = [];
};

MyStack.prototype.push = function (x) {
  this.queue1.push(x);
};

MyStack.prototype.pop = function () {
  while (this.queue1.length > 1) {
    this.queue2.push(this.queue1.shift());
  }
  const popped = this.queue1.shift();
  [this.queue1, this.queue2] = [this.queue2, this.queue1]; // Swap queues
  return popped;
};

MyStack.prototype.top = function () {
  while (this.queue1.length > 1) {
    this.queue2.push(this.queue1.shift());
  }
  const topElement = this.queue1[0];
  this.queue2.push(this.queue1.shift());
  [this.queue1, this.queue2] = [this.queue2, this.queue1]; // Swap queues
  return topElement;
};

MyStack.prototype.empty = function () {
  return this.queue1.length === 0;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * var obj = new MyStack()
 * obj.push(x)
 * var param_2 = obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.empty()
 */

/*
Approach:
    We will maintain two queues: queue1 and queue2.
    When pushing an element, we will enqueue it to queue1.
    For the pop, top, and empty operations, we will transfer elements from queue1 to queue2 until there is only one element left in queue1. 
        The element left in queue1 will be the one that needs to be popped or accessed for the top operation. After the transfer, we will swap the names of queue1 and queue2, 
        so that the element that was originally last pushed becomes the front of the queue (this ensures LIFO behavior).
    For the pop operation, we will dequeue and return the element from the front of the queue (which was originally pushed last).
    For the top operation, we will return the front element of the queue (which was originally pushed last).
    For the empty operation, we will check whether queue1 is empty or not.
*/

/*
Complexity Analysis:
    Push: O(1) - Enqueuing an element into a queue takes constant time.
    Pop: O(n) - In the worst case, we need to transfer n-1 elements from one queue to the other.
    Top: O(n) - Similar to the pop operation, we need to transfer n-1 elements.
    Empty: O(1) - Checking the length of the queue takes constant time.
*/
