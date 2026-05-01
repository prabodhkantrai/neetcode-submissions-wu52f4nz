class Solution {
public:
    bool isValid(string s) {
        map<char, char> mp;
        mp['['] = ']';
        mp['{'] = '}';
        mp['('] = ')';
        
        stack<char> st;
        cout<<"hm";
        for(auto it : s){
            if (mp.find(it) != mp.end()){
                st.push(it);
            }
            else{
                if(st.size() == 0 || it != mp[st.top()]){
                    return false;
                }
                st.pop();
            }
            cout<<"hm1";
        }

        if (st.size() != 0) return false;
        cout<<"hm2";
        return true;
    }
};
