/*
A company is planning to interview 2n people. Given the array costs where costs[i] = [aCosti, bCosti], 
the cost of flying the ith person to city a is aCosti, and the cost of flying the ith person to city b is bCosti.

Return the minimum cost to fly every person to a city such that exactly n people arrive in each city.
*/

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int cost=0;
        int n = costs.size();
        
        sort(costs.begin(),costs.end(),[](vector<int> &A , vector<int> &B)
             {
                 if(A[1]-A[0] >B[1]-B[0])
                     return true;
                 return false;
             });
        
        for(int i=0;i<n/2;i++)
        {
            cost = cost+costs[i][0];
        }
        
        for(int i=n/2;i<n;i++)
        {
            cost = cost + costs[i][1];
        }
        
        return cost;
    }
};
