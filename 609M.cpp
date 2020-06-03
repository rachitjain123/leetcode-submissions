class Solution {
private:
    unordered_map<string, vector<string>> map;
    vector<vector<string>> res;
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        for(auto& s : paths)
            processPath(s);
        
        for(auto& p : map)
            if(p.second.size() >= 2)
                res.push_back(move(p.second));

        return res;
    }
    
    void processPath(string& s){
        istringstream ss(s);
        string base_dir;
        ss >> base_dir;
        string file;
        while(getline(ss, file, ' ')){
            if(file.empty())
                continue;
            int pos = file.find('(');
            string content = file.substr(pos);
            string name = file.substr(0, pos);
            map[content].push_back(base_dir + "/" + name);
        }
    }
};