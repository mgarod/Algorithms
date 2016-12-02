#include <iostream>
#include <unordered_map>
using namespace std;

class TrieNode {
  public:
    TrieNode() : isWord(false) { }
    bool hasNextChar(char c) { return nextChar.count(c); };
    bool isValidWord() { return isWord; };
    void setIsWord() { isWord = true; };
    void set(char c) { nextChar[c] = new TrieNode(); };
    TrieNode* get(char c) { return nextChar[c]; };
  private:
    bool isWord;
    unordered_map<char, TrieNode*> nextChar;
};

class Trie {
  public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* n = root;
        for (int i = 0; i < word.length(); ++i) {
            if (!(n->hasNextChar(word[i])))
              n->set(word[i]);
            n = n->get(word[i]);
        }
        n->setIsWord();
    }

    // Returns if the word is in the trie.
    bool search(string word) {
      TrieNode* n = root;
      for (int i = 0; i < word.length(); ++i) {
        if (n->hasNextChar(word[i])) {
          n = n->get(word[i]);
        } else {
          return false;
        }
      }
      if (n->isValidWord())
        return true;
      else
        return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
      TrieNode* n = root;
      for (int i = 0; i < prefix.length(); ++i) {
        if (n->hasNextChar(prefix[i])) {
          n = n->get(prefix[i]);
        } else {
          return false;
        }
      }
      return true;
    }

  private:
    TrieNode* root;
};

int main() {
  Trie t;
  t.insert("app");
  t.insert("apple");
  t.insert("beer");
  t.insert("add");
  t.insert("jam");
  t.insert("rental");
  cout << std::boolalpha;
  cout << t.search("apps") << endl;
  cout << t.search("app") << endl;
  cout << t.search("ad") << endl;
  cout << t.search("applepie") << endl;
  cout << t.search("rest") << endl;
  cout << t.search("jan") << endl;
  cout << t.search("rent") << endl;
  cout << t.search("beer") << endl;
  cout << t.search("jam") << endl;
  cout << t.startsWith("apps") << endl;
  cout << t.startsWith("app") << endl;
  cout << t.startsWith("ad") << endl;
  cout << t.startsWith("applepie") << endl;
  cout << t.startsWith("rest") << endl;
  cout << t.startsWith("jan") << endl;
  cout << t.startsWith("rent") << endl;
  cout << t.startsWith("beer") << endl;
  cout << t.startsWith("jam") << endl;

  // [false,true,false,false,false,false,false,true,true,false,true,true,false,false,false,true,true,true]
}
