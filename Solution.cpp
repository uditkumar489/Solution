/**
* 451. Sort Characters By Frequency
*
* Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:
Input: "tree"
Output: "eert"
EXPLANATION :
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:
Input: "cccaaa"
Output: "cccaaa"

Example 3:
Input: "Aabb"
Output: "bbAa"
 */


// CODE :

class Solution {
public:
     string frequencySort(string s) {
      // create char frequency O(N)
      unordered_map<char,int> freq; for (char c:s) freq[c]++;
      // create sorted char frequency O(N*logN)
      map<int, unordered_set<char>> sortFreq; for (auto& p:freq) sortFreq[p.second].insert(p.first);
      // create string by char ascending frequency O(N)
      string res;
      for (auto it = sortFreq.rbegin(); it != sortFreq.rend(); ++it) {
        for (char c:it->second) res += string(it->first, c);  
      }
      return res;
    }
};
