class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int>  map;
        for (int i = 0; i < strs.size(); i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            cout<<temp<<" ";
            if (map.find(temp) == map.end()){
                int indx = map.size();
                map[temp] = indx;
            }
            if (res.size() <= map[temp]){
                res.push_back({strs[i]});
            }
            else{
                res[map[temp]].push_back(strs[i]);
            }
        }
        return res;
    }
};
