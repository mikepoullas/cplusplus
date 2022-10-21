// COMP 5421 Assignment 1
// Mike Poullas - 21917730
// TokenList.h

#ifndef TOKENLIST_H_
#define TOKENLIST_H_

#include <iostream>
#include <iomanip>
#include "Token.h"

using std::string;

class TokenList {
private:
  // a private "member type"
   struct TNode
   {
      Token theToken; // The token contained in this node
      TNode* next;    // Pointer to the next node or nullptr

      // Constructor
      TNode(const Token& aToken, TNode* next = nullptr) : theToken(aToken), next(next) {}
      TNode() = delete;                   // default ctor
      TNode(const TNode& other) = delete; // copy ctor
      TNode(TNode&& other) = delete;      // move ctor
      TNode& operator=(const TNode& other) = delete; // copy assignment
      TNode& operator=(TNode&& other) = delete;      // move assignment

      virtual ~TNode() = default;
   };

  // Begin class TokenList
  TNode* head {nullptr}; // Points to the first node in the list
  TNode* tail {nullptr}; // Points to the last node in the list
  size_t theSize { 0 };  // Counts the number of nodes in the list

  bool remove(TNode* nodePtr);
  TNode* lookup(const Token& aToken) const;
  void addAfter(TNode* p, const Token& aToken);

public:

  TokenList();
  TokenList(const TokenList& list); //Copy CTOR
  TokenList(TokenList&& list);      //Move CTOR
  TokenList& operator=(const TokenList& rhs);  //Copy assignment operator
  TokenList& operator=(TokenList&& rhs);      //Move assignment operator
  virtual ~TokenList();

  bool empty() const;
  size_t size() const;
  void print(ostream& sout) const;
  const Token& front() const;
  const Token& back() const;
  void addSorted(const Token& aToken);
  void addSorted(const string& str, int lineNum);
  bool removeFront();
  bool removeBack();
  bool search(const Token& aToken) const;
  void addFront(const Token& aToken);
  void addBack(const Token& aToken);
};

#endif //TOKENLIST_H_
