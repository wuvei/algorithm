class Solution {
public:
    inline bool isDigit(char c){
        return '0' <= c && c <= '9';
    }
    string decodeString(string s) {
        if (!s.size()) return "";
        stack<string> st;
        string temp = s.substr(0, 1);
        for (int i = 1; i < s.size(); i++) {
            char c = s[i];
            if (isDigit(c)) {
                if (isDigit(s[i - 1])) temp += c;
                else {
                    st.push(temp);
                    temp = c;
                }
            }
            else if (c == '[') {
                st.push(temp);
                st.push("[");
                temp = "";
            }
            else if (c == ']'){
                string word = "";
                if (temp != "") st.push(temp);
                temp = "";
                while(st.top() != "[") {
                    temp = st.top() + temp;
                    st.pop(); 
                }
                st.pop();
                int times = std::stoi(st.top());
                st.pop();
                for (int i = 0; i < times; i++) word += temp;
                st.push(word);
                temp = "";
            }
            else {
                if (s[i - 1] == '[' || s[i - 1] == ']') {
                    temp = c;
                }
                else {
                    temp += c;
                }
            }
        }
        while (!st.empty()) {
            temp = st.top() + temp;
            st.pop();
        }
        return temp;
    }
};