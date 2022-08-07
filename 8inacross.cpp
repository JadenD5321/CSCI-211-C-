// Programming proccess of this code. 
// Has to be between 1-8 inside the array.
#include <iostream>
using namespace std; 

  void printCross(int cross[]){
    static int sol = 0;
    cout << "Solution#" << ++sol << ":\n";
    cout << " " << cross[0] << cross[1] << endl;
    cout << cross[2] << cross[3] << cross[4] << cross[5] << endl;
    cout << " " << cross[6] << cross[7] <<endl;
    cout<<endl;
   return;
}
// using a helperArray to  determine whats adjacent to each other. 
bool okay(int q[], int c){
  // q[] the actual array we are checking 
  // int c is the current index  of the array we are checking where the position is placed. If c= position 2, then we are checking that position 2 and so forth. 

//helperArray= tells us what boxes we need to check. We have to look at each box accordingly.  
    static int helperArray[8][5] ={
  // We are using 5 in the helperArray to determine the largest number that is stored in the box.
  		{-1},  // position 0; -1 is a sentinel value (to stop checking)
  		{0,-1}, // position 1 checks 0.
  		{0,-1},    // position 2, we are looking at 0.
  		{0,1,2,-1}, // position 3, we are looking at 0 1 and 2.
  		{0,1,3,-1}, // position 4 we are looking at 0,1, and 3
  		{1,4,-1},   // position 5, we are looking at 1 and 4 
  		{2,3,4,-1}, // position 6 we are looking at 2,3, and 4.
  		{3,4,5,6,-1}// position 7 we are looking at 3,4, and 5.
// each element ends with -1 to break the loop in each position
  } ;
  // we are doing the uniqueness test 
  // every element is equal
	for (int i = 0; i < c; i++)
    // if two boxes contain the same number inside the boxes, regardless of whether they are adjacent to each other, then we will return false. 
		if (q[c] == q[i]) return false;
  
//adjacent test 
//helperArray[c][i] = ith neighbor of position c. In other words it means the position of the ith neighbor.
// We do absolute value because we do not know the order value. Absolute value basically subsittues with negaitve 1. We return false since rules are broken. It will be true if there are consecutive neighbors.

for(int i = 0; helperArray[c][i] != -1; i++) {
  // We are looping through the helperArray at index c position until we reach -1. Once we reach -1 we stop.
        if  (abs(q[ helperArray[c][i] ] - q[c] )== 1) 
            return false;
  // we cannot have a difference of 1 between two adjacent. Once we store them in the index
  }
    return true; // if we basically went through each boxes successfully and we didnt have any issues within the adjacency test.
}


//fills in the positions of the cross, ensuring each new value is okay
//if a valid 8-cross solution is found, prints the solution
//if ever stuck, backtracks and tries another set of answers






// review this part of the code
int main() {
    int q[8], col = 0;
  
     q[col] = 1;
  // q[0]=1 will be our first value 
  
    // Start at the first position in the cross
    // while we have not backtracked beyond the first index
    while (col >= 0){
      
       col++;
    // If we have exceed our last index
        if (col > 7){
            printCross(q);// printCross
            // backtrack
            col--; // we backtrack and print them out. 
          if(col < 0) return 0;
        }
       else q[col] = 0;
        // If we have run out of numbers to try
      
      while( col >= 0) {

         q[col]++;
        
        if(q[col] > 8){

         // backtrack
            col--;
            if (col < 0) return 0;
        }
        // if the number we placed in the position is okay and successfully does not have any issue with tests, then we can pass it through the column and terminate our loop.
           if (okay(q, col)) 
              break;
            // We can terminate the loop once we have       
          }
       }
    return 0;
  }