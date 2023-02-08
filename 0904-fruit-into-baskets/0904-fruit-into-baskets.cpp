class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //approach: 
        //sliding window , try to maximize it!
        //note it is not guaranteed that this sliding window is a valid solution , otherwize it is its length

        unordered_map<int, int>baskets;

        //track boundries of the max sliding window so far
        int l = 0, r = 0, n = fruits.size();

        while(r < n){
            //add this fruit type to the baskets
            //may be it is in one of the two or not
            baskets[fruits[r]]++;

            //check if it is not of any type of the two
            //if not , we will increase the size of this window :) => maximizing
            if(baskets.size() > 2){
                
                //move the whole window to right one step
                // ++l , ++r
                //so, remove the type of the leftmost fruit
                // aready added the type of the rightmost fruit
                baskets[fruits[l]]--;

                //just after removing, if one basket is empty remove it (because we track the type of fruits in the window using the baskets no)
                if(baskets[fruits[l]] == 0)
                    baskets.erase(fruits[l]);
                ++l;
            }
            ++r;
        }
        return r - l;
    }
};