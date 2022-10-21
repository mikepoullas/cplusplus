// COMP5421 - Asg1
// Mike Poullas - 21917739
// Dictionary.cpp

#include <ostream>
#include <fstream>
#include <sstream>
#include "Dictionary.h"

using std::ofstream;
using std::ifstream;
using std::istringstream;
using std::cout;
using std::endl;

size_t Dictionary::bucketIndex(const string& token) const {

  // Bucket index for tokens not beginning with a letter
	size_t index = 26;
  
  // Otherwise find the bucketIndex for the word
	if (isalpha(token[0])) {
		if (isupper(token[0]))
			index = token[0] - 'A';
		else
			index = token[0] - 'a';
	}
	return index;
}

Dictionary::Dictionary(const string& filename) : filename(filename) {

  // create an input file stream
	ifstream fin(filename); 

	if (!fin) {
	  cout << "could not open input file: " << filename << endl;
		exit(1);
	}
	
  int linenum = 0;
	string line;
  
  // Very important first attempt to read;
  // This first attempt will get the i/o flags initialized
	getline(fin, line);
						
	while (fin) {
		
    // cout << line << endl;

    // Count the line
		++linenum;

    // Turn the line into an input string stream
		istringstream sin(line); 
		string tokenStr;

    // Extract token strings
		while (sin >> tokenStr) {
			processToken(tokenStr, linenum);
		}
    // Attempt to read the next line, if any
		getline(fin, line); 
	}
	fin.close();
}

void Dictionary::processToken(const string& token, int linenum) {
  
  tokenListBuckets[bucketIndex(token.c_str())].addSorted(Token(token.c_str(), linenum));
  
}

void Dictionary::print(ostream& sout) const {

  char c;
  
  for (int i=0; i <= 26; i++) {
    sout << "<" << (char)(i+65) << ">" << endl;
    tokenListBuckets[i].print(sout);
  }
}