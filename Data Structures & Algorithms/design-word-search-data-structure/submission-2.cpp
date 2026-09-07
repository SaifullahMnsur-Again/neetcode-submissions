class WordDictionary {
    class TrieNode {
    public:
        TrieNode* children[26];
        bool isEOW = false;

        TrieNode() {
            for(int i = 0; i < 26; i++)
                children[i] = nullptr;
            isEOW = false;
        }
    };

    TrieNode *root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *curr = root;
        for(char c : word) {
            int idx = c - 'a';
            if(curr->children[idx] == nullptr)
                curr->children[idx] = new TrieNode();
            curr = curr->children[idx];
        }
        curr->isEOW = true;
    }
    
    bool search(string word, TrieNode *curr = nullptr, int i = 0) {
        if(i == 0 and curr == nullptr) 
            curr = root;

        if(!curr)
            return false;

        if(i == word.size()) {
            if(curr->isEOW)
                return true;
            return false;
        }

        if(word[i] != '.') {
            int idx = word[i] - 'a';
            return search(word, curr->children[idx], i + 1);
        }

        for(int j = 0; j < 26; j++) {
            if(curr->children[j] and search(word, curr->children[j], i + 1))
                return true;
        }

        return false;
    }
};
