class Solution {
public:
    int leastInterval(vector<char>& tasks, int n){
        array<int, 26> arr{};
        for(char c : tasks){
            arr[c - 'A']++;
        }

        int maxF = 0;

        for(int freq : arr){
            maxF = max(maxF , freq);
        }

        int maxCount = 0;

        for(int freq : arr){
            if(maxF == freq){
                maxCount++;
            }
        }

        int k = (maxF - 1) * (n + 1) + maxCount;
    
        return max((int)tasks.size(), k);
    }
};
