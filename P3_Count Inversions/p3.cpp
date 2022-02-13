#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

/*
 * Complete the 'isBalanced' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isBalanced(string s) {
    stack<char>st;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '{' || s[i] == '(' || s[i] == '[')
            st.push(s[i]);
        else {
            if (s[i] == '}') {
                if (!st.empty() && st.top() == '{')
                    st.pop();
                else
                    return "NO";
            }
            else if (s[i] == ']') {
                if (st.top() == '[' && !st.empty())
                    st.pop();
                else
                    return "NO";
            }
            else if (s[i] == ')') {
                if (st.top() == '(' && !st.empty())
                    st.pop();
                else
                    return "NO";
            }

        }
    }
    if (st.size() == 0)
        return "YES";
    return "NO";
}

int main()
{

        cout << isBalanced("}][}}(}][))]") << "\n";

    return 0;
}


