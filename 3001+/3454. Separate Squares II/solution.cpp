class Solution {
public:
    typedef pair<int, int> ii;

    class SegmentTree {
    public:
        vector<ii> tree;

        SegmentTree(int n) { tree.resize(4 * n); }

        void update(int i, int left, int right, int uLeft, int uRight, int val,
                    vector<int>& originX) {
            if (right < uLeft || left > uRight) {
                return;
            }

            if (uLeft <= left && right <= uRight) {
                tree[i].first += val;
            } else {
                int mid = (left + right) / 2;
                update(2 * i + 1, left, mid, uLeft, uRight, val, originX);
                update(2 * i + 2, mid + 1, right, uLeft, uRight, val, originX);
            }

            if (tree[i].first > 0) {
                tree[i].second = originX[right + 1] - originX[left];
            } else if (left == right) {
                tree[i].second = 0;
            } else {
                tree[i].second =
                    tree[2 * i + 1].second + tree[2 * i + 2].second;
            }
        }

        int query() { return tree[0].second; }
    };

    double separateSquares(vector<vector<int>>& squares) {
        int n = squares.size();

        vector<tuple<int, int, int, int>> events;
        vector<int> originX;
        int maxX = 0;
        for (int i = 0; i < n; ++i) {
            int x = squares[i][0];
            int y = squares[i][1];
            int l = squares[i][2];

            events.emplace_back(y, x, l, 1);
            events.emplace_back(y + l, x, l, -1);

            originX.push_back(x);
            originX.push_back(x + l);

            maxX = max(maxX, x + l);
        }

        sort(events.begin(), events.end(), [](const auto& a, const auto& b) {
            return get<0>(a) < get<0>(b);
        });
        sort(originX.begin(), originX.end());

        int maxCompressX =
            lower_bound(originX.begin(), originX.end(), maxX) - originX.begin();
        SegmentTree* segmentTree = new SegmentTree(maxCompressX);

        // Calculate totalArea
        double totalArea = 0;
        double prevY = 0;
        for (auto [y, x, l, type] : events) {
            double thisArea = segmentTree->query() * (y - prevY);

            int left = lower_bound(originX.begin(), originX.end(), x) -
                       originX.begin();
            int right = lower_bound(originX.begin(), originX.end(), x + l) -
                        originX.begin() - 1;
            segmentTree->update(0, 0, maxCompressX, left, right, type, originX);
            totalArea += thisArea;
            prevY = y;
        }

        // Find answer
        segmentTree = new SegmentTree(maxCompressX);
        double curArea = 0;
        double curWidth = 0;
        prevY = 0;
        for (auto [y, x, l, type] : events) {
            curWidth = segmentTree->query();
            double thisArea = curWidth * (y - prevY);
            if (2 * (curArea + thisArea) >= totalArea) {
                return prevY + (totalArea - 2.0 * curArea) / (2.0 * curWidth);
            }

            int left = lower_bound(originX.begin(), originX.end(), x) -
                       originX.begin();
            int right = lower_bound(originX.begin(), originX.end(), x + l) -
                        originX.begin() - 1;
            segmentTree->update(0, 0, maxCompressX, left, right, type, originX);
            curArea += thisArea;
            prevY = y;
        }

        return 0;
    }
};
