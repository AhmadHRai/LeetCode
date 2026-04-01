class Solution {
public:
    struct Robot {
        int index;
        int position;
        int health;
        int direction;
    };

    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<Robot> robots;
        robots.reserve(n);

        for (int i = 0; i < n; i++) {
            robots.push_back({i, positions[i], healths[i], directions[i] == 'R'});
        }

        sort(robots.begin(), robots.end(), [](const Robot& a, const Robot& b) {
            return a.position < b.position;
        });

        int top = 0;

        for (int i = 0; i < n; i++) {
            auto& curr = robots[i];

            if (curr.direction == 1) {
                robots[top++] = curr;
                continue;
            }

            while (top > 0 && robots[top - 1].direction == 1 && curr.health > 0) {
                auto& prev = robots[top - 1];

                if (prev.health > curr.health) {
                    curr.health = 0;
                    prev.health--;
                    if (prev.health == 0) {
                        top--;
                    }
                } else if (prev.health < curr.health) {
                    curr.health--;
                    top--;
                } else {
                    curr.health = 0;
                    top--;
                }
            }

            if (curr.health > 0) {
                robots[top++] = curr;
            }
        }

        robots.resize(top);

        sort(robots.begin(), robots.end(), [](const Robot& a, const Robot& b) {
            return a.index < b.index;
        });

        vector<int> result;
        result.reserve(robots.size());

        for (const auto& r : robots) {
            result.push_back(r.health);
        }

        return result;
    }
};
