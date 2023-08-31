class Solution {
public:

    int minTaps(int n, vector<int>& ranges) {
        int sz = ranges.size();
        const int N = 1e4+2;
        int arr[N] = {0};
        for(int i = 0; i < sz; ++i) {
            int left = max(0, i-ranges[i]);
            arr[left] = max(arr[left], i+ranges[i]);
        }
        int prev_interval_end = 0, cnt = 0, far_end = 0;
        // farthest end of any interval 
        // whose start is with in the range
        // of the current interval
        for(int st = 0; st <= n; ++st) {
            // st indicates the start of new interval
            if(st > prev_interval_end) {
                if(far_end < st) return -1;
                cnt++;
                prev_interval_end = far_end;
            }
            far_end =  max(far_end, arr[st]);
        }        
        return cnt;
    }
};
