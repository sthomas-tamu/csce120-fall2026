#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

std::string tolower(std::string wd) {
  for (size_t i = 0; i < wd.size(); ++i) {
    wd.at(i) = tolower(wd.at(i));
  }
  return wd;
}


std::string getReplace(std::string wd) {
  return "***";
}


int main() {
  bool DEBUG = true;  // can toggle on and off debugging statements

  // read in input filenames
  std::cout << "Enter the filename containing the list of censored words: ";
  std::string censorWordsFilename;
  if (!(std::cin >> censorWordsFilename)) {
    std::cout << "Error, no filename given, exiting." << std::endl;
    return -1;
  }

  std::cout << "Enter the filename to censor: ";
  std::string originalTextFilename;
  if (!(std::cin >> originalTextFilename)) {
    std::cout << "Error, no filename given, exiting." << std::endl;
    return -1;
  }

  std::string censoredTextFilename = "censored." + originalTextFilename;
  std::cout << "Censored output will be in: " << censoredTextFilename << std::endl;

  // create and open filestreams
  std::ifstream censorIn(censorWordsFilename);
  std::ifstream origIn(originalTextFilename);
  std::ofstream censorOut(censoredTextFilename);
  // TODO(@Student): add code to check opened properly

  // get list of words to censor from file
  std::vector<std::string> censorWords;
  std::string censorWord;
  while (censorIn >> censorWord) {  // operator >> uses whitespace to determine the string's end
                                    // failure checking is built in, returns false if failed
    censorWords.push_back(tolower(censorWord));  // convert all censor words to lower case
  }
  if (DEBUG) {
    std::cout << "DEBUG::censorWords:";
    for (const std::string& censorWord : censorWords) {
      std::cout << " " << censorWord;
    }
    std::cout << std::endl;
  }

  // process text line by line, until the end of the file:
  //   get next line
  //   see if each censor word is in line
  //     if it is there, replace with symbols
  //   output modified line
  while (!origIn.eof()) {
    std::string line;
    getline(origIn, line);
    // TODO(@Student): add code to check if getline executed properly

    if (DEBUG) {
      std::cout << "DEBUG::processing line: '" << line << "'" << std::endl;
    }

    std::string lineOut = line;
    for (const std::string& censorWd : censorWords) {
      std::string lowerLine = tolower(lineOut);  // temporary lower case copy to match censor words
      size_t position = lowerLine.find(censorWd);
      while (position != std::string::npos) {
        if (DEBUG) {
          std::cout << "DEBUG::\tfound censor word " << censorWd
            << " at position " << position << ", replacing" << std::endl;
        }
        lowerLine.replace(position, censorWd.size(), getReplace(censorWd));
        lineOut.replace(position, censorWd.size(), getReplace(censorWd));
        position = lowerLine.find(censorWd);
      }
    }
    if (DEBUG) {
      std::cout << "DEBUG::line becomes: '" << lineOut << "'" << std::endl;
    }

    censorOut << lineOut << std::endl;
  }

  return 0;  // ifstream/ofstream closed by their destructors
}
