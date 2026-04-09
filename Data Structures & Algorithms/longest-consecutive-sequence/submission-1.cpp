class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        int maxLen = 1;
        int currLen = 1;
        for(int i = 0 ; i < nums.size() - 1; i++){
            if (nums[i] + 1 == nums[i+1]){
                currLen += 1;
            }
            else if(nums[i] == nums[i+1]){
                continue;
            }
            else{
                currLen = 1;
            }
            maxLen = max(maxLen, currLen);
        }

        return maxLen;
    }
};
