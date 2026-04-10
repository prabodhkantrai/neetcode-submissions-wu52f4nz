class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (!s.length()) return 0;
        int i = 0, j = 0;
        int maxLen = INT_MIN;
        unordered_set<char> st;
        while (i <= j && j < s.length()){
            if (st.find(s[j]) == st.end()){
                st.insert(s[j]);
                maxLen = max(maxLen, int(st.size()));
                j++;
            }
            else{
                while (i <= j){
                    st.erase(s[i]);
                    if (s[i] == s[j]) {i++; break;}
                    i++;
                }
                maxLen = max(maxLen, int(st.size()));
            }
        }
        return maxLen;
    }
};
