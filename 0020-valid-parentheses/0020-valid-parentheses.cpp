class Solution {
public:
    bool isValid(string s) {

        // Stack to store opening brackets
        stack<char> st;

        // Traverse the string
        for (char ch : s) {

            // If opening bracket, push into stack
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }

            // Otherwise it is a closing bracket
            else {

                // No opening bracket available
                if (st.empty())
                    return false;

                // Check matching pair
                if (ch == ')' && st.top() != '(')
                    return false;

                if (ch == '}' && st.top() != '{')
                    return false;

                if (ch == ']' && st.top() != '[')
                    return false;

                // Matching bracket found
                st.pop();
            }
        }

        // If stack is empty, all brackets matched
        return st.empty();
    }
};