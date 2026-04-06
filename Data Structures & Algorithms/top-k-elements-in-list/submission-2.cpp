class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> mp;
        for (auto it : nums){
            mp[it]++;
        }
        
        vector<pair<int, int>> temp;
        for (auto it : mp){
            temp.push_back(make_pair(it.second, it.first));
        }

        sort(temp.rbegin(), temp.rend());

        for (auto it : temp){
            res.push_back(it.second);
            k--;
            if (!k) break;
        }

        return res;
    }
};
