class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, int> mp;
        for(int i = 0; i < speed.size(); i++){
            mp[position[i]] = speed[i];
        }


        stack<float> st;
        for(auto it : mp){
            while(st.size() > 0 && st.top() <= ((float)(target-it.first)/(float)it.second)){
                st.pop();
            }
            st.push((float)(target-it.first)/(float)it.second);
        }

        return st.size();
    }
};
