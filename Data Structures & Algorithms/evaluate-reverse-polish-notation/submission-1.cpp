class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for (auto it : tokens) {
            if (it == "+") {
                long long num1 = st.top();
                st.pop();
                long long num2 = st.top();
                st.pop();
                st.push(num1 + num2);
            } else if (it == "-") {
                long long num1 = st.top();
                st.pop();
                long long num2 = st.top();
                st.pop();
                st.push(num2 - num1);
            } else if (it == "*") {
                long long num1 = st.top();
                st.pop();
                long long num2 = st.top();
                st.pop();
                st.push(num1 * num2);
            } else if (it == "/") {
                long long num1 = st.top();
                st.pop();
                long long num2 = st.top();
                st.pop();
                st.push(num2 / num1);
            } else {
                long long num = stoi(it);
                st.push(num);
            }
        }
        return st.top();
    }
};
