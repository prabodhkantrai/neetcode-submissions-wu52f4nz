class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> minL (prices.size());
        int currMin = INT_MAX;
        for(int i = 0; i <prices.size(); i++){
            currMin = min(currMin, prices[i]);
            minL[i] = currMin;
        }

        vector<int> maxR (prices.size());
        int currMax = INT_MIN;
        for(int i = prices.size() - 1; i >= 0; i--){
            currMax = max(currMax, prices[i]);
            maxR[i] = currMax;
        }

        int netMax = 0;
        for(int i = 0; i < prices.size(); i++){
            netMax = max(netMax, maxR[i] - minL[i]);
        }

        return netMax;

    }
};
