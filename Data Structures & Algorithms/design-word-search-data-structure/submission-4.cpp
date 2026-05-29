class WordDictionary {
private:
    array<WordDictionary*, 26> children;
    bool isEnd;
    
public:
    WordDictionary() {
        children.fill(nullptr);
        isEnd = false;
    }
    
    void addWord(string word) {
        WordDictionary* curr = this;
        for(char i : word){
            if(!curr->children[i - 'a']){
                curr->children[i - 'a'] = new WordDictionary();
            }
            curr = curr->children[i - 'a'];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {   
            return searchHelper(word, this);
    }
    bool searchHelper(string word, WordDictionary* curr) { 
            if(word.empty()){
                if(curr->isEnd) return true;
                else return false;
            } 
            
            if(word[0] == '.'){
                for(auto i : curr->children){
                    if(i){
                        if(searchHelper(word.substr(1), i)){
                            return true;
                        }
                    } 
                }
                return false;
            }
            else{
                if(curr->children[word[0] - 'a']){
                    return searchHelper(word.substr(1), curr->children[word[0] - 'a']);
                }
                return false;
           }
            
    }
};
