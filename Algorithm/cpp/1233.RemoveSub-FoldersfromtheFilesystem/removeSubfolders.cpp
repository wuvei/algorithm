class Solution {
    
    // Trie class
    class Trie {
        // Node class
        class node{
        public:
            string folder;
            unordered_map<string, node*> trie;
            bool terminal = false;
        };
        
        // root pointer
        node* root;
    public:
        Trie() {
           root = new node(); 
        }
        
        // Utility function to split strings using a delimiter
        vector<string> split(string text, char delim) {
            string line;
            vector<string> vec;
            stringstream ss(text);
            while (getline(ss, line, delim)) {
                if (line != "")
                    vec.push_back(line);
            }
            return vec;
        }

        // Insert into the trie
        void insert(string folder) {
            node* temp = root;
            auto folders = split(folder, '/');

            for(auto folder : folders) {
                // if it's already terminal, don't add anything more.
                if(temp->terminal) return;
                
                if(temp->trie[folder] == NULL){
                    node* new_node = new node();
                    temp->trie[folder] = new_node;
                }
                temp = temp->trie[folder];
            }
            // mark the terminal true at the end.
            temp->terminal = true;
        }
        
        // Add folders to the result
        // iterate over the entire trie root.
        // if terminal true encounters, add that to the result vector.
        void sumFolders(vector<string>& result, string folder, node* head) {
            if(!head) head = root;
            node* temp = head;
            
            if(temp->terminal){
                result.emplace_back(folder);
                return;
            }
            
            auto mp = temp->trie;

            for(auto itr : mp){
                sumFolders(result, folder+"/"+itr.first, itr.second);
            }
        }
    };

public:
    vector<string> removeSubfolders(vector<string>& folders) {
        
        // Instantiate a new trie
        Trie* trie = new Trie();
        
        // Insert each and every folder into the trie
        // The trie is modified such that, if it detects a terminal true, 
        // it straight away returns without adding anything else.
        for(string folder : folders){
            trie->insert(folder);
        }
        
        // Create a new result vector
        vector<string> result;
        // Fill the vector
        trie->sumFolders(result, "", nullptr);
        // return result
        return result;
    }
};