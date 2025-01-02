class Solution {
public:
    int maxHour(vector<int>& piles) {
        int maxi = INT_MIN;
        int n = piles.size();

        for(int i=0; i<n; i++){
            maxi = max(maxi, piles[i]);
        }

        return maxi;
    }

    int calcHours(vector<int>& piles, int hour) {
        int n = piles.size();
        int totalHour = 0;

        for(int i=0; i<n; i++){
            totalHour += ceil((double)piles[i] / (double)hour);
        }
        
        return totalHour;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = maxHour(piles);

        while(low <= high){
            int mid = high + (low - high) / 2;

            int totalHour = calcHours(piles, mid);

            if(totalHour <= h){
                high = mid - 1;
            }

            else {
                low = mid + 1;
            }
        }

        return low;
    }
};