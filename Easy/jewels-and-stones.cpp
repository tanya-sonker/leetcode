#include <iostream>
#include <map>
#include <unordered_set>
using namespace std;

// set:
// runtime: 8ms (65.08%)
// memory: 8.5MB (41.25%)
// unordered_set:
// runtime: 4ms (65.08%)
// memory: 8.7MB (28.75%)
int numJewelsInStones_set(string J, string S) {
  int count = 0;
  unordered_set<char> s;
  for(int i=0; i<J.length(); i++)
  {
    s.insert(J[i]);
  }

  for(int j=0; j<S.length();j++)
  {
    char val = S[j];
    if(s.find(val)!=s.end())
    {
      count ++;
    }
  }
  return count;
}

// runtime: 4 ms (65.08%)
// memory: 8.6MB (31.25%)
int numJewelsInStones_map(string J, string S) {
  int count = 0;
  map<char, int> m;
  for(int i=0; i<S.length(); i++)
  {
    char c = S[i];
    if(m.find(c)!=m.end())
    {
      m[c]++;
    }
    m.insert(pair<char, int>(c, 1));
  }

  for(int j=0; j<J.length();j++)
  {
    char val = J[j];
    if(m.find(val)!=m.end())
    {
      count += m[val];
    }
  }
  return count;
}
// brute force
// runtime: 4ms (65.08%)
// memory: 8.3 MB (86.25%)
int numJewelsInStones_brute(string J, string S) {
  int count = 0;
  for(int i=0; i<J.length(); i++)
  {
    for(int j=0; j<S.length(); j++)
    {
      if(J[i]==S[j])
      {
        count++;
      }
    }
  }
  return count;
}

int main()
{
  string j = "aA";
  string s = "aAAbbbb";
  cout<<numJewelsInStones_set(j,s)<<endl;
  return 0;
}
