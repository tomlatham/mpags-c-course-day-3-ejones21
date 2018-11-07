#include "CaesarCipher.hpp"
#include "CipherMode.hpp"
#include <iostream>
#include <string>

CaesarCipher::CaesarCipher(const size_t& key):key_{key % alphabetSize_}
{
}

CaesarCipher::CaesarCipher(const std::string& key):key_{0}
{
  if ( key.empty() ) {
    return;
  }

  for ( const auto& elem : key ) {
    if ( ! std::isdigit(elem) ) {
      std::cerr << "[error] cipher key must be an unsigned long integer for Caesar cipher,\n"
	        << "        the supplied key (" << key << ") could not be successfully converted" << std::endl;
      return;
    }
  }

  key_ = std::stoul(key) % alphabetSize_;
}

std::string CaesarCipher::applyCipher(const std::string& inputText, const CipherMode mode ) const
{
  // Create the output string
  std::string outputText {};

  // Loop over the input text
  char processedChar {'x'};
  for ( const auto& origChar : inputText ) {

    // For each character in the input text, find the corresponding position in
    // the alphabet by using an indexed loop over the alphabet container
    for ( size_t i{0}; i < alphabetSize_; ++i ) {

      if ( origChar == alphabet_[i] ) {

        // Apply the appropriate shift (depending on whether we're encrypting
        // or decrypting) and determine the new character
        // Can then break out of the loop over the alphabet
        if ( mode == CipherMode::Encrypt ) {
          processedChar = alphabet_[ (i + key_) % alphabetSize_ ];
        } 
	else if (mode == CipherMode::Decrypt) {
	  processedChar = alphabet_[ (i + alphabetSize_ - key_) % alphabetSize_ ];
        }
        break;
      }
    }

    // Add the new character to the output text
    outputText += processedChar;
  }

  return outputText;
}
