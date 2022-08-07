#include <iostream>
#include <cmath>
using namespace std;

void print(int q[]);// calls function
bool okay(int q[], int c); // calls function
void backtrack(int q[], int &c); // calls function

int main() {

  int q[8] = {}, c = 0; // 8 x 8 chessboard
  q[0] = 0;// initialize array to 0
    while (c >= 0) { // backtract from the first column
      c++;
      if (c == 8) { // backtrack if we are in the last column
        print(q);
        backtrack(q, c);
    } else {
        q[c] = -1;
    } while (c >= 0) {
      q[c]++;
        if (q[c] == 8) {// we backtract when we reach the end of the column
          backtrack(q, c);
        } else {
          if (okay(q, c))
            break;// go back to the loops beginning
        }
      }
    }
  return 0;
}

void print(int q[]) {
  
  int i, j;
  // here we just fill out the board w/ black boxes and the white boxes
  typedef char box[5][7]; // dataype "box" will be the array used for the black and white queens
  box bb, wb,bq, *board[8][8];// establish white and black queens which will go in each of the boxes also establishing the 8 x 8 board
  

  // desigun for black queen 
  static box BQ = { {'*','*','*','*','*','*','*'},
                     {'*',' ','*',' ','*',' ','*'},
                     {'*',' ',' ','*',' ',' ','*'},
                     {'*',' ','*',' ','*',' ','*'},
                     {'*','*','*','*','*','*','*'} 
                     };
  // design for white queen     
    static box wq = { {' ','*',' ',' ',' ','*',' '},
                     {' ',' ','*' ,' ','*',' ',' '},
                     {' ' ,' ',' ','*',' ',' ',' '},
                     {' ' ,' ','*',' ','*',' ',' '},
                     {' ','*',' ',' ',' ','*',' '} 
                     };
  /* i designed it in this format of listing every element in 1 array is because I thought it was better and easier for me to look at visually rather than the way we did in class w/ marking the coordinates of the 5 by 7 array, bc it was easier for me to look at it as a 5 x 7 matrix on the computer.
  */
  
  for (i = 0; i < 5; i++)// each box is again a 5 x 7 array 
    for (j = 0; j < 7; j++) 
    {
      wb[i][j] = ' ';// fills up the white squares
   
      bb[i][j] = '*';// fills up the black squares
     
    }

  static int solution = 0;
  cout << "Solution # " << solution++ << ":" << endl;
  
   // Print upper border, done in lab
   for (i=0; i<7*8; i++){
      cout << '_';
   }
   cout << endl;

// print the boxes with the pointers in array board
  for (i = 0; i < 8; i++)
    for (j = 0; j < 8; j++)
      if ((i + j) % 2 == 0) {/* if the box is odd its a black box if the box is even its a white box */
        if (q[i] == j) {
          board[i][j] = &wq;
        } else {
          board[i][j] = &wb;
        }
      } else {
        if (q[i] == j) {
          board[i][j] = &BQ;
        } else {
          board[i][j] = &bb;
        }
      }
       
  int k, l;
  for (i = 0; i < 8; i++)// 8 x 8 chessboard
    for (k = 0; k < 5; k++){
      cout << "   " << "|"; // prints the left boarder
      for (j = 0; j < 8; j++)
        for (l = 0; l < 7; l++)
          cout << (*board[i][j])[k][l];
        cout << "|" << endl;   
    }
// prints out the lower boarder, done in lab
cout << " ";
   for (i=0; i<7*8; i++)
      cout << '=';
   cout << endl;
}

bool okay(int q[], int c) {// bool okay function from previous projects
  for (int i = 0; i < c; i++) 
    if (q[i] == q[c] || c - i == abs(q[c] - q[i]))
      return false;
      return true;  
}

void backtrack(int q[], int &c) {
  c--;
  if (c == -1) { 
    exit(0);
  q[c]++;  
  }
}