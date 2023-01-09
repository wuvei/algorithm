class Solution {
public:
    bool areNumbersAscending(string s) {
        const char separator = ' ';
        std::istringstream streamData(s);
        std::string val;
        int prev = -1;
        while (std::getline(streamData, val, separator)) {
            try {
                const int i {std::stoi(val)};
                if (i <= prev)
                    return false;
                prev = i;
            }
            catch(std::invalid_argument const& ex) {}
        }
        return true;
    }
};