class PrefixTree {
    class TrieNode {
    public:
        TrieNode* children[26];
        bool isEOW;
        TrieNode() {
            for(int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            isEOW = false;
        }
    };
    TrieNode *root;
public:
    PrefixTree() {
      root = new TrieNode();  
    }
    
    void insert(string word) {
        TrieNode *curr = root;
        for(char c : word) {
            int idx = c - 'a';
            if(curr->children[idx] == nullptr) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isEOW = true;
    }
    
    bool search(string word) {
        TrieNode *curr = root;
        for(char c : word) {
            int idx = c - 'a';
            if(curr->children[idx] == nullptr) {
                return false;
            }
            curr = curr->children[idx];
        }
        if(curr->isEOW)
            return true;
        return false;
        
    }
    
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        for(char c : prefix) {
            int idx = c - 'a';
            if(curr->children[idx] == nullptr) {
                return false;
            }
            curr = curr->children[idx];
        }
        return true;
    }
};
