class Trie {
public:
    bool isLeaf;
    Trie* next[26];
    Trie() {
        isLeaf = false;
        for(int i=0; i<26; i++) next[i] = NULL;
    }
};
class Solution {
    Trie* root = new Trie();

    void insert(string word) {
        int len = word.size();
        Trie* iter = root;
        for(char ch : word) {
            if(!iter->next[ch - 97]) {
                iter->next[ch - 97] = new Trie();
            }
            iter = iter->next[ch - 97];
        }
        iter->isLeaf = true;
    }

    string search(string &word) {
        string cu;
        Trie* iter = root;
        for(char ch : word) {
            if(!iter->next[ch - 97]) {
                if(iter->isLeaf) return cu;
                return word;
            }
            cu += ch;
            iter = iter->next[ch - 97];
            if(iter->isLeaf) return cu;
        }
        return cu;
    }
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        string ret, t;
        for(string i: dictionary) insert(i);
        for(char i: sentence) {
            if (i == ' ') {
                ret += search(t);
                ret += ' ';
                t.clear();
            } else {
                t += i;
            }
        }
        ret += search(t);
        return ret;
    }
};