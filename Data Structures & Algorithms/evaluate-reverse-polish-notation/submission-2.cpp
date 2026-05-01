class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto it : tokens){
            if (it == "+" || it == "-" || it == "*" || it == "/"){
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                if (it == "+") st.push(x+y);
                else if (it == "-") st.push(y-x);
                else if (it == "*") st.push(x*y);
                else if (it == "/") st.push(y/x);
                cout<<st.top()<<" ";
            }
            else{
                int op = std::atoi(it.c_str());
                st.push(op);
            }
        }
        
        return st.top();
    }
};
