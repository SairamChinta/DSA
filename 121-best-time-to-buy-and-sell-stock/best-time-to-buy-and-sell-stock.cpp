class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minpr=INT_MAX;
        int maxprofit=0;
        for(int i =0; i <prices.size(); i++){
            if(prices[i]<minpr){
                minpr = prices[i];
            }
            else{
                maxprofit = max(maxprofit, prices[i]-minpr);
            }
        }
        return maxprofit;
    }
};