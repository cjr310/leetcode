// Suppose you have a random list of people standing in a queue. 
// Each person is described by a pair of integers (h, k), 
// where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. 
// Write an algorithm to reconstruct the queue.

// Example

// Input:
// [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

// Output:
// [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]



#include<vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(),[](vector<int>&a, vector<int>&b){
            return a[0]>b[0]||(a[0]==b[0]&&a[1]<b[1]);
        });
        for(int i=0; i<people.size(); ++i){
            auto p = people[i];
            if(p[1]!=i){
                people.erase(people.begin() + i);
                people.insert(people.begin()+p[1], p);
            }
        }
        return people;
    }
};

//思路，先按照大到小排序，如果第一个数相同，按从小到大排。然后把排序错误的位置擦去，插入正确的位置。