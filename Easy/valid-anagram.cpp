#include <iostream>
#include <map>
using namespace std;

// faster than 6%
// runtime: 40 ms
// memory: 9.6 MB
// focused on when to return true
bool isAnagram_init(string s, string t) {
        map<char, int> m1, m2;
        for(int i=0; i<s.length(); i++)
        {
            // found a match
            if(m1.find(s[i])!=m1.end())
            {
                m1[s[i]]++;
            }
            else
            {
                m1.insert(pair<char,int>(s[i], 0));
            }
        }
        for(int i=0; i<t.length(); i++)
        {
            // found a match
            if(m2.find(t[i])!=m2.end())
            {
                m2[t[i]]++;
            }
            else
            {
                m2.insert(pair<char,int>(t[i], 0));
            }
        }
        if(s.length()==t.length())
        {
          if(m1==m2)
          {
            return true;
          }
        }
        return false;
}

// faster than 97.88% submissions
// focused on when to return false
// character arithmetic
// runtime: 8 ms
// memory: 9.6 MB
// tried to find if matched; trying to see if doesn't
// actually had this idea with sock merchant
// again this is about pairs so, you want to cancel them out!
bool isAnagram(string s, string t) {
  // 26 chars in English Alphabet
    int count[26] = {0};
    if(s.length()!=t.length())
    {
      return false;
    }
    for(int i=0; i<s.size(); i++)
    {
      count[s[i]-'a']+=1;
      count[t[i]-'a']-=1;
    }
    for(int i=0; i<26; i++)
    {
      if(count[i]!=0)
      {
        return false;
      }
    }
    return true;
}
int main()
{
  string s1 = "rat";
  string s2 = "tra";
  string s3 = "car";
  cout<<isAnagram(s1,s2)<<endl;
  cout<<isAnagram(s1,s3)<<endl;

}
