#ifndef DICTIONARY_H_
#define DICTIONARY_H_

#include "TokenList.h"

class Dictionary
{

private:
  string filename;
  // 26  alpha buckets + 1 none-alpha bucket
  TokenList tokenListBuckets[27];  
  size_t bucketIndex(const string& token) const;

public:
  Dictionary(const string& filename);
  void processToken(const string& token, int linenum);
  void print(ostream& out) const;
  Dictionary()  = delete;   // no default ctor
  ~Dictionary() = default;  // default dtor
  Dictionary(const Dictionary& ) = default; // copy ctor
  Dictionary(      Dictionary&&) = default; // move ctor
  Dictionary& operator=(const Dictionary&) = default;  // copy assignment
  Dictionary& operator=(      Dictionary&&) = default; // move assignment
};

#endif //DICTIONARY_H_
