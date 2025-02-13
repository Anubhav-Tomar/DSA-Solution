class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
        for(int i: nums){
            pq.push(i);
        }

        while(pq.top() < k){
            long long int first = pq.top();
            pq.pop();
            long long int second = pq.top();
            pq.pop();

            long long int num = min(first, second) * 2 + max(first, second);
            pq.push(num);
            cnt++;
        }
        return cnt;
    }
};