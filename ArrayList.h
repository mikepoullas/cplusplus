// COMP5421 - Asg1
// Mike Poullas - 21917739
// ArrayList.h

#ifndef ArrayList_H
#define ArrayList_H

#include <iostream>
using std::ostream;

class ArrayList {
private:
	int *pArray;
	int capacity;
	int used;
  // Double the current capacity of the list. Private method.
  void resize(); 

public:
	ArrayList();
  // Copy constructor
	ArrayList(const ArrayList &array);
  // Move constructor
	ArrayList(ArrayList &&array);	      

  // Copy assignment operator
	ArrayList &operator=(const ArrayList &rhs);
  // Move assignment operator
	ArrayList &operator=(ArrayList &&rhs);		

  // Destructor (and a virtual one in this example)
	virtual ~ArrayList(); 

	bool empty() const; // Determines whether used equals zero
	bool full() const;  // Determines whether used equals capacity
	int size() const;   // Returns used

	void pushback(int x); // Inserts x at position used and then increments used by 1
	bool contains(int x) const; // Determines whether x occurs in the list
	bool get(int position, int &value) const; // Returns false if position is out of range; otherwise, places the value stored at position in the reference parameter value and then returns true.
	int getCapacity() const; // Returns the allocated capacity of this list
	void print(std::ostream& sout); // Prints the numbers in the list to the sout stream, separating them by a comma followed by a space
	friend ostream& operator << (ostream& sout, const ArrayList& list); // Overloading the insertion operator
};

ostream& operator << (ostream& sout, const ArrayList& list);

#endif // ArrayList_H

