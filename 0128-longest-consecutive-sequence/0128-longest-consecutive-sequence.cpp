class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        int ans = 1;

        if(n == 0){
            return 0;
        }

        for(int i=0; i<n; i++){
            st.insert(nums[i]);
        }
        
        for(auto i: st){
            if(st.find(i-1) == st.end()){
                int count = 1;
                int x = i;
                while(st.find(x+1) != st.end()){
                    x++;
                    count++;
                }
                ans = max(ans, count);
            }
        }
        return ans;  
    }
};