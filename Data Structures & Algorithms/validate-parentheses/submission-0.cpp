class Solution {
   public:
    bool isValid(string s) {
        stack<char> st;
        for (auto it : s) {
            if (it == '(' or it == '[' or it == '{')
                st.push(it);
            else {
                if (it == ')') {
                    if (st.empty())
                        return false;
                    else if (st.top() != '(')
                        return false;
                    st.pop();
                } else if (it == ']') {
                    if (st.empty())
                        return false;
                    else if (st.top() != '[')
                        return false;
                    st.pop();
                } else {
                    if (st.empty())
                        return false;
                    else if (st.top() != '{')
                        return false;
                    st.pop();
                }
            }
        }
        return st.empty();
    }
};
