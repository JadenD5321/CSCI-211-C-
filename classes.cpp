// Rat class i.e. a class for rational numbers
// Private:The user has no access to it. Even though the program is visible. Protected members cannot be accessed as well. I will think of it like a private organization.

// Public: Public can have access to anything within the program. A function will run when you declare a variable 
#include <iostream>
#include <cmath>
using namespace std;

class Rat{
private:
   int n;
   int d;
   
public:
   // constructors(Another way to intialize a function for the operators)
  
   // default constructor(it prints out a bunch of errors since you have not intialized n and d into the rat) Also you can tell its a default since you have not declared anything inside the bracket box(). 

   Rat(){
      n=0;
      d=1;
   }
   
   // 2 parameter constructor
   Rat(int i, int j){
      n=i;
      d=j;
   }
   
   // conversion constructor
   Rat(int i){
      n=i;
      d=1;
   }
   
   //accessor functions (usually called get() and set(...) )
   int getN(){ 
     return n;
     }
   int getD(){ 
     return d;}

   
   void setN(int i){
     n=i;
     }
   void setD(int i){
     d=i;
     }
   
   //arithmetic operators
   Rat operator+(Rat r){
      Rat t;
      t.n = n*r.d + d*r.n;
      t.d = d*r.d;
      return t;
   }
   
   // Write the other 3 operators (operator-, operator*, operator/).
// operator- Sub
  Rat operator-(Rat r){
      Rat t;
      t.n = n*r.d - d*r.n;
      t.d = d*r.d;
      t.reduce();
      return t;
   }
// operator* multiplication
   Rat operator*(Rat r){
      Rat t;
      t.n = n*r.n;
      t.d = d*r.d;
      t.reduce();
      return t;
   }
// operator division
   Rat operator/(Rat r){
      Rat t;
      t.n = n*r.d;
      t.d = d*r.n;
      t.reduce();
      return t;
   }

  // Write a function to reduce the Rat to lowest terms, and then you can call this function from other functions.
   void reduce(){
      int gcd_ = gcd(n, d);
      n /= gcd_;
      d /= gcd_;
      if (d < 0) { 
         d = -d;
         n = -n;
      }
   }
// we have to make sure that it ends in a postive value(Specifically the denominator)
   // Calculate the GCD (Euclid's algorithm)
   int gcd(int n, int d){
      return d == 0 ? n : gcd(d, n%d);
   }

   // 2 overloaded i/o operators
   friend ostream& operator<<(ostream& os, Rat r);
   friend istream& operator>>(istream& is, Rat& r);
}; //end Rat


// operator<<() is NOT a member function but since it was declared a friend of Rat
// it has access to its private parts.
ostream& operator<<(ostream& os, Rat r){
   // Rewrite this function so that improper fractions are printed as mixed numbers.  For example:
   // 3/2 should be printed as 1 1/2
   // 1/2 should be printed as 1/2
   // 2/1 should be printed as 2
   // 0/1 should be printed as 0
   // Negative numbers should be printed the same way, but beginning with a minus sign

 if (abs(r.n) >= r.d || r.n == 0)
      os << r.n/r.d << " ";
   if (r.d != 1)
      os << (r.n/r.d <= -1 ? abs(r.n%r.d) : r.n%r.d) << "/" << r.d;  
   return os;
}

// operator>>() is NOT a member function but since it was declared a friend of Rat
// it has access to its private parts.
istream& operator>>(istream& is, Rat& r){
   is >> r.n >> r.d;
   return is;
}




int main() {
   Rat r1(5, 2), r2(3, 2);
   
   cout << "r1: " << r1 << endl;
   cout << "r2: " << r2 << endl;
   cout << "r1 + r2: " << r1 + r2 << endl;
   cout << "r1 - r2: " << r1 - r2 << endl;
   cout << "r1 * r2: " << r1 * r2 << endl;
   cout << "r1 / r2: " << r1 / r2 << endl;
   cout << endl;
   
   r1 = r2;
   r2 = r1 * r2;
   
   cout << "r1: " << r1 << endl;
   cout << "r2: " << r2 << endl;
   cout << "r1 + r2: " << r1 + r2 << endl;
   cout << "r1 - r2: " << r1 - r2 << endl;
   cout << "r1 * r2: " << r1 * r2 << endl;
   cout << "r1 / r2: " << r1 / r2 << endl;
   cout << endl;
   
   r1 = r2 + r1 * r2 / r1;
   r2 = r2 + r1 * r2 / r1;
   
   cout << "r1: " << r1 << endl;
   cout << "r2: " << r2 << endl;
   cout << "r1 + r2: " << r1 + r2 << endl;
   cout << "r1 - r2: " << r1 - r2 << endl;
   cout << "r1 * r2: " << r1 * r2 << endl;
   cout << "r1 / r2: " << r1 / r2 << endl;
   
   return 0;
}
