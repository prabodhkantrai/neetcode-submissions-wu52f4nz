class Solution {
public:
    vector<vector<int>> helper(vector<int> &nums, int n){
        vector<vector<int>> v;
        for(int i = n+1; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                if (nums[i]+nums[j] == -1*nums[n]){
                    v.push_back({nums[n], nums[i], nums[j]});
                }
            }
        }

        return v;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        set<string> unq;

        sort(nums.begin(), nums.end());
        int currNum = INT_MIN;

        for(int i = 0; i < nums.size(); i++){
            if (nums[i] == currNum) continue;
            auto s = helper(nums, i);
            if (s.size() != 0){
                for (auto it : s){
                    string temp = to_string(it[0]) + to_string(it[1]) + to_string(it[2]);
                    if (unq.find(temp) == unq.end()){
                        res.push_back(it);
                        unq.insert(temp);
                    }

                }
            }
            currNum = nums[i]; 
        }

        return res;
    }
};