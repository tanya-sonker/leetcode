#include <iostream>
#include <stack>
using namespace std;

// time limit exceeded
// but had the right idea
bool isValid_trial(string s) {
        stack<char> st;
        int i=0;
        while(i<s.length())
        {
            st.push(s[i]);
            if(s[i]=='(')
            {
                if(s[i+1]==')')
                {
                    st.push(s[i+1]);
                    st.pop(); // pop closing
                    st.pop(); // pop opening
                    i+=2;
                }
                else if(s[i+1]=='}'||s[i+1]==']')
                {
                    st.push(s[i+1]);
                    i+=2;
                }
                else{
                    i++;
                }
                // continue iterating
            }
            else if(s[i]=='{')
            {
                if(s[i+1]=='}')
                {
                    st.push(s[i+1]);
                    st.pop(); // pop closing
                    st.pop(); // pop opening
                    i+=2;
                }
                else if(s[i+1]==')'||s[i+1]==']')
                {
                    st.push(s[i+1]);
                    i+=2;
                }
                else{
                    i++;
                }
                // continue iterating
            }
            else if(s[i]=='[')
            {
                if(s[i+1]==']')
                {
                    st.push(s[i+1]);
                    st.pop(); // pop closing
                    st.pop(); // pop opening
                    i+=2;
                }
                else if(s[i+1]=='}'||s[i+1]==')')
                {
                    st.push(s[i+1]);
                    i+=2;
                }
                else{
                    i++;
                }
                // continue iterating
            }
            else{ // } end of string
                if(s[i]=='}' && st.top()=='{')
                {
                    st.pop();
                }
                else if(s[i]==']' && st.top()=='[')
                {
                    st.pop();
                }
                else if(s[i]==')' && st.top()=='(')
                {
                    st.pop();
                }
            }
        }
        if(!st.empty())
        {
            return false;
        }
      return true;
}

// works for examples below!
// but runtime error with leetcode
bool isValid_unacceptable(string s)
{
  stack<char> st;
    if(s.length()==0)
    {
        return true;
    }
    else if(s.length()==1) // case: {
    {
        return false;
    }
    else{
      for(int i=0; i<s.length(); i++)
      {
        // push to stack if opening brace
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
        {
          st.push(s[i]);
        }
        // processing closing braces
        // check top of stack if opening brace
        else // if(s[i]==')' || s[i]=='}' || s[i]==']')
        {
          if(st.top()=='(' && s[i]==')')
          {
            st.pop();
          }
          else if(st.top()=='{' && s[i]=='}')
          {
            st.pop();
          }
          else if(st.top()=='[' && s[i]==']')
          {
            st.pop();
          }
          else{
            st.push(s[i]);  // this case: { [ } ]
          }
        }
      }
    }
  if(!st.empty())
  {
    return false;
  }
 return true;
}


// faster than 100% of C++ submissions
// memory usage: 8.6MB
// my mistake: I think of when to continue
// that is I think of true cases
// I need to think of when to terminate
// that is when to return false
bool isValid(string s)
{
  stack<char> st;

  // empty string
  if(s.length() == 0){
      return true;
  }

  // single parenthesis
  if(s.length() == 1){
      return false;
  }

// process if closing bracket
  for(int i =0 ; i < s.length(); i++){
      char c = s[i];
      if(c == '}'|| c == ')' || c == ']'){
          if(st.size() == 0 ) return false;
          if(c == '}' && st.top() != '{') return false;
          if(c == ')' && st.top() != '(') return false;
          if(c == ']' && st.top() != '[') return false;
          st.pop();

       }
      else {
          st.push(c);
      }
  }
// if empty return true else false
return (st.empty());
}

int main()
{
  // true cases
  string s1 = "{}"; // gives true; want false
  string s2 = "{}[]";
  string s3 = "{()}";
  cout<<"Checking for true cases: "<<endl;
  cout<<"Is "<<s1<<" valid? "<<isValid(s1)<<endl;
  cout<<"Is "<<s2<<" valid? "<<isValid(s2)<<endl;
  cout<<"Is "<<s3<<" valid? "<<isValid(s3)<<endl;
  cout<<endl;

  // false cases
  cout<<"Checking false cases: "<<endl;
  string s4 = "{]";
  string s5 = "{[(]";
  string s6 = "([)]";
  cout<<"Is "<<s4<<" valid? "<<isValid(s4)<<endl;
  cout<<"Is "<<s5<<" valid? "<<isValid(s5)<<endl;
  cout<<"Is "<<s6<<" valid? "<<isValid(s6)<<endl;


  return 0;
}
