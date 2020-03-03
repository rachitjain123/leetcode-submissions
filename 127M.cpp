class Solution {
public:
       vector<string> generateNextPossWords(string word, unordered_set<string>& set) {
        vector<string> nextPossWords;
        for (int i = 0; i < word.length(); i++) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (word[i] == c) continue;

                char temp = word[i];
                word[i] = c;
                bool wordInSet = set.find(word) != set.end();

                if (wordInSet) {
                    nextPossWords.push_back(word);
                    set.erase(set.find(word));
                }
                word[i] = temp;
            }
        }
        return nextPossWords;
    }

    int bfs(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set;
        for (string word : wordList) set.insert(word);

        if (set.find(endWord) == set.end()) return 0;

        queue<string> q;
        q.push(beginWord);
        int level = 1;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string frontWord = q.front();
                q.pop();

                vector<string> nextPossWords = generateNextPossWords(frontWord, set);
                for (string word : nextPossWords) {
                    if (word == endWord) return level + 1;
                    q.push(word);
                }
            }
            level++;
        }

        level = 0;
        return level;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int minLadderLength = bfs(beginWord, endWord, wordList);
        return minLadderLength;
    }
};