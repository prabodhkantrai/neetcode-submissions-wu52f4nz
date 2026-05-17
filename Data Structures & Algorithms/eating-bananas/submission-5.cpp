class Solution {
public:
    int calculate(vector<int> &piles, int x){
        int res = 0;
        for (auto it : piles){
            int sum = it%x == 0 ? it/x : (it/x) + 1;
            res += sum;
        }
        return res;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int low = 1, high = piles[piles.size() - 1];
        int maxHr = INT_MIN, minRate = INT_MAX;
        while(low <= high){
            int m = low + (high-low)/2;
            int calc = calculate(piles, m);
            if (calc == h){
                minRate = m;
                high =  m - 1;
            }
            else if (calc > h){
                low = m + 1;
            }
            else{
                if (m < minRate){
                    minRate = m;
                }
                high = m - 1;
            }
            cout<<minRate;
        }

        return minRate;
    }
};
