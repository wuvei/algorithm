class AuthenticationManager {
public:
    AuthenticationManager(int timeToLive): ttl(timeToLive){
    }
    
    void generate(string tokenId, int currentTime) {
        l.push_back(tokenId);
        m[tokenId] = std::make_pair(currentTime + ttl, std::prev(l.end()));
    }
    
    void renew(string tokenId, int currentTime) {
        removeExpired(currentTime);
        if (m.find(tokenId) != m.end() && m[tokenId].first > currentTime) {
            l.erase(m[tokenId].second);
            l.push_back(tokenId);
            m[tokenId] = std::make_pair(currentTime + ttl, std::prev(l.end()));
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        removeExpired(currentTime);
        return l.size();
    }
    void removeExpired(int currentTime) {
        while (!l.empty() && m[l.front()].first <= currentTime) {
            l.pop_front();
        }
    }
private:
    unordered_map<string, pair<int, std::list<string>::iterator>> m;
    list<string> l;
    int ttl;
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */