class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, h = nums.size()-1;
        int pivot = -1;
        if (nums.size() == 1) return nums[0];
        while(l <= h){
            int m = l + (h-l)/2;
            if ((m == 0 && nums[m] < nums[m+1]) || 
                (m == nums.size() - 1 && nums[m-1] > nums[m]) || 
                (m > 0 && m < nums.size() - 1 && nums[m] < nums[m+1] && nums[m] < nums[m-1])){
                    pivot = m;
                    break;
                }
            else if (nums[m] > nums[nums.size()-1]){
                l = m+1;
            }
            else{
                h = m-1;
            }
        }

        return nums[pivot];
    }
};
