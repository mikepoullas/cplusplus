// COMP5421 - Asg1
// Mike Poullas - 21917739
// Token.h

#ifndef Token_H
#define Token_H

#include <iostream>
#include "ArrayList.h"

using std::ostream;

class Token {

private:

  char* cstr {nullptr};
  int frequency {0};
  ArrayList number_list;

public:

  Token(const char* astr, int line_num);
  Token() = delete;
	Token(const Token& token);          // Copy ctor
	Token(Token&& token) noexcept;      // Move ctor

	Token& operator = (const Token& rhs); //Copy operator
  Token& operator = (Token&& rhs);      //Move operator

	virtual ~Token();

  const char* c_str() const; 
  void addLineNumber(int line_num); 
  size_t size() const;
  void print(std::ostream& sout);
  const ArrayList& getNumberList() const;
  int compare(const Token& aToken) const;
  friend ostream& operator << (ostream& sout, const Token& token);
};

ostream& operator << (ostream& sout, const Token& token);

#endif //Token_H

