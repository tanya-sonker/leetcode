#include <iostream>
using namespace std;

// faster than 100% of C++ online  submissions
// memory less than 50% of C++ online submissions
// memory: 8.6MB; runtime: 0ms

string removeVowels(string s) {
    string ans = "";
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] =='a'|| s[i]=='e'||s[i]=='i'|| s[i]=='o' || s[i]== 'u')
        {
            ans+="";
        }
        else
        {
          ans+=s[i];
        }
    }
    return ans;
}

int main()
{
cout<<removeVowels("leetcodeisacommunityofcoders")<<endl;
return 0;
}
