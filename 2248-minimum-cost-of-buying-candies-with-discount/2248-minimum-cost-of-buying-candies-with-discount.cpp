class Solution {
public:
    int minimumCost(vector<int>& cost) {
       int n=cost.size();
        sort(cost.begin(),cost.end());
        int sum=0;
        int count=0;
        for(int i=n-1;i>=0;i--){
            if(count>1){
                count=0;
                continue;
            }
            sum=sum+cost[i];
            count++;
        }
        return sum;
    }
};