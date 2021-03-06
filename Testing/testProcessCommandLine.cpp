//! Unit Tests for MPAGSCipher processCommandLine interface
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "ProcessCommandLine.hpp"
#include <vector>
#include <string>

TEST_CASE("Reads command line arguments correctly","[command line]"){
  ProgramSettings testcommands{false,false,"","","",CipherMode::Encrypt};

  SECTION("Process -h correctly"){
    const std::vector<std::string> testargs {"name", "-h"};
    REQUIRE (processCommandLine(testargs, testcommands)==true);
    REQUIRE (testcommands.helpRequested==true);
  }

  SECTION("Process --help correctly"){
    const std::vector<std::string> testargs {"name", "--help"};
    REQUIRE (processCommandLine(testargs, testcommands)==true);
    REQUIRE (testcommands.helpRequested==true);
  }

  SECTION("Process --version correctly"){
    const std::vector<std::string> testargs {"name", "--version"};
    REQUIRE (processCommandLine(testargs, testcommands)==true);
    REQUIRE (testcommands.versionRequested==true);
  }

  SECTION("Process -i correctly"){
    SECTION("With no filename specified"){
      const std::vector<std::string> testargs {"name", "-i"};
      REQUIRE (processCommandLine(testargs, testcommands)==false);
    }
    SECTION("With filename specified"){
      const std::vector<std::string> testargs {"name", "-i","input"};
      REQUIRE (processCommandLine(testargs, testcommands)==true);
      REQUIRE (testcommands.inputFile=="input");
    }
  }

  SECTION("Process -o correctly"){
    SECTION("With no filename specified"){
      const std::vector<std::string> testargs {"name", "-o"};
      REQUIRE (processCommandLine(testargs, testcommands)==false);
    }
    SECTION("With filename specified"){
      const std::vector<std::string> testargs {"name", "-o","output"};
      REQUIRE (processCommandLine(testargs, testcommands)==true);
      REQUIRE (testcommands.outputFile=="output");
    }
  }

  SECTION("Process -k correctly"){
    SECTION("With value not specified"){
      const std::vector<std::string> testargs {"name", "-k"};
      REQUIRE (processCommandLine(testargs, testcommands)==false);
    }
    SECTION("With value specified"){
      const std::vector<std::string> testargs {"name", "-k","5"};
      REQUIRE (processCommandLine(testargs, testcommands)==true);
      REQUIRE (testcommands.cipher_key=="5");
    }
  }

  SECTION("Process mode correctly"){
    SECTION("For encryption"){
      const std::vector<std::string> testargs {"name", "--encrypt"};
      REQUIRE (processCommandLine(testargs, testcommands)==true);
      REQUIRE (testcommands.mode==CipherMode::Encrypt);
    }
    SECTION("For decryption"){
      const std::vector<std::string> testargs {"name", "--decrypt"};
      REQUIRE (processCommandLine(testargs, testcommands)==true);
      REQUIRE (testcommands.mode==CipherMode::Decrypt);
    }
  }

}
