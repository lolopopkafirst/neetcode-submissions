class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> vals;
        
        for(string val : tokens){
            if (val == "+" || val == "-" || val == "*" || val == "/") {
            int val1 = vals.top();
            vals.pop();
            int val2 = vals.top();
            vals.pop();
                if(val == "+"){
                    vals.push((val2 + val1));
                }
                else if(val == "-"){
                    vals.push((val2 - val1));
                }
                else if(val == "*"){
                    vals.push((val2 * val1));
                }
                else if(val == "/"){
                    vals.push((val2 / val1));
                }
            }
            else {
                vals.push(stoi(val));
            }
            }
        return vals.top();
        }
        
};
