class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        // For each monster, calculate the number of minutes it takes to reach the city
        // by dividing its distance by its speed and rounding it down
        for (int i = 0; i < dist.size(); ++i)
            dist[i] = (dist[i] - 1) / speed[i];
        // Sort the distances in ascending order
        sort(begin(dist), end(dist));
        // Loop through the distances and compare them with the current minute
        for (int i = 0; i < dist.size(); ++i)
            // If the distance is smaller than or equal to the minute, it means the monster has reached the city
            // and we cannot eliminate it, so we return the number of monsters eliminated so far
            if (i > dist[i])
                return i;
        // If we reach the end of the loop, it means we can eliminate all the monsters, so we return the size of the vector
        return dist.size();
    }
};

/* 
The time complexity =  O(n log n), where n is the number of monsters. This is because the sorting takes O(n log n) time, and the loop takes O(n) time.
The space complexity = O(1), since we only use constant extra space.
 */
