int close_IO = [](){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();

class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        data.push_back(homepage);
    }

    void visit(string url) {
        top = ++cur;
        if (cur == data.size())
            data.push_back(move(url));
        else data[cur] = move(url);
    }

    string back(int steps) {
        return data[cur = max(0, cur - steps)];
    }

    string forward(int steps) {
        return data[cur = min(top, cur + steps)];
    }

private:
    vector<string> data;
    int top = 0, cur = 0;
};