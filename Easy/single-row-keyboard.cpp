#include <iostream>
#include <map>

using namespace std;

// runtime: 28ms
// memory: 9.2MB
// runtime --> 13.59% faster than C++ submissions
// memory --> 100% less than C++ submissions
int calculateTime(string keyboard, string word) {
    int ans = 0;
    map<char, int> m;
    for(int i=0; i<keyboard.length(); i++)
    {
        m.insert(pair<char, int>(keyboard[i], i));
    }
    ans+=m[word[0]];
    for(int i=1; i<word.length(); i++)
    {
        char prev = word[i-1];
        char val = word[i];
        if(m[val]<m[prev]){
        ans += m[prev]-m[val];
      }
      else{
        ans += m[val]-m[prev];
      }
    }
    return ans;
}

int main()
{
  string k = "abcdefghijklmnopqrstuvwxyz";
  string w1 = "cba";
  string w2 = "leet";
  string p = "pqrstuvwxyzabcdefghijklmno";
  string w3="leetcode";
  cout<<calculateTime(k, w1)<<endl;
  cout<<calculateTime(k, w2)<<endl;
  cout<<calculateTime(p, w3)<<endl;
  return 0;
}
