class Solution {
    int cnt;
    unordered_map<string,string>mp;
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        cnt++;
        string str=to_string(cnt);
        mp[str]=longUrl;
        return str;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));