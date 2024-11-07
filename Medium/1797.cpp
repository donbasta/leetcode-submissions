class AuthenticationManager {
public:
    int ttl;
    set<pair<int, string>> se;
    map<string, int> ids;
    AuthenticationManager(int timeToLive) : ttl(timeToLive) {
        
    }

    void jumpTime(int currentTime) {
        while (!se.empty() && se.begin()->first <= currentTime) {
            ids.erase(se.begin()->second);
            se.erase(se.begin());
        }
    }
    
    void generate(string tokenId, int currentTime) {
        jumpTime(currentTime);
        se.emplace(currentTime + ttl, tokenId);
        ids[tokenId] = currentTime + ttl;
    }
    
    void renew(string tokenId, int currentTime) {
        jumpTime(currentTime);
        if (!ids.count(tokenId)) return;
        se.erase(make_pair(ids[tokenId], tokenId));
        ids[tokenId] = currentTime + ttl;
        se.emplace(ids[tokenId], tokenId);
    }
    
    int countUnexpiredTokens(int currentTime) {
        jumpTime(currentTime);
        return ids.size();
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */