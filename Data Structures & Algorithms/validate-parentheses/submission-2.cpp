class Solution {
public:
    bool isValid(string s) {
        stack<char> res = {};
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                res.push(s[i]);
            else{
                switch(s[i]){
                    case '}' :
                        if(!res.empty() && res.top() == '{') res.pop();
                        else return false;
                        break;
                    case ')' :
                        if(!res.empty() && res.top() == '(') res.pop();
                        else return false;
                        break;
                    case ']' :
                        if(!res.empty() && res.top() == '[') res.pop();
                        else return false;
                        break;
                    default : 
                        res.push(']');
                }

            }
        }

        return res.empty();
    }
};
