static auto _sync_io = ios::sync_with_stdio(false);
static auto _tie_cin = cin.tie(NULL);
static int trieArray[32768][27], baseIndex, nodeCounter;
class Trie {
  int helper(string &str, int threshold) {
    int currentNode = 0, nextNode = 0;
    for (char ch : str) {
      ch -= 96; // Convert character to zero-based index
      nextNode = trieArray[currentNode][ch];
      if (nextNode >= baseIndex) {
        currentNode = nextNode - baseIndex;
        continue;
      }
      if (nextNode < threshold) break;
      trieArray[currentNode][ch] = nextNode = ++nodeCounter + baseIndex;
      currentNode = nodeCounter;
    }
    return nextNode;
  }
public:
  Trie() {
    baseIndex += 65536;
    nodeCounter = 0;
  }

  void insert(string &&word) {
    int lastNode = helper(word, 0);
    trieArray[lastNode -= baseIndex][0] = baseIndex;
  }

  bool search(string &&word) {
    int lastNode = helper(word, baseIndex);
    if (lastNode < baseIndex) return false;
    return trieArray[lastNode -= baseIndex][0] == baseIndex;
  }

  bool startsWith(string &&prefix) {
    int lastNode = helper(prefix, baseIndex);
    return lastNode >= baseIndex;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
