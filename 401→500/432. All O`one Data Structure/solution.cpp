#include <list>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class AllOne {
public:
    // Constructor to initialize the AllOne data structure
    AllOne() {
        
    }
    
    // Increments the count of the key by 1
    void inc(string key) {
        // If the key doesn't exist, insert it with initial value 0
        if (!bucketOfKey.count(key))
            bucketOfKey[key] = buckets.insert(buckets.begin(), {0, {key}});
            
        // Move to the next bucket and update the lookup
        auto next = bucketOfKey[key], bucket = next++;
        // If the next bucket doesn't exist or its value is not the expected one, create it
        if (next == buckets.end() || next->value > bucket->value + 1)
            next = buckets.insert(next, {bucket->value + 1, {}});
        
        // Insert the key in the next bucket
        next->keys.insert(key);
        bucketOfKey[key] = next;
        
        // Remove the key from its old bucket
        bucket->keys.erase(key);
        // If the old bucket is empty, remove it from the list
        if (bucket->keys.empty())
            buckets.erase(bucket);
    }
    
    // Decrements the count of the key by 1
    void dec(string key) {
        // If the key doesn't exist, return without doing anything
        if (!bucketOfKey.count(key))
            return;

        // Move to the previous bucket and update the lookup
        auto prev = bucketOfKey[key], bucket = prev--;
        // Remove the key from the mapping
        bucketOfKey.erase(key);
        // If the count is greater than 1, we need to move it to the previous bucket
        if (bucket->value > 1) {
            // If the previous bucket doesn't exist or its value is not the expected one, create it
            if (bucket == buckets.begin() || prev->value < bucket->value - 1)
                prev = buckets.insert(bucket, {bucket->value - 1, {}});
            // Insert the key in the previous bucket
            prev->keys.insert(key);
            bucketOfKey[key] = prev;
        }
        
        // Remove the key from its old bucket
        bucket->keys.erase(key);
        // If the old bucket is empty, remove it from the list
        if (bucket->keys.empty())
            buckets.erase(bucket);
    }
    
    // Retrieves a key with the maximum count
    string getMaxKey() {
        // If buckets are empty, return an empty string
        return buckets.empty() ? "" : *(buckets.rbegin()->keys.begin());
    }
    
    // Retrieves a key with the minimum count
    string getMinKey() {
        // If buckets are empty, return an empty string
        return buckets.empty() ? "" : *(buckets.begin()->keys.begin());
    }
private:
    // Structure to represent a bucket with a count and associated keys
    struct Bucket { 
        int value; 
        unordered_set<string> keys; 
    };
    
    list<Bucket> buckets; // List of buckets to keep track of counts and keys
    unordered_map<string, list<Bucket>::iterator> bucketOfKey; // Map to link keys to their buckets
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

/*
 * Approach:
 * The AllOne data structure maintains a list of buckets, each representing a unique count of keys. 
 * Each bucket contains a set of keys that have the same count. The keys are stored in an unordered 
 * map for fast access. The list of buckets is sorted by their counts.
 * 
 * - `inc(key)`: If the key doesn't exist, it is added to the first bucket (count 0). The key is 
 * moved from its current bucket to the next bucket with count incremented by 1. If the old bucket 
 * becomes empty after the removal, it is deleted.
 * 
 * - `dec(key)`: If the key exists, it is removed from its current bucket. If its count is greater 
 * than 1, it is moved to the previous bucket with count decremented by 1. Again, if the old bucket 
 * becomes empty after the removal, it is deleted.
 * 
 * - `getMaxKey()`: Retrieves a key from the last bucket (max count).
 * 
 * - `getMinKey()`: Retrieves a key from the first bucket (min count).
 *
 * Complexity Analysis:
 * Time Complexity: O(1) for `inc`, `dec`, `getMaxKey`, and `getMinKey` operations, as each operation involves 
 * a constant number of insertions, deletions, and lookups.
 * Space Complexity: O(N) where N is the number of unique keys, as we need to store each key in the map 
 * and associated buckets in the list.
 */
