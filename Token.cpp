// COMP5421 - Asg1
// Mike Poullas - 21917739
// Token.cpp

#include "Token.h"
#include <cstring>
#include <iomanip>

using std::setw;
using std::right;

// Normal constructor, creates a new token using the supplied C-string and line
// number
Token::Token(const char* astr, int line_num)
	: cstr(new char[strlen(astr) + 1]), number_list(ArrayList()) {
	strcpy(cstr, astr);
	frequency = 1;
	number_list.pushback(line_num);
}

// Copy constructor
Token::Token(const Token& token)
	: cstr(new char[token.size()]),
	  frequency(token.frequency),
	  number_list(ArrayList(token.number_list)) {
	    strcpy(cstr, token.cstr);
}

// Move constructor
Token::Token(Token&& token) noexcept
	: cstr(token.cstr),
	  frequency(token.frequency),
    number_list(token.number_list) {
      // Release pointer from source object
      token.cstr = nullptr;
      token.frequency = 0;
}

// Copy assignment operator
Token &Token::operator=(const Token& rhs) {
  // Conditional statement that performs no operation 
  // if you try to assign the object to itself
	if (this != &rhs) {
		delete[] cstr;
		cstr = new char[rhs.size() + 1];
		strcpy(cstr, rhs.cstr);
    frequency = rhs.frequency;
		number_list = rhs.number_list;
	}

  return *this;
}

// Move assignment operator
Token &Token::operator=(Token&& rhs) {
  // Conditional statement that performs no operation 
  // if you try to assign the object to itself
  if (this != &rhs) {
    
    // Free the existing resource
		delete[] cstr;
    
		cstr = rhs.cstr;
    frequency = rhs.frequency;
		number_list = rhs.number_list;

    // Release pointer from source object
    rhs.cstr = nullptr;
    rhs.frequency = 0;
  }
  
	return *this;
}

// Destructor of class Token
Token::~Token() {
	delete[] cstr;
}

// Returns a constant pointer to this token’s cstr
const char *Token::c_str() const {
	return cstr;
}

// Add line_num to the end of this token's number list
void Token::addLineNumber(int line_num) {
	frequency += 1;
	number_list.pushback(line_num);
	return;
}

// Returns the length of this token’s cstr
size_t Token::size() const {
	return (int)strlen(cstr);
}

// Prints this token’s cstr followed by its number_list.
void Token::print(std::ostream &sout) {
  sout << c_str() << " ";
	number_list.print(sout);
}

const ArrayList &Token::getNumberList() const {
	return number_list;
}

// Returns -1, 0, or 1, depending on whether this token’s cstr is less than,
// equal to, or grater than aToken’s cstr.
int Token::compare(const Token &aToken) const {
	return strcmp(cstr, aToken.cstr);
}

// Overload the << operator, sout is sent back for output.
std::ostream &operator<<(std::ostream &os, const Token &token) {
  
  if (token.cstr != nullptr){
    os << right << setw(20) << token.c_str();
	  os << "  (" << token.frequency << ") " << token.getNumberList();
  } else 
      os << right << setw(20) << "  (0)";
  
	return os;
}
