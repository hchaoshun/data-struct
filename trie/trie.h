#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode {
  struct TrieNode *children[ALPHABET_SIZE];
  bool is_end_word;
};

struct TrieNode *getNode() {
  struct TrieNode *node = new TrieNode();
  node->is_end_word = false;
  for (size_t i = 0; i < ALPHABET_SIZE; ++i) {
    node->children[i] = nullptr;
  }
  return node;
}

class Trie {
 public:
  void insert(struct TrieNode *root, const string &key) {
    struct TrieNode *ptr = root;
    for (size_t i = 0; i < key.size(); i++) {
      size_t index = key[i] - 'a';
      if (!ptr->children[index]) {
        ptr->children[index] = getNode();
      }
      ptr = ptr->children[index];
    }
    ptr->is_end_word = true;
  }

  bool search(struct TrieNode *root, const string &key) {
    struct TrieNode *ptr = root;
    for (size_t i = 0; i < key.size(); ++i) {
      size_t index = key[i] - 'a';
      if (!ptr->children[index]) {
        return false;
      }
      ptr = ptr->children[index];
    }
    return (ptr != nullptr && ptr->is_end_word);
  }
};

int main() {
  vector<string> keys {"the", "a", "there", "answer", "any", "bye", "their"};
  Trie t;
  struct TrieNode *root = getNode();
  for (auto key : keys) {
    t.insert(root, key);
  }
  cout << t.search(root, "there") << endl;
  cout << t.search(root, "aa") << endl;

  return 0;
}
