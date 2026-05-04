class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        vector<int> res (temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); i++){
            while (st.size() > 0 && st.top().second < temperatures[i]){
                auto it = st.top();
                res[it.first] = i - it.first;
                st.pop();
            }
            st.push(make_pair(i, temperatures[i]));
        }

        return res;
    }
};
