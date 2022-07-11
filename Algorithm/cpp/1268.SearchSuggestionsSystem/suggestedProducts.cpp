class Trienode {
public:
    Trienode() {}
    std::shared_ptr<Trienode> data[26];
    vector<int> p;
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        auto root = std::make_shared<Trienode>(), node = root;
        for (int i = 0; i < products.size(); ++i) {
            node = root;
            for (char c: products[i]) {
                if (!node -> data[c - 'a']) {
                    node -> data[c - 'a'] = make_shared<Trienode>();
                }
                node = node -> data[c - 'a'];
                if ((node -> p).size() < 3)
                    (node -> p).push_back(i);
            }
        }
        vector<vector<string>> ans;
        node = root;
        bool flag = false;
        for (char c: searchWord) {
            if (flag || !node -> data[c - 'a']) {
                ans.emplace_back();
                flag = true;
            }
            else {
                vector<string> v;
                node = node -> data[c - 'a'];
                for (int idx: node -> p)
                    v.push_back(products[idx]);
                ans.push_back(std::move(v));
            }
        }
        return ans;
    }
};