class TrieNode {
public:
    bool isCompleteWord;
    TrieNode *children[26];

    TrieNode() {
        isCompleteWord = false;
        for(int i = 0 ; i < 26 ; i++)
            children[i] = nullptr;
        
    }
};
class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode(); 

    }
    void _insert(TrieNode *node, string& word, int i) {
        if(i == word.size()) {
            node->isCompleteWord = true;
            return;
        }
        int idx = word[i] - 'a';
        if(!node->children[idx])
            node->children[idx] = new TrieNode();
        
         _insert(node->children[idx], word, i+1);
    }
    void insert(string word) {
        _insert(root, word, 0);
    }
    bool _search(TrieNode *node, string& word, int i) {
        if(i == word.size())
            return node->isCompleteWord;
        if(word[i] == '.' ) {
            bool found = 0;
            for (auto child : node->children) {
                if(child)
                 found |= _search(child, word, i+1);
            } 
            return found;
        }
        int idx = word[i] - 'a';

        if(node->children[idx]) 
            return _search(node->children[idx], word, i+1);
        return false;
    }
    bool search(string word) {
        return _search(root, word, 0);
    }

};


class WordDictionary {
public:
    Trie *trie;
    WordDictionary() {
        trie = new Trie();
    }
    
    void addWord(string word) {
        trie->insert(word);
    }
    
    bool search(string word) {
        return trie->search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */