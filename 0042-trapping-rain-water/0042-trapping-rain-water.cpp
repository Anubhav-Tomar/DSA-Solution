class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int total = 0;
        int i = 0;
        int j = n-1;
        int leftmax = height[i];
        int rightmax = height[j];

        while(i < j){
            if(leftmax < rightmax){
                i++;
                leftmax = max(leftmax, height[i]);
                total += leftmax - height[i];
            }
            else{
                j--;
                rightmax = max(rightmax, height[j]);
                total += rightmax - height[j];
            }
        }
        return total;
    }
};