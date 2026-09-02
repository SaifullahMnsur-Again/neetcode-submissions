class PrefixTree {
    class TrieNode {
    public:
        vector<TrieNode*> children;
        bool isEndOfWord;

        TrieNode() {
            children.assign(26, nullptr);
            isEndOfWord = false;
        }

        ~TrieNode() {
            for (TrieNode* child : children) {
                delete child;
            }
        }
    };
    TrieNode *root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *curr = root;
        for(auto ch : word) {
            int idx = ch - 'a';
            if(curr->children[idx] == nullptr)
                curr->children[idx] = new TrieNode();
            curr = curr->children[idx];
        }
        curr->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode *curr = root;
        for(auto ch : word) {
            int idx = ch - 'a';
            if(curr->children[idx] == nullptr)
                return false;
            curr = curr->children[idx];
        }
        return curr->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        for(auto ch : prefix) {
            int idx = ch - 'a';
            if(curr->children[idx] == nullptr)
                return false;
            curr = curr->children[idx];
        }
        return true;
    }
};
