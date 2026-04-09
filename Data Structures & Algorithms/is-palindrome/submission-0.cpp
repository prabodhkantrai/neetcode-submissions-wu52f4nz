class Solution {
public:
    bool isPalindrome(string s) {
        string pal = "";
        for (auto it : s){
            if ((it >= 'A' && it <='z') || (it >= '0' && it <= '9')) pal += tolower(it);
        }

        string lap = pal;
        reverse(lap.rbegin(), lap.rend());
        cout<<lap<<"\n";
        cout<<pal;
        if (lap == pal) return true;
        return false;
    }
};
