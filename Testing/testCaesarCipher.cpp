//! Unit Tests for MPAGSCipher processCommandLine interface
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "CaesarCipher.hpp"
#include <string>

TEST_CASE("Encrypts/decrypts text as required","[cipher]"){
  CaesarCipher key{"5"};

  SECTION("Encrypt text"){
    const std::string input {"HELLOWORLD"};
    const CipherMode mode {CipherMode::Encrypt};
    std::string output {key.applyCipher(input,mode)};
    REQUIRE (output=="MJQQTBTWQI");
  }

  SECTION("Decrypt text"){
    const std::string input {"MJQQTBTWQI"};
    const CipherMode mode {CipherMode::Decrypt};
    std::string output{key.applyCipher(input,mode)};
    REQUIRE(key.applyCipher(input, mode) == "HELLOWORLD");
  }
}
