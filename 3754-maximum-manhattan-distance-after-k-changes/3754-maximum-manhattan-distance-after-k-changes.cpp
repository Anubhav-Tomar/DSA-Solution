class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.size();
        int ans = 0;
        int north = 0;
        int south = 0;
        int east = 0;
        int west = 0;

        for(int i=0; i<n; i++){
            char ch = s[i];
            if(ch == 'N'){
                north++;
            }
            else if(ch == 'S'){
                south++;
            }
            else if(ch == 'E'){
                east++;
            }
            else if(ch == 'W'){
                west++;
            }

            int x = abs(east - west);
            int y = abs(north - south);
            int md = x+y;
            int dis = md + min(2*k, i+1-md);
            ans = max(dis, ans);
        }
        return ans;
    }
};