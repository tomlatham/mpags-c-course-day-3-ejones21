#include "CaesarCipher.hpp"
#include "CipherMode.hpp"
#include <iostream>
#include <string>
CaesarCipher::CaesarCipher(const size_t& key):key_{key}
{
}
CaesarCipher::CaesarCipher(const std::string& key):key_{0}
{
  for ( const auto& elem : key ) {
      if ( ! std::isdigit(elem) ) {
        std::cerr << "[error] cipher key must be an unsigned long integer for Caesar cipher,\n"
                  << "        the supplied key (" << key << ") could not be successfully converted" << std::endl;
	break;
      }
      else {
	key_ = std::stoul(key);
      }
  }
}

std::string CaesarCipher::applyCipher(const std::string& inputText, const CipherMode mode )
{
  // Make sure that the key is in the range 0 - 25
  const size_t alphabetSize = alphabet_.size();
  const size_t truncatedKey { key_ % alphabetSize };

  // Loop over the input text
  char processedChar {'x'};
  for ( const auto& origChar : inputText ) {

    // For each character in the input text, find the corresponding position in
    // the alphabet by using an indexed loop over the alphabet container
    for ( size_t i{0}; i < alphabetSize; ++i ) {

      if ( origChar == alphabet_[i] ) {

        // Apply the appropriate shift (depending on whether we're encrypting
        // or decrypting) and determine the new character
        // Can then break out of the loop over the alphabet
        if ( mode == CipherMode::encrypt ) {
          processedChar = alphabet_[ (i + truncatedKey) % alphabetSize ];
        } 
	else if (mode == CipherMode::decrypt) {
	  processedChar = alphabet_[ (i + alphabetSize - truncatedKey) % alphabetSize ];
        }
        break;
      }
    }

    // Add the new character to the output text
    outputText_ += processedChar;
  }

  return outputText_;
}
