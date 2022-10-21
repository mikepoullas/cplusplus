// COMP 5421 Assignment 1
// Mike Poullas - 21917730
// TokenList.cpp

#include "TokenList.h"
#include "Token.h"

using std::cin;
using std::endl;

//Default constructor
TokenList::TokenList(): head {nullptr}, tail{nullptr}, theSize{0} {}

// Copy constructor
TokenList::TokenList(const TokenList& list): head(nullptr), tail(nullptr), theSize(0) { 
  TNode* curFirst = list.head->next;
  TNode* newFirst = head;
  
  // Loop through list to copy all items
  while (curFirst != list.tail) {
    //addAfter(newFirst, curFirst->theToken);
    curFirst = curFirst->next;
    newFirst = newFirst->next;
  }
}

// Move constructor
TokenList::TokenList(TokenList&& list): head(list.head), tail(list.tail), theSize(list.theSize) {
    list.head = nullptr;
    list.tail = nullptr;
    list.theSize = 0;
}

// Copy assignment operator
TokenList& TokenList::operator=(const TokenList& rhs){ 
  if (this != &rhs) {

    TNode* prevFirst = head->next;
    TNode* temp;
    
    while (prevFirst != tail) {
      temp = prevFirst;
      prevFirst = prevFirst->next;
      delete temp;
    }

    delete head;
    delete tail;

    // Create new head and tail pointers
    TNode* head {nullptr};
    TNode* tail {nullptr};
    
    TNode* first = rhs.head->next;
    TNode* newFirst = head;

    while (first != rhs.tail) {
      //addAfter(newFirst, first->theToken);
      first = first->next;
      newFirst = newFirst->next;
    }
  }
  
  return *this;
};


// Move assignment operator
TokenList& TokenList::operator=(TokenList&& rhs){ // Move assignment operator
  if (this != &rhs) {
    TNode* prevFirst = head->next;
    TNode* temp;
    while (prevFirst != tail) {
      temp = prevFirst;
      prevFirst = prevFirst->next;
      delete temp;
    }
    head = rhs.head;
    tail = rhs.tail;
    theSize = rhs.theSize;
    rhs.head = nullptr;
    rhs.tail = nullptr;
  }
  
  return *this;
};


// Destructor (and a virtual one in this example)
TokenList::~TokenList(){ 

  TNode* currentNode = head;
  TNode* nextNode;

  while (currentNode != tail) {
      nextNode = currentNode->next;
      delete currentNode;
      currentNode = nextNode;
  }
  
  // Final pointer left outside of while loop is tail so delete it
  delete tail;
}

// Returns T or F if list size is zero
bool TokenList::empty() const {
  return (theSize == 0);
} 

// Returns the token at the front of this list
const Token& TokenList::front() const { 
    return (head->next)->theToken;
};

// Returns the token at the back of this list
const Token& TokenList::back() const {
    return (tail->next)->theToken;
};

// Adds aToken at its sorted position into the list so as to maintain the ascending order of the
// tokens in the list
void TokenList::addSorted(const string& str, int lineNum) {

  // Create a new token with string and line number
  Token aToken(str.c_str(), lineNum);
  
  // Lookup node if its in linked list 
  TNode* aNode = lookup(aToken);

  // Token is not in linked list so add first token in the front head->newNode<-tail
  if (aNode == nullptr) {
      addFront(aToken);
    } // aToken is on the list so fetch its line number and add it to the array of line numbers
      else if (aNode->theToken.compare(aToken) == 0) {
        //int num_to_add = aToken.getTokenValue();
        
        (aNode->theToken).addLineNumber(lineNum);
    } // Otherwise, aToken is not on the list, and, to maintain sorter order of the list, it   
      // should be inserted after the node which aNode points at
      else {
        addAfter(aNode, aToken); 
    }

  return;
}

void TokenList::addSorted(const Token& aToken) {
  // Line number to be added to token array list
  int lineNumber {0};
  // Get the list of numbers in token array
  ArrayList listOfLineNumbers = aToken.getNumberList();

  //Get the line number where token is found
  listOfLineNumbers.get(listOfLineNumbers.size()-1, lineNumber);
  // Call addSorted to place token
  addSorted(aToken.c_str(), lineNumber);
}

// If aToken is in the list, it returns a pointer to the node whose token is equal to aToken; 
// otherwise, it returns a pointer to the node after which aToken would be inserted in the sorted
// list.
TokenList::TNode* TokenList::lookup(const Token& aToken) const { 

  // First check if we have an empty Linked List
  if (head == nullptr) 
    return nullptr;

  if (aToken.compare(head->theToken) < 0)
    return nullptr;
  // Previous node in linked list
  TNode* pNode = head;
  // Current node in linked list
  TNode* cNode = head->next;

  while (cNode != nullptr) {
    // Compare the cstr of the two token objects;
    // =0, <0 or >0 for sorting
    if (((cNode->theToken).compare(aToken) > 0)) {
        break;
    }
    // Move to the next node
    pNode = cNode;
    cNode = cNode->next;
    
  }
  // Finally return a node whose token exists at position pNode
  return pNode;
};

// If the list is nonempty, removes the node at the front of the list and returns true
// otherwise returns false
bool TokenList::removeFront(){ 
  if (theSize >= 1) {
      if (remove(head->next))
        return true;
  } 
  
  return false;
}

// If the list is nonempty, removes the node at the end of the list and returns true
// otherwise returns false
bool TokenList::removeBack(){ 
  if (theSize >= 1) {
    // Find the second last node starting from head
    TNode* secondToLastNode = head;

    // Travel linked list to find second to last node
    while ((secondToLastNode->next)->next != nullptr)
      secondToLastNode = secondToLastNode->next;

    // Call remove method to delete it
    if (remove(secondToLastNode->next))
      return true;
  }

  return false;
};

// Returns theSize
size_t TokenList::size() const {
  return theSize;
} 

// Prints the entire list
void TokenList::print(std::ostream& sout) const { 
    if (empty()) {
        sout << " " << endl;
    } else {
        TNode* nodeToPrint = head;

        while (nodeToPrint != nullptr) {
            sout << nodeToPrint->theToken << endl;
            nodeToPrint = nodeToPrint->next;
        }
    }
}

// Determines whether aToken is in the list.
bool TokenList::search(const Token& aToken) const { 
    
  TNode* firstNode = head;
  
  // Travel through LL until we find matching Token or not
  while (firstNode != tail) {
    if ((firstNode->theToken).compare(aToken) == 0) {
        return true;
    }
    firstNode = firstNode->next;
  }
  return false;
}

// Adds a new node storing aToken after the node to which p points. 
// If p is nullptr, it adds the node to the front of the list.
void TokenList::addAfter(TNode* p, const Token& aToken) {
  
  TNode* q {new TNode(aToken)};

  // Make next of new node as next of previous node
  q->next = p->next;

  //move the next of prev_node as new_node
  p->next = q;

  ++this->theSize;

};

// Removes the node aNode points to
bool TokenList::remove(TNode* aNode) { 

   // Make sure we're not deleting the head or tail nodes
   if (aNode != head || aNode != tail){
    // Have to start with the head pointer and travel nodes until we find aNode
    // while assigning prevPtr and currentPtr to be used for removing aNode
    TNode* prevPtr = head; 
    // The first valid node
    TNode* currentPtr = head->next; 
    
    while(currentPtr != nullptr) {
        // Check if we found the token we're looking for
        if (currentPtr == aNode) {
            // Unlink the node to remove
            prevPtr->next = currentPtr->next; 
            // Delete the node aNode
            delete currentPtr; 
            // Set return bool value to true since we found and successfully deleted node
            return true;
        } else {
            // We did not find aNode yet
            // Go to next node
            prevPtr = currentPtr; 
            currentPtr = currentPtr->next; 
        }
    }
  }
  return false; 
}

void TokenList::addFront(const Token& aToken) {

  TNode *newNode { new TNode(aToken, head) };
  
  head = newNode;

  if (tail == nullptr){ 
    tail = head; 
  }

  theSize++;
 
  return;
}
 
void TokenList::addBack(const Token& aToken) {

  TNode* newNode = { new TNode(aToken) };

  if (tail == nullptr) {
    head = tail = newNode;
  } else {
      tail->next = newNode;
      tail = newNode;
  }
  
  theSize++;
  
  return;
}
