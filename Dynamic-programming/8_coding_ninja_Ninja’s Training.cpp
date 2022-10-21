#include<bits/stdc++.h>
using namespace std;

//  recursion solution

int max_merit(vector<vector<int>>points ,int day,int last){
    
    if(day==0){
        int max_point=INT_MIN;
        for(int i=0;i<=2;i++){
            if(i!=last){
                max_point=max(max_point,points[0][i]);
            }
        }
        return max_point;
    }
    
    int sum=0;
    int point=INT_MIN;
    for(int i=0;i<=2;i++){
        if(i!=last){
            sum=points[day][i]+max_merit(points,day-1,i);
            point=max(point,sum);
        }
    }
    return point;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    return max_merit(points,n-1,3);
}

// memoization 

#include <bits/stdc++.h>

using namespace std;

int f(int day, int last, vector<vector<int>> &points,vector<vector<int>> &dp) {

  if (dp[day][last] != -1) return dp[day][last];

  if (day == 0) {
    int maxi = 0;
    for (int i = 0; i <= 2; i++) {
      if (i != last)
        maxi = max(maxi, points[0][i]);
    }
    return dp[day][last] = maxi;
  }

  int maxi = 0;
  for (int i = 0; i <= 2; i++) {
    if (i != last) {
      int activity = points[day][i] + f(day - 1, i, points, dp);
      maxi = max(maxi, activity);
    }

  }

  return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector < vector < int > > & points) {

  vector < vector < int > > dp(n, vector < int > (4, -1));
  return f(n - 1, 3, points, dp);
}