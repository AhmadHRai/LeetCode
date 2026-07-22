const int K = 17, MAXN = 1e5;
int st[K + 1][MAXN];

void build(auto& array) {
	copy(array.begin(), array.end(), st[0]);

	for(int i = 1; i <= K; i++)
	    for(int j = 0; j + (1 << i) <= array.size(); j++)
	        st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
}

int query(int L, int R) {
	int i = bit_width(unsigned(R - L + 1)) - 1;
	return max(st[i][L], st[i][R - (1 << i) + 1]);
}

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(const string& s, vector<vector<int>>& queries) {
        int n = s.size(), active = 0;
        vector<pair<int, int>> zero;
        vector<int> index(n);
        for(int i = 0; i < n; i++) {
        	if(s[i] == '0') {
        		if(i > 0 && s[i - 1] == '0') zero.back().second++;
        		else zero.push_back({i, 1});
        	}else {
        		active++;
        	}
        	index[i] = int(zero.size()) - 1;
        }
        if(zero.empty()) return vector<int>(queries.size(), active);

        vector<int> gains(zero.size() - 1);
        for(int i = zero.size() - 2; i >= 0; i--) {
        	gains[i] = zero[i].second + zero[i + 1].second;
        }
        build(gains);

        vector<int> res(queries.size(), active);
        for(int i = 0, sz = queries.size(); i < queries.size(); i++) {
        	int L = queries[i][0], R = queries[i][1];
        	int start = index[L] + 1, end = index[R] - (s[R] == '0');
        	int cnt_left = index[L] == -1 ? -1 : (zero[index[L]].second - (L - zero[index[L]].first));
    		int cnt_right = index[R] == -1 ? -1 : (R - zero[index[R]].first + 1);

        	if(start < end)
    			res[i] = max(res[i], active + query(start, end - 1));
    		if(s[L] == '0' && s[R] == '0' && index[L] + 1 == index[R])
    			res[i] = max(res[i], active + cnt_left + cnt_right);
            if(s[L] == '0' && index[L] + 1 < index[R] + (s[R] == '1'))
                res[i] = max(res[i], active + cnt_left + zero[index[L] + 1].second);
            if(s[R] == '0' && index[L] < index[R] - 1)
                res[i] = max(res[i], active + cnt_right + zero[index[R] - 1].second);
        }
        return res;
    }
};
