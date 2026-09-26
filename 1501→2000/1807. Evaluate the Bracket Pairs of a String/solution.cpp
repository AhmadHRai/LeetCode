struct TrieNode {
    TrieNode* next[26]; // 'a'-'z'
    int idx = -1;
};
static constexpr int N = 1e6 + 1;
static TrieNode pool[N];
static int ptr = 0; // node counter
struct Trie {
    TrieNode* newNode() {
        TrieNode* node = &pool[ptr++];
        memset(node->next, 0, sizeof(node->next));
        node->idx = -1;
        return node;
    }
    TrieNode* root;
    Trie() {
        ptr = 0; // reset the counter
        root = newNode();
    }
    void insert(string_view word, int id) {
        TrieNode* Node = root;
        for (char c : word) {
            int i = c - 'a';
            if (Node->next[i] == NULL)
                Node->next[i] = newNode();
            Node = Node->next[i];
        }
        Node->idx = id;
    }

    int search(string_view s) {
        TrieNode* Node = root;
        for (char c : s) {
            int i = c - 'a';
            if (Node->next[i] == NULL)
                return -1;
            Node = Node->next[i];
        }
        return Node->idx;
    }
};
class Solution {
public:
    string evaluate(string& s, vector<vector<string>>& knowledge) {
        const int n = s.size(), m = knowledge.size();
        Trie trie;
        for (int i = 0; i < m; i++)
            trie.insert(knowledge[i][0], i);

        string t;
        t.reserve(n);
        for (int i = 0; i < n; i++) {
            while (i < n && s[i] >= 'a')
                t += s[i++];
            if (i == n)
                break;

            if (s[i] == '(') {
                int l = i++, r;
                while (i < n && s[i] >= 'a')
                    i++;
                if (s[i] == ')')
                    r = i;
                string key = s.substr(l + 1, r - l - 1);
                int id = trie.search(key);
                if (id != -1)
                    t += knowledge[id][1];
                else
                    t += '?';
            }
        }
        return t;
    }
};
