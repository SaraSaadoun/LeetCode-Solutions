class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size();
        vector<int>ans;
        ans.push_back(first);
        int tmp = first;
        for(int i = 0; i < n; ++i){
            tmp ^= encoded[i];
            ans.push_back(tmp);
        }
        return ans;
    }
};