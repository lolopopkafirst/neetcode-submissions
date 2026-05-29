class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> vals;
        
        for(string val : tokens){
                if(val == "+"){
                    int val1 = stoi(vals.top());
                    vals.pop();
                    int val2 = stoi(vals.top());
                    vals.pop();
                    vals.push(to_string(val2 + val1));
                    
                }
                else if(val == "-"){
                int val1 = stoi(vals.top());
                    vals.pop();
                    int val2 = stoi(vals.top());
                    vals.pop();
                    vals.push(to_string(val2 - val1));
                    
                }
                else if(val == "*"){
                    int val1 = stoi(vals.top());
                    vals.pop();
                    int val2 = stoi(vals.top());
                    vals.pop();
                    vals.push(to_string(val2 * val1));
                    
                }
                else if(val == "/"){
                    int val1 = stoi(vals.top());
                    vals.pop();
                    int val2 = stoi(vals.top());
                    vals.pop();
                    vals.push(to_string(val2 / val1));
                }
                else vals.push(val);
            }
        return stoi(vals.top());
        }
        
};
