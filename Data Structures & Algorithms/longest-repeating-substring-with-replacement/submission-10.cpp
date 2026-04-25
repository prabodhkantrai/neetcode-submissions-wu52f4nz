class Solution {
public:
    int findMax(map<char, int>& mp){
        if (mp.size() == 0) return 0;
        int maxCount = 0;
        for (auto it : mp){
            maxCount = max(maxCount, it.second);
        }
        return maxCount;
    }

    int characterReplacement(string s, int k) {
        int len = s.length();
        if (len <= k + 1) return len; 
        map<char, int> mp;
        int i = 0, j = 0;
        int maxLen = INT_MIN;
        while (i <= j && j < len){
            mp[s[j]]++;
            if(j - i + 1 - findMax(mp) <= k){
                j++;
            }
            else{
                maxLen = max(maxLen, j - i);
                cout<<"2:"<<maxLen<<"\n";
                while (j - i + 1 - findMax(mp) > k){
                    mp[s[i]]--;
                    i++;
                }
                mp[s[j]]--;
            }
        }
        maxLen = max(maxLen, j - i);
        cout<<"3:"<<maxLen<<"\n";
        return maxLen;
    }
};
