#include<iostream>
#include<cmath>
using namespace std;

int main(){
int q[8] = {0},c = 0; 
q[0] = 0;


nextcolumn:
    c++;
    if(c== 8) goto print;
    q[c] = -1;
// go to the next column 

nextrow:
    q[c]++;
    if(q[c]==8)
      goto backtrack;

  for(int k = 0; k<c; k++){
        if(q[k] == q[c] || (c-k) == abs(q[c]- q[k]))
          // this line forms the absolute value function for the rows and columns 
	goto nextrow; 

  }

// not using a row variable 

        // check to see if we’re in row 8 

        // if we are……….. backtrack

        //do UR TESTS

        // if you fail UR TESTS u go 2 nextRow

        // if you pass UR TESTS u go 2 next column

     goto nextcolumn;
backtrack:
    c--;
    if(c == -1) return 0;
//go to the previous column 

// if column is equal to 2 -1 u done all solutions r found 

    goto nextrow;
print:
  static int solution = 1;
  cout << "solution: "<< solution++ << endl;
// the solution basically works eachtime the loop runs successfully 
  for(int k = 0; k<8; k++)
      {
      for(int w = 0; w < 8; w++){
            if(q[k] == w){
                cout << 1;
            }
            else{
               cout << 0;
            }
        }

          cout << endl;
        }
    cout << endl;

    goto backtrack;

}


// once the code is on backtrack, it means that all the running executions are complete.

