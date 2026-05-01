class Solution {
public:
    bool checkIfDone(map<char, int> &mp){
        for(auto it : mp){
            if (it.second > 0) return false;
        }
        return true;
    }

    bool mapCmp(map<char, int> & tempMap, map<char, int> &mp){
        for (auto it : mp)
        {
            if (tempMap.find(it.first) == tempMap.end()) return false;
            else if (tempMap[it.first] < it.second) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        map<char, int> mp;
        sort(t.begin(), t.end());
        for(auto it : t){
            mp[it]++;
        }

        int i=0, j=0, flg = 0;
        int minLen = INT_MAX;
        string minWord = "";
        map<char, int>  tempMap;
        while(i <= j && j < s.size()){
            if (mp.find(s[j]) == mp.end()){
                if (flg == 0) i++;
            }
            else{
                if (flg == 0) flg = 1;
                tempMap[s[j]]++;
                if (mapCmp(tempMap, mp)){
                    cout<<s.substr(i, j-i+1);
                    if (j - i + 1 < minLen){
                        minLen = j - i + 1;
                        minWord = s.substr(i, j-i+1);
                    }
                    while(i <= j)
                    {
                        if (mp.find(s[i]) == mp.end()){
                            i++;
                        }
                        else{
                            if (mapCmp(tempMap, mp)){
                                if (j-i+1 < minLen){
                                    minLen = j-i+1;
                                    minWord = s.substr(i, j-i+1);
                                }
                                tempMap[s[i]]--;
                                i++;
                            }
                            else break;
                        }
                    }
                }
            }
            j++;
        }

        return minWord;
    }
};
