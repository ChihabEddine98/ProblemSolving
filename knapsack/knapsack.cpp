/* A Dynamic programming version for Knapsack problem */

#include <bits/stdc++.h> 
using namespace std; 

// weights , profits vector will be an inchanged array in all the code
int weights[]={3, 4, 5, 9, 4}; 
int profits[]={3, 4, 4, 10, 4}; 

// knapsack(n: #objects , C:capacity) : result [maximum profit we can get from availaible objects]
// naive version in O(2^n)
int knapsack(int n,int C) 
{ 

	// Base Case 
	if (n == 0 || C == 0) 
		return 0; 

	// If weight of the nth item is more 
	// than Knapsack capacity C, then 
	// this item cannot be included 
	// in the solution
	if (weights[n - 1] > C) 
		return knapsack(n-1,C); 

	// Return the maximum of two cases: 
	// (1) not included   
	// (2) nth item included
	else
        return max(knapsack(n-1,C),profits[n-1]+knapsack(n-1,C-weights[n-1]));
} 

int main(int argc,char* argv[]) 
{ 
    
	int C = 11; 
	int n = sizeof(profits) / sizeof(profits[0]); 
	cout << knapsack(n,C); 
	return 0; 
} 

