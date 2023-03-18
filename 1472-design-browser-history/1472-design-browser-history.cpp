class BrowserHistory {
public:
    vector<string> history;
    int currPageIdx;
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        currPageIdx = 0;
    }
    
    void visit(string url) {
        history.resize(currPageIdx + 1);
        history.push_back(url);
        ++currPageIdx;
        // cut from currpage+1 till end and push url
    }
    
    string back(int steps) {
        currPageIdx = (currPageIdx < steps ? 0 : currPageIdx - steps);
        return history[currPageIdx];
    }
    
    string forward(int steps) {
        int sz = history.size();
        currPageIdx = (steps + currPageIdx >= sz ? sz - 1 : currPageIdx + steps);
        return history[currPageIdx];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */