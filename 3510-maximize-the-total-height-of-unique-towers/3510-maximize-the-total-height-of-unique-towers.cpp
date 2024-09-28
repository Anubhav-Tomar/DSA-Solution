class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        int n = maximumHeight.size();
        sort(maximumHeight.begin(), maximumHeight.end());
        long long sum = 0;
        long long curr = maximumHeight.back();

        for(int i=n-1; i>=0; i--){
            curr = min(curr, (long long)maximumHeight[i]);
            if(curr <= 0){
                return -1;
            }
            sum += curr;
            curr--;
        }
        return sum;
    }
};