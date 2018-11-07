#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP


#include <string> 
#include <vector>
#include <iostream>
#include <fstream>
#include "CipherMode.hpp"

class CaesarCipher{
  public:
    explicit CaesarCipher(const size_t& key);
    explicit CaesarCipher(const std::string& key);
    std::string outputText_;
    size_t key_;
    std::string applyCipher(const std::string& inputText, const CipherMode mode ) ;

  private:
    std::vector<char> alphabet_ = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
 };

#endif // MPAGSCAESARCIPHER_CAESARCIPHER_HPP
