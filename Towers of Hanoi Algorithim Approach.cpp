#include <iostream>
#include <vector>
using namespace std;
int main() {
   vector<int> t[3]; // Contains an array of three vectors such as towers A, B and C
   int n;
   cout << "Please enter the number of rings to move: ";
   cin >> n;
   cout << endl;
   // close is the number of spots to move to the right to find the "closest" tower.
   // If (n= number of rings basically) is odd, then I will say close = 1 and far = 2. If n is even, the reverse 
  //push_back add element to the end. We just keep adding an additional element if we want
  // pop_back= removes the previous element. Think of it as backtracking but its really not that. 
// (1,2,3)(1,2,3.,4). Just Added an additional element 
  //pop_back delete the last element
  //back refers only to the last element. For example: (1,2,3) back=3. 
 int close =(n % 2 ==0 ? 2 : 1);int far = (n % 2 == 0 ? 1 : 2); 
// if there are an even amount of rings, close will be 2 and far will be 1. It will be an inverse if there is an odd number of rings. 
//% module
  
// If (n= number of rings basically) is odd, then I will say close = 1 and far = 2.  If n is even, the reverse. far = 1 and close= 2
  
  // if the number disks stored into the tower is odd, then close will be 1 and far will be 2.
  
   int from = 0, to = close, candidate = 1, move = 0;
    if(n%2 == 0) to = 2;
  // Initialize the towers
  // putting all the rings into tower zero.
  //n+1= base. N amount of rings. Base of any ring stored in the +1.
// Also consider n+1 as the base function that stabilizes the tower. N will be the biggest ring, while the top part will be the smallest ring. 
   for(int i = n + 1; i >= 1; --i)
     t[0].push_back(i);
   t[1].push_back(n+1);//adds another element from the bottom of the array 
   t[2].push_back(n+1);//adds another element from the bottom of the array.
   while (t[1].size() < n+1) { // while t[1] does not contain all of the rings. We must attempt to push all the rings to t[1]. Once all rings are stored in t[1], then we can print out the possible moves it will take for the amount of disks stored in the tower. 
      cout << "Move #" << ++move << ": Transfer ring " << candidate << " from tower " << char(from+'A') << " to tower " << char(to+'A') << "\n";


// Review this last part again.
     
      // Move the ring from "from" to "to" (first copy it, then delete it from "from")
    t[to].push_back(t[from].back());
    t[from].pop_back();
     // if we have 4 rings, to will be = 2, from will be = 0
     
     // first line means we will push the ring at the top of
     // t[from] to the top of t[to], then we remove the ring
     // from t[from] with pop_back
     
     // from = the tower with the smallest ring that has not just been moved: (to+1)%3 or (to+2)%3
		if (t[(to+1) % 3].back() < t[(to+2) % 3].back())
      //we want to move in a circle,if to is equal to 2( the last stake), then we will add 1 to it and module by 3 to get back to ring 0.
      // From= Determines the ring we want to move and to determines the stake we want to move the ring to. 
         from = (to+1)%3;
      else
         from =(to+2)%3;
     // if the ring at (2+1)%3 is less than the ring at (2+2)%3
    //3/3= 0 and 4/3=1
      // candidate = the ring on top of the from tower
     
     //  From is the stake where we will take a ring from. Candidate is the ring we will take from(where current ring is located). We look at element at very top.
      candidate = t[from].back();
      // to = the closest tower on which the candidate can be placed: (from+close)%3 or (from+far)%3

     // from = 0. 
     // if n is less than m and you do. n%m, the result will just be n. n= 2 and m=3. So in other words the smaller one will be 2. 
    if (t[(from+1) % 3].back() > candidate)
       
          to = (from+1) % 3;
       
     else 
          to = (from+2) % 3;
     }
  return 0;
}

 