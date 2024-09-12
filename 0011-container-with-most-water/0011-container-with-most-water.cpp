class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n-1;
        int maxHeight = INT_MIN;

        while(i<j){
            int h1 = height[i];
            int h2 = height[j];

            int area = (j-i) * (min(h1, h2));
            maxHeight = max(maxHeight, area);

            if(h1 > h2){
                j--;
            }
            else{
                i++;
            }
        }
        return maxHeight;
    }
};