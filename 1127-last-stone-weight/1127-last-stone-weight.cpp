class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        

        if(stones.size() == 1){
            return stones[0];
        }

        while(stones.size() > 1){
            sort(stones.begin(), stones.end());
            int n = stones.size();

            stones[n-2] = stones[n-1] - stones[n-2];

            stones.pop_back();
        }

        return stones[0];
    }
};