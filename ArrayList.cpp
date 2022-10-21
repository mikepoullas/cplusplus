// COMP5421 - Asg1
// Mike Poullas - 21917739
// ArrayList.cpp

#include "ArrayList.h"

// Default Constructor of class ArrayList
ArrayList::ArrayList(): capacity{1}, used{0}, pArray{new int[1]} {};

// Copy constructor
ArrayList::ArrayList(const ArrayList& array)
	: pArray(new int[array.capacity]),
	  capacity(array.capacity),
	  used(array.used) {				 
      // Only loop through up to used
	    for (int i = 0; i < array.used; i++) 
		    pArray[i] = array.pArray[i];
}

// Move constructor
ArrayList::ArrayList(ArrayList&& array)
	: pArray(array.pArray),
	  capacity(array.capacity),
	  used(array.used) { 
	    array.pArray = nullptr;
}

// Copy assignment operator
ArrayList &ArrayList::
operator=(const ArrayList& rhs) { 
	if (this != &rhs) {
		delete[] pArray;
		pArray = new int[rhs.capacity];
    // Only loop through up to used size
		for (int i = 0; i < rhs.used; i++)  
			pArray[i] = rhs.pArray[i];

    capacity = rhs.capacity;
		used = rhs.used;
	}
	return *this;
}

// Move assignment operator
ArrayList &ArrayList::operator=(ArrayList&& rhs) { 
	if (this != &rhs) {
		delete[] pArray;
		pArray = rhs.pArray;
		capacity = rhs.capacity;
		used = rhs.used;
		rhs.pArray = nullptr;
	}
	return *this;
}

// Destructor of class ArrayList
ArrayList::~ArrayList() {
	// delete pArray
	delete[] pArray;
}

// Determines whether used equals zero
bool ArrayList::empty() const {
  return (used == 0);
}

// Full function returns whether ArrayList is full to capacity
bool ArrayList::full() const {
	return (used == capacity);
}

// Returns size of used
int ArrayList::size() const {
	return used;
}

// Doubles the ArrayList capacity
void ArrayList::resize() {

  // Double the size of capacity
	capacity = capacity * 2;

	// Initialize a temp array with a larger capacity
	int *tempArrayList = new int[capacity];

	// Copy to the tempArrayList all the elements in pArray
	for (int i = 0; i < used; i++) {
		tempArrayList[i] = pArray[i];
	}

	// Delete pArray
	delete[] pArray;

	// Point pArray to tempArrayList address
	pArray = tempArrayList;

	// Assign tempArrayList as a null pointer
	tempArrayList = nullptr;
  
}

// Adds number at the position of used in ArrayList
void ArrayList::pushback(int x) {

  if (full()) {
		resize();
	}

	pArray[used] = x;

	used++;
}

// Determines whether x occurs in the list
bool ArrayList::contains(int x) const {
    if (!empty()){
        for(int i = 0; i < used; i++){ // Only loop through up to used size
            if (pArray[i] == x)
                return true;
        }
    }
    return false;
}

// Returns false if position is out of range; otherwise, places the value stored at position in // the reference parameter value and then returns true.
bool ArrayList::get(int position, int& value) const { 
    if (position > used || position < 0)
        return false;
    else {
        value = pArray[position];
        return true;
    }
}

// Returns the size of the ArrayList
int ArrayList::getCapacity() const {
	return capacity;
}

// Prints the numbers in the list to the sout stream, separating them by a comma followed by a // space
void ArrayList::print(std::ostream& sout){ 
    for(int i = 0; i < used; i++){
        if (i == used - 1)
            sout << pArray[i];
        else
            sout << pArray[i] << ", ";
    }
    sout << std::endl;
}

// Overload the <<. SOUT is sent back for output
ostream &operator<<(ostream &sout, const ArrayList &list) {
	for (int i = 0; i < list.size(); i++)
		sout << list.pArray[i] << " ";

	return sout;
}