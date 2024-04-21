// Define a custom comparator class that compares two pairs of food name and rating
class custom_comparator
{
    public: 
    // Define the operator () that returns true if the first pair has a higher rating or a smaller name than the second pair
    bool operator() (const pair<string, int>& a, const pair<string, int>& b) const
    {
        // If the ratings are equal, compare the names lexicographically
        return a.second == b.second ? a.first < b.first : a.second > b.second;
    }
};

// Define a class named FoodRatings
class FoodRatings 
{
    public:

    // Declare a hash table that maps each food name to its cuisine name and current rating
    // Hash Function : 
    // H1(food_name) = { cuisine_name, current_rating }

    unordered_map<string, pair<string, int>> food_info;

    // Declare another hash table that maps each cuisine name to a set of pairs of food name and rating
    // The set is ordered by the custom comparator defined above
    // Hash Function : 
    // H2(cuisine_name) = SET({ food_name, current_rating } : ordered by current_rating DESCENDING)

    unordered_map<string, set<pair<string, int>, custom_comparator>> cuisine_info;

    // Define the constructor that takes three vectors of foods, cuisines, and ratings as input and initializes the system
    // Time : O(n), where n is the number of food items
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) 
    {
        // Optimize the input/output stream for faster performance
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        // Get the size of the input vectors
        const int n = (int) foods.size(); 

        // Loop through each food item
        for(int i = 0; i < n; ++i)
        {
            // Insert the food name, cuisine name, and rating into the first hash table
            food_info[foods[i]] = {cuisines[i], ratings[i]};
            // Insert the food name and rating into the set corresponding to the cuisine name in the second hash table
            cuisine_info[cuisines[i]].insert(make_pair(foods[i], ratings[i]));
        }
    }
    
    // Define a method that changes the rating of a given food name to a new rating
    // Time : O(log N), where N is the maximum number of food items in a cuisine
    void changeRating(string food, int new_rating) 
    {
        // Get the reference to the pair of cuisine name and current rating of the given food name from the first hash table
        pair<string, int>& f = food_info[food];
        // Store the old rating in a variable
        int old_rating = f.second;

        // Get the reference to the set of pairs of food name and rating of the cuisine name from the second hash table
        set<pair<string, int>, custom_comparator>& st = cuisine_info[f.first];

        // Remove the pair of food name and old rating from the set
        // This takes O(log N) time
        st.erase({food, old_rating});

        // Update the new rating of the food in the first hash table
        f.second = new_rating;
        // Insert the pair of food name and new rating into the set
        // This also takes O(log N) time
        st.insert(make_pair(food, new_rating));
        
        // Return nothing
        return;
    }
    
    // Define a method that returns the highest rated food name for a given cuisine name
    // Time : O(1)
    string highestRated(string cuisine) 
    {
        // Get the reference to the set of pairs of food name and rating of the cuisine name from the second hash table
        set<pair<string, int>, custom_comparator>& st = cuisine_info[cuisine];
        // Return the first element of the set, which is the pair with the highest rating or the smallest name
        return st.begin()->first;
    }
};

/* 
    The space complexity of the code is O(n), where n is the number of food items, since it stores all the food names, cuisine names, and ratings in two hash tables.
 */