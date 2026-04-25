class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(), s1.end());
        for(int i = 0; i < s2.length(); i++){
            if (find(s1.begin(), s1.end(), s2[i]) == s1.end()){
                continue;
            }

            string s = s2.substr(i, s1.length());
            sort(s.begin(), s.end());
            if (s == s1) return true;
        }
        return false;
    }
};
