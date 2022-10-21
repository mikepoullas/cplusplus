// COMP5421 - Assignment 1
// Mike Poullas - 21917739
// main.cpp

#include<iostream>
//#include<cassert> ** Uncomment to run all other driver code 
//#include<string>  ** Uncomment to run all other driver code 

//#include "ArrayList.h"  ** Uncomment to run ArrayList driver code 
//#include "Token.h"      ** Uncomment to run Token driver code 
//#include "TokenList.h"  ** Uncomment to run TokenList driver code 
#include "Dictionary.h"

using std::cout;
using std::endl;
using std::string;
using std::cin;

int main()
{
/*
 std::cout << "Testing ArrayList!" << endl << endl;
 ArrayList list{};
 cout << "list-1 -> " << list << endl;
 assert(list.getCapacity() == 1);

 list.pushback(19);
 cout << "list-2 -> " << list << endl;
 assert(list.getCapacity() == 1);
 assert(list.size() == 1);

 list.pushback(32);
 cout << "list-3 -> " << list << endl;
 assert(list.getCapacity() == 2);
 assert(list.size() == 2);

 list.pushback(21);
 cout << "list-4 -> " << list << endl;
 assert(list.getCapacity() == 4);
 assert(list.size() == 3);

 list.pushback(7);
 cout << "list-5 -> " << list << endl;
 assert(list.getCapacity() == 4);
 assert(list.size() == 4);

 list.pushback(18);
 cout << "list-6 -> " << list << endl;

 // Using the print statement  
 cout << "list-6 -> "; list.print(cout); cout << "\n";
  
 assert(list.getCapacity() == 8);
 assert(list.size() == 5);

 cout << "ArrayList Test Successful" << endl << endl;

 std::cout << "Testing an Object of Class Token" << endl << endl;
 Token t1{ "Hello", 1 };

 // ideally we want to print t1 like this (easy to implement)
 cout << "A) t1: " << t1 << "\n";

 //cout << "A) t1: "; t1.print(cout); cout << "\n";
 t1.addLineNumber(11);
 t1.addLineNumber(13);
 t1.addLineNumber(74);
 t1.addLineNumber(92);
 cout << "B) t1: " << t1 << "\n";

  // Use the copy constructor (not copy assignment) 
 Token t2 = t1; 
 t1.addLineNumber(11111);
 cout << "C) t1: " << t1 << "\n";
 cout << "D) t2: " << t2 << "\n";

 t2 = t1; // copy assignment
 cout << "E) t1: " << t1 << "\n";
 cout << "F) t2: " << t2 << "\n";
 
 Token t3 = std::move(t2); // move constructor
 cout << "G) t3: " << t3 << "\n";
 cout << "H) t2: " << t2 << "\n"; // warning C26800:
 // Use of a moved from object

 t1 = std::move(t3); // move assignment
 cout << "I) t3: " << t3 << "\n"; // warning C26800:

 // Use of a moved from object
 cout << "J) t1: " << t1 << "\n";

 ArrayList ia = t1.getNumberList();
  
 cout << "J) ia: " ; ia.print(cout); cout << "\n";

  // Tokenlist
 std::cout << "Testing TokenList " << endl << endl;
  
 TokenList bucket;

 Token t4("Hello", 1);
 bucket.addSorted(t4);

 Token t5("Hello", 11);
 bucket.addSorted(t5);

 Token t6("Hello", 111);
 bucket.addSorted(t6);

 Token tArray[]{ Token("How", 1), Token("are", 11), Token("you", 2),
                 Token("today?", 22), Token("#tag", 3), Token("yuzz-a-ma-tuzz-boo", 3) };
 for (Token t : tArray) {
     bucket.addSorted(t);
 }

 // ideally we prefer cout << bucket << endl;
 bucket.print(cout); 
 cout << endl;
*/
 
 // Dictionary
 std::cout << "Dictionary Processing" << endl << endl;
 
 cout << "Enter the name of input text file: " ;
 string filename;
 cin >> filename;
 
 Dictionary dictionary(filename);
 dictionary.print(cout);

 return 0;
}

