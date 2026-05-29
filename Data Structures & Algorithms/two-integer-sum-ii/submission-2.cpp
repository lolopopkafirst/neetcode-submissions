class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int right = numbers.size() - 1;
        cout << right;
        int left = 0;
        while(true){
            int sum = numbers[left] + numbers[right];
            if(sum == target){
                return vector <int> {left + 1, right + 1};
            }
            if(sum < target){
                left++;
            }
            if(sum > target){
                right--;
            }
        }

    }
};
