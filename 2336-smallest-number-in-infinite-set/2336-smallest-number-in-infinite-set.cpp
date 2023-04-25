class SmallestInfiniteSet {
public:
    vector<bool>nums;
    int smallest;
    int n = 1001;
    SmallestInfiniteSet() {
        nums = vector<bool>(n, true);
        smallest = 1;
    }
    
    int popSmallest() {
        nums[smallest] = false;
        int oldSmallest = smallest;
        for(int i = 1; i < n; ++i) {
            if(nums[i]) {
                smallest = i;
                break;
            }
        }    
        return oldSmallest;
    }
    
    void addBack(int num) {
        if(num < smallest)
            smallest = num;
        nums[num] = true;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */