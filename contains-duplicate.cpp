#include <iostream>
#include <map>
#include <vector>
#include <unordered_set>
using namespace std;

// approach #1: waste of space
// in the case of distinct, create a map for no reason
// 60 ms of runtime
// 16.7 MB of memory

bool containsDuplicate_map(vector<int>& nums){
  // key: element in arr
  // value: occurence of element in arr (calling this count)
  map<int, int> m;

  for(int i=0; i<nums.size(); i++){
    // look back to find a match
    if(m.find(nums[i])!=m.end()){
        // increment count
        m[nums[i]]++;
        // only add once
        // which happens when count = 1
        if(m[nums[i]]==1){
        // pushback # which was a duplicate
        return true;
      }
    }
    else{
      // "count" is 0
      m.insert(pair<int,int>(nums[i], 0));
    }
    }
  // if wanted sorted: sort(res.begin(), res.end());
  //sort(res.begin(), res.end());
  // but this adds O(n log n) to time complexity
  // But this algorithm's time complexity would still be O(n)
  return false;
}

// don't need to increment and all
// just need to find
// runtime: 52ms
// memory: 16.7 MB

bool containsDuplicate_map2(vector<int>& nums){
  // key: element in arr
  // value: occurence of element in arr (calling this count)
  map<int, int> m;

  for(int i=0; i<nums.size(); i++){
    // look back to find a match
    if(m.find(nums[i])!=m.end()){
        return true;
      }
      // "count" is 0
      m.insert(pair<int,int>(nums[i], 0));
    }
  return false;
}

// again, you realized you don't need to count
// its occurence, just see if it exists!
// so why have a map, only keeping track of one thing
// time complexity: O(n) --> do search + insert n times
// space complexity: O(n) --> set of n elements
bool containsDuplicate(vector<int>& nums) {
  // but don't need a map b/c just seeing if duplicates exist
  // map<int, int> m;
  unordered_set<int> m;
  for(int i=0; i<nums.size(); i++){
    // look back to find a match
    if(m.find(nums[i])!=m.end()){
        return true;
    }
      // put in set
      m.insert(nums[i]);
    }
  return false;
}

int main()
{
  vector<int> a{1,2,3,4};
  cout<<containsDuplicate(a)<<endl;
  return 0;
}
