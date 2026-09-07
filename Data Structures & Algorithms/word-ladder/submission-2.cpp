class Solution {
    map<string, bool> vis;
    map<string, int> memo; 
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList, int cnt = 1) {
        if(beginWord.size() != endWord.size())
            return 0;
        
        if(beginWord == endWord)
            return cnt;
        
        if (memo.find(beginWord) != memo.end()) {
            return memo[beginWord] == INT_MAX ? INT_MAX : cnt + (memo[beginWord] - 1);
        }
        

        vis[beginWord] = true;
        int minn = INT_MAX;
        int sz = beginWord.size();

        for(auto word : wordList) {
            if(sz == word.size() and !vis[word]) {
                int diff = 0;
                for(int i = 0; i < sz; i++) {
                    diff += word[i] != beginWord[i];
                    if(diff > 1)
                        break;
                }
                if(diff == 1)
                    minn = min(minn, ladderLength(word, endWord, wordList, cnt + 1));
            }
        }

        vis[beginWord] = false;

        if (minn == INT_MAX) {
            memo[beginWord] = INT_MAX;
        } else {
            memo[beginWord] = minn - cnt + 1;
        }

        return (cnt == 1 and minn == INT_MAX) ? 0 : minn;
    }
};
