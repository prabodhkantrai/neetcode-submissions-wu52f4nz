class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, h = matrix.size()-1;
        int i = -1;
        while(l <= h){
            int m = l + (h-l)/2;
            if (matrix[m][0] <= target && matrix[m][matrix[0].size()-1] >= target){
                i = m;
                break;
            }
            else if (matrix[m][0] > target){
                h = m-1;
            }
            else{
                l = m+1;
            }
        }
        if (i == -1) return false;
        l = 0;
        h = matrix[0].size();
        while (l <= h){
            int m = l + (h-l)/2;
            if (matrix[i][m] == target){
                return true;
            }
            else if (matrix[i][m] > target){
                h = m-1;
            }
            else{
                l = m+1;
            }
        }

        return false;
    }
};
