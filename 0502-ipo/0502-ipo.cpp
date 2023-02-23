class Solution {
public:   
    
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        int n = profits.size();
        
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; ++i){
            v[i] = {capital[i],  profits[i]};
        }
        //sort according to capital
        sort(v.begin(), v.end());

        //pq : to find the max profit of all possible projects till now in o(1)
        //possible projects : projects that have capital <= w
        priority_queue<int> pq;

        int i = 0;
        while(k--){
            //get all possible projects
            while(i<n && v[i].first <= w){
                pq.push(v[i++].second);
            }
            //no one of the projects have the minimum capital (w) to be done :( so break
            //note from the problem description:
            // Pick a list of at *most* k distinct projects
            if(pq.empty())
                break;
            
            //pick the max profit of all possible projects
            int mx = pq.top();
            pq.pop();
            w += mx;
        }
        return w;
    }
};