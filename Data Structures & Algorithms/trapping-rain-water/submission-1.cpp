class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> leftMax (height.size(), 0);
        vector<int> rightMax (height.size(), 0);
        int currMax = 0;

        for(int i = 0; i < height.size(); i++){
            currMax = max(currMax, height[i]);
            leftMax[i] = currMax;
        }

        currMax = 0;

        for (int i = height.size() - 1; i >= 0; i--){
            currMax = max(currMax, height[i]);
            rightMax[i] = currMax;
        }

        int totalArea = 0;
        for(int i = 0; i < height.size() ; i++){
            int dim= min(leftMax[i], rightMax[i]);
            totalArea += max(0, dim - height[i]);
        }

        return totalArea;
    }
};
