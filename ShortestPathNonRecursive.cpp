#include <iostream>
#include <string> 
using namespace std;
const int rows = 5;
const int cols = 6;
string path[rows][cols]; // declare a path matrix, it is a string matrix

int calculateCost(int i, int j) {
 // Calculates the cost of every square and fills in the cost matrix.
    static int weight[rows][cols] = {
        {3,4,1,2,8,6},
        {6,1,8,2,7,4},
        {5,9,3,9,9,5},
        {8,4,1,3,2,6},
        {3,7,2,8,6,4}
    };
    static int cost[rows][cols] = { 0 }; // declare the  matrix
    if(cost[i][j] != 0) // If the cost has already been calculated
        return cost[i][j]; //return it.
// For each remaining column,
      // Calculate the cost of each square in the column (non-recursively),
      // and store the correct number in the cost matrix and the correct string in the path matrix.
    // base case (leftmost column)
    if (j == 0) {
        path[i][j] = to_string(i); // update the base case path matrix
        return weight[i][j];
    }
// Calculate the cost of each square in the column (non-recursively),
      // and store the correct number in the cost matrix and the correct string in the path matrix.

    int up = calculateCost((i+rows-1)%rows, j-1); 
    int left = calculateCost(i, j-1); 
    int down = calculateCost((i+1)%rows, j-1); 
    int minCost = min(min(up, left), down);
  
  // Check which square in the rightmost column has the lowest cost.  Store that cost in minLength and the row number in minRow.
    if(minCost == up)
        path[i][j] = path[(i+rows-1)%rows][j-1] + to_string(i);
    else if(minCost == left)
        path[i][j] = path[i][j-1] + to_string(i);
    else
        path[i][j] = path[(i+1)%rows][j-1] + to_string(i); // update the path matrix
    
    cost[i][j] = minCost + weight[i][j];
   

    return cost[i][j];
}
//the main function that will check the costs for teh rows and columns int i and j in other words.
int main() {
    int ex[rows];
    int rowIndex = 0; 
    for (int i = 0; i < rows; i++)
        if (calculateCost(i, cols - 1) < calculateCost(rowIndex, cols-1)) 
            rowIndex = i; 

    cout << "The shortest path is of length " << calculateCost(rowIndex, cols-1) << endl;
    cout << "The rows of the path from left to right are " << path[rowIndex][cols-1] << endl;
    return 0;
}