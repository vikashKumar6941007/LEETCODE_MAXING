class Solution {
public:

// Think of ans as a stack bcz string also have all function of stack
// push_back() = push()
// pop_back() = pop()
// back() = top()

    string removeDuplicates(string s) {
        string ans;

        for (char c : s) {
            if (!ans.empty() && ans.back() == c)
                ans.pop_back();
            else
                ans.push_back(c);
        }

        return ans;
    }
};