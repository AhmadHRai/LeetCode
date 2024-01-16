use std::collections::HashMap;
use rand::prelude::*;

struct RandomizedSet {
    list : Vec<i32>,
    map  : HashMap<i32, usize>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl RandomizedSet {

    fn new() -> Self {
        Self { list: Vec::new(), map: HashMap::new() }
    }
    
    fn insert(&mut self, val: i32) -> bool {
        if !self.map.contains_key(&val) {
            self.map.insert(val, self.list.len());
            self.list.push(val);
            true
        } else { false }
    }
    
    fn remove(&mut self, val: i32) -> bool {
        if let Some(idx) = self.map.remove(&val) {
            if let Some(&val2) = self.list.last() {
                self.list.swap_remove(idx);
                if val != val2 {
                    *self.map.get_mut(&val2).unwrap() = idx;
                }
            }
            true
        } else { false }
    }
    
    fn get_random(&self) -> i32 {
        *self.list.choose(&mut rand::thread_rng()).unwrap()
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * let obj = RandomizedSet::new();
 * let ret_1: bool = obj.insert(val);
 * let ret_2: bool = obj.remove(val);
 * let ret_3: i32 = obj.get_random();
 */

 /* 
Approach

To solve the random selection problem, a vector is maintained along with a hash map. The keys of the hash map are the inserted values, and its values are the indexes into the 
vector where the same respective keys reside.

When a new value is inserted, it's pushed onto the end of the vector, and added as a key to the hash map with the last vector index as the value.

When a value is removed, the key is removed from the hash map along with its vector index. The key is also removed from the vector at the given index, moving the value at the 
end of the vector to fill the vacated index. The hash map is updated to reflect the moved key in the vector.

Complexity

    Time complexity: O(1) for each operation, or O(Q) where Q is the number of operations.
    Space complexity: O(Q) where the worst-case is insert() adds another number for each operation.

*/