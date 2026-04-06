    class Solution {
    public:
        bool helper(vector<int>& nums){
            for(int i = 0 ; i < nums.size() - 1 ; i++){
                if (nums[i] == nums[i+1]){
                    return true;
                }
            } 
            return false;
        }

        bool hasDuplicate(vector<int>& nums) {
            if (nums.size() == 0) return false;
            sort(nums.begin(), nums.end());
            return helper(nums);
        }
    };