#include <iostream>
#include <vector>
using namespace std;

// observations:
// profit: selling price - cost price
// decreasing order will always be a loss
// order matters
// wanna do SP - CP
// gotta keep track of max

/*
brute force:
- want profit so SP>CP so, scan array
such that from the left all are assumed to be CP
and from the right all are assumed to be SP
- two pointers running opposite directions
- only calculate max when SP>CP
- update max when it is
- so, should do for all and skip when not
- meaning no computation for descending order
- also means coming up with permutations
*/

// runtime: 760 ms
// memory: 9.5 MB
// time complexity: O(n^2)
// space complexity: O(1)
int maxProfit_brute(vector<int>& prices) {
    int max = 0;
    for(int i=0; i<prices.size(); i++)
    {
      for(int j=prices.size()-1; j>i; j--)
      {
          if(prices[j]>prices[i])
          {
            if(prices[j]-prices[i]>max){
              max = prices[j]-prices[i];
            }
          }
      }
    }
    return max;
}

/*
intuition tells me I want this to happen in one pass!
additionally, i always need to know:
(1) max profit
(2) min price
- so, as you scan array, keep track of min price so far
and max profit so far
- key is understanding want to find max once min is found
- had the right idea of subarrays like mergesort
*/
// runtime: 8ms
// memory: 9.3 MB (less than 100% of solutions!)
// time complexity: O(n) --> single pass!
// space complexity: O(1) --> two variables used!
int maxProfit_initial(vector<int>& prices){
  int min_price = INT_MAX; // largest possible integer
  int max_profit = 0;
  for(int i=0; i<prices.size(); i++)
  {
    if(prices[i]<min_price){
      min_price = prices[i];
    }
    else if(prices[i] - min_price > max_profit){
      max_profit = prices[i] - min_price;
    }
  }
  return max_profit;
}

// runtime: 4ms (98.22% faster!)
// memory: 9.6 MB (less than 74% solutions)
// alternatively:
int maxProfit(vector<int>& prices){
  int min_price = INT_MAX; // largest possible integer
  int max_profit = 0;
  // auto loop method
  for(int price : prices)
  {
      int profit = price - min_price;
      // update max
      max_profit = max(max_profit, profit);
      // update min
      min_price = min(price, min_price);
  }
  return max_profit;
}

int main()
{
  // compile using C++11 so, in terminal:
  // $ g++ FILE_NAME.cpp -std=c++11
  // vector initialization like this is in C++11
  vector<int> v1 = {7, 1, 5, 3, 6, 4};
  vector<int> v2{7, 6, 4, 3, 1};
  cout<<maxProfit(v1)<<endl;
  cout<<maxProfit(v2)<<endl;
  return 0;
}
