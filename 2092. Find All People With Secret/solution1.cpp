class Solution {
public:
    std::vector<int> findAllPeople(int n, std::vector<std::vector<int>>& meetings, int firstPerson) {
        // Initialize a set to keep track of people who know the secret.
        // Including  0 (representing the person who knows the secret initially) and the first person.
        std::set<int> knownSet = {0, firstPerson};
        
        // Prepare a vector to store sorted meetings by time.
        std::vector<std::vector<std::pair<int, int>>> sortedMeetings;
        // Sort meetings by time to process them in order.
        std::sort(meetings.begin(), meetings.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[2] < b[2];
        });

        // A set to keep track of seen meeting times to group meetings by time.
        std::set<int> seenTime;
        
        // Group meetings by their time and store in sortedMeetings.
        for (const auto& meeting : meetings) {
            if (seenTime.find(meeting[2]) == seenTime.end()) {
                seenTime.insert(meeting[2]);
                sortedMeetings.push_back({});
            }
            sortedMeetings.back().push_back({meeting[0], meeting[1]});
        }

        // For each group of meetings at the same time, construct a graph and perform BFS.
        for (const auto& meetingGroup : sortedMeetings) {
            std::set<int> peopleKnowSecret;
            // Graph to represent connections between people.
            std::unordered_map<int, std::vector<int>> graph;
            
            // Populate the graph with connections between people who attended the same meeting.
            for (const auto& pair : meetingGroup) {
                graph[pair.first].push_back(pair.second);
                graph[pair.second].push_back(pair.first);
                
                // If the person already knows the secret, add them to the set of people who know the secret.
                if (knownSet.find(pair.first) != knownSet.end()) peopleKnowSecret.insert(pair.first);
                if (knownSet.find(pair.second) != knownSet.end()) peopleKnowSecret.insert(pair.second);
            }
            
            // BFS to find all people who know the secret.
            std::queue<int> queue;
            for (int person : peopleKnowSecret) queue.push(person);
        
            while (!queue.empty()) {
                int curr = queue.front();
                queue.pop();
                // Mark the person as knowing the secret.
                knownSet.insert(curr);
                // Add all unseen neighbors to the queue.
                for (int neigh : graph[curr]) {
                    if (knownSet.find(neigh) == knownSet.end()) {
                        knownSet.insert(neigh);
                        queue.push(neigh);
                    }
                }
            }
        }

        // Convert the set of people who know the secret to a vector and return.
        return std::vector<int>(knownSet.begin(), knownSet.end());
    }
};


/* 
Approach

    1. Sort the meetings based on their time.
    2. Iterate through the sorted meetings.
    3. For each meeting group at a specific time, construct a graph where nodes represent people and edges represent connections between people who attended the same meeting.
    4. Perform a breadth-first search (BFS) starting from the people who already know the secret within that meeting group.
    5. Add all encountered people during the BFS traversal to the set of people who know the secret.
    6. Repeat the process for each meeting group.
    7. Return the final set of people who know the secret.

Complexity Analysis

    Time Complexity: The time complexity is primarily influenced by the sorting of meetings (O(n log n)) and the breadth-first search (BFS) traversal. The BFS traversal is performed 
    for each group of meetings, and each BFS takes O(m) time, where m is the total number of attendees in all meetings. Thus, the overall time complexity is O(n log n + m).
    
    Space Complexity: The space complexity is determined by the storage of the graph, the queue, and the set of known people. The graph stores the connections between attendees, the 
    queue stores the BFS traversal queue, and the set stores the people who know the secret. Since the total number of attendees is m, the space complexity is O(m).

 */