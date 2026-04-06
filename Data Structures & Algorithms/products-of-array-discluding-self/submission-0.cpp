class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> inc, dec, res;
        int temp = 1;
        cout<<"inc ";
        for (auto it : nums){
            temp = temp*it;
            inc.push_back(temp);
            cout<<temp<< " ";
        }

        temp = 1;
        cout<<"dec ";
        for(auto it = nums.rbegin(); it != nums.rend(); it++){
            temp = temp*(*it);
            dec.push_back(temp);
            cout<<temp<<" ";
        }

        reverse(dec.begin(), dec.end());

        for (int i = 0; i < nums.size() ; i++){
            if (i == 0){
                res.push_back(dec[1]);
            }
            else if (i == nums.size() - 1){
                res.push_back(inc[nums.size() - 2]);
            }
            else{
                res.push_back(inc[i-1]*dec[i+1]);
            }
        }

        return res;
    }
};
