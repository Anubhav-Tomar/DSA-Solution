class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0;
        int j = n-1;

        while(i < j){
            int ans = numbers[i] + numbers[j];

            if(ans == target){
                return {i+1, j+1};
            }
            else if(ans > target){
                j--;
            }
            else{
                i++;
            }
        }
        return {-1, -1};
    }
};