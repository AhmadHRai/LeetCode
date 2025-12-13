#include <algorithm>
#include <regex>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        int n = code.size();
        vector<pair<string, string>>
            validCoupons; // Pair to store valid code and businessLine

        // Valid business line categories
        unordered_set<string> validBusinessLines = {"electronics", "grocery",
                                                    "pharmacy", "restaurant"};

        // Regular expression for valid code: Only alphanumeric characters and
        // underscores.
        std::regex codeRegex("^[a-zA-Z0-9_]+$");

        // Iterate through all coupons
        for (int i = 0; i < n; i++) {
            // Check if the coupon is valid
            if (isActive[i] && !code[i].empty() &&
                std::regex_match(code[i], codeRegex) &&
                validBusinessLines.count(businessLine[i]) > 0) {

                // If valid, add to the list as a pair (businessLine, code)
                validCoupons.push_back({businessLine[i], code[i]});
            }
        }

        // Define sorting order for business line
        unordered_map<string, int> businessLineOrder = {{"electronics", 0},
                                                        {"grocery", 1},
                                                        {"pharmacy", 2},
                                                        {"restaurant", 3}};

        // Sort the validCoupons first by businessLine and then by code
        // lexicographically
        sort(validCoupons.begin(), validCoupons.end(),
             [&businessLineOrder](const pair<string, string>& a,
                                  const pair<string, string>& b) {
                 if (businessLineOrder[a.first] == businessLineOrder[b.first]) {
                     return a.second < b.second;
                 }
                 return businessLineOrder[a.first] < businessLineOrder[b.first];
             });

        // Extract the sorted coupon codes
        vector<string> result;
        for (const auto& coupon : validCoupons) {
            result.push_back(coupon.second);
        }

        return result;
    }
};
