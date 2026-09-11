class BrowserHistory {
    std::list<string>::iterator it;
    list<string> hist;
public:
    BrowserHistory(string homepage) {
        hist.push_back(homepage);
        it = hist.begin();
    }
    
    void visit(string url) {
        auto nxt = it;
        nxt++;
        
        hist.erase(nxt, hist.end());
    
        hist.push_back(url);
        it = --hist.end();
    }
    
    string back(int steps) {
        while(it != hist.begin() and steps > 0) {
            steps--;
            it--;
        }
        return *it;
    }
    
    string forward(int steps) {
        while(it != --hist.end() and steps > 0) {
            steps--;
            it++;
        }
        return *it;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */