class Solution {
    class TrieNode {
    public:
        bool endofWord;
        TrieNode* children[26];

        TrieNode()
        {
            endofWord = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };


    class Trie {
    public:
        TrieNode* root;
        Trie() { root = new TrieNode(); }

        void insert(string word)
        {
            TrieNode* node = root;
            for (char c : word) {
                int index = c - 'a';
                if (!node->children[index]) {
                    node->children[index] = new TrieNode();
                }
                node = node->children[index];
            }
            node->endofWord = true;
        }
    };

    Trie trie;
    vector<int> memo;
public:
    bool wordBreak(string s, vector<string>& wordDict, int i = 0) {
        // cerr << "Called for: " << i << endl;
        if(i >= s.size())
            return true;
        if(i == 0) {
            memo.assign(s.size(), -1);
            for(auto word : wordDict)
                trie.insert(word);
        }

        if(memo[i] != -1)
            return memo[i];

        TrieNode *node = trie.root;
        for(int ln = 1; i + ln <= s.size(); ln++) {
            int idx = s[i + ln - 1] - 'a';
            if(node->children[idx] == 0)
                break;
            node = node->children[idx];
            if(node->endofWord and wordBreak(s, wordDict, i + ln)) {
                return memo[i] = 1;
            }
        }

        return memo[i] = 0;
    }
};
