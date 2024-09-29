class Solution {
public:
    int countOfSubstrings(string word, int k) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int n = word.size();
        int count = 0;

        for(int i=0; i<n; i++){
            unordered_set<char> found;
            int constant = 0;
            for(int j=i; j<n; j++){
                char ch = word[j];
                if(vowels.count(ch)){
                    found.insert(ch);
                }
                else{
                    constant++;
                }

                if(found.size() == 5 && constant == k){
                    count++;
                }

                if(constant > k){
                    break;
                }
            }
        }
        return count;
    }
};