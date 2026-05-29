class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<pair<int, int>> st;

        for(int i = 0 ; i < n ; i++){
            if(st.empty() || temperatures[st.top().first] >= temperatures[i]){
                st.push({i, 0});
            }
            else{
                while(!st.empty() && temperatures[st.top().first] < temperatures[i]){
                st.top().second += 1;
                int val = st.top().second;
                res[st.top().first] += st.top().second;
                st.pop();
                if(!st.empty()) st.top().second += val;

            }
            st.push({i, 0});
            }
        }
        return res;
    }
};
