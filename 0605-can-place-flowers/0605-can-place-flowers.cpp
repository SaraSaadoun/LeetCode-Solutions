class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        
        if(n == 0)
            return true;
        
        for(int i = 0; i < m; ++i) {
            
            if(flowerbed[i] == 0){
                
                bool emptyLeftPlot = (!i || flowerbed[i - 1] == 0);
                bool emptyRightPlot = (i == m - 1 || flowerbed[i + 1] == 0);
                
                if(emptyLeftPlot && emptyRightPlot) {
                    flowerbed[i] = 1;
                    --n;
                    if(n == 0)
                        break;
                }
                
            }            
         
        }
        
        return n == 0;

        
    }
};