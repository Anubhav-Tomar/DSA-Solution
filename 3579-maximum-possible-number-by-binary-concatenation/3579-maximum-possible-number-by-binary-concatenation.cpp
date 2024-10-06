class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
        int maxnum = 0;
        sort(nums.begin(), nums.end());

        do {
            string binaryCon = "";
            for(auto num: nums){
                binaryCon += toBinaryString(num);
            }
            int decimalVal = binaryToDecimal(binaryCon);
            maxnum = max(maxnum, decimalVal);
        } while (next_permutation(nums.begin(), nums.end()));

        return maxnum;
    }

    string toBinaryString(int num){
        string binary = "";
        while(num > 0){
            binary = (num % 2 == 0 ? "0" : "1") + binary;
            num /= 2;
        }
        return binary;
    }

    int binaryToDecimal(string binary){
        int decimalVal = 0;
        int base = 1;

        for(int i = binary.size()-1; i >= 0; i--){
            if(binary[i] == '1'){
                decimalVal += base;
            }
            base *= 2;
        }
        return decimalVal;
    }
};