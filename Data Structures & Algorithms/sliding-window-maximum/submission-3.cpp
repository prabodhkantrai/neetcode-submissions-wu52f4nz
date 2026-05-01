class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> ms;
        vector<int> res;

        for(int i = 0; i < k; i++){
            ms.insert(nums[i]);
        }

        for (int i = 0; i <= nums.size() - k; i++){
            res.push_back(*ms.rbegin());
            ms.extract(nums[i]);
            ms.insert(nums[i+k]);
        }

        return res;
    }
};
