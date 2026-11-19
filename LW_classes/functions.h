// this file is provided.  do not submit.
#ifndef PROVIDED_FUNCTIONS_H_
#define PROVIDED_FUNCTIONS_H_

#include <string>

std::string deobfuscate(
    std::string obfuscated_sentence,
    std::string deobfuscation_details);

std::string wordFilter(
    std::string sentence_to_filter,
    std::string word_to_filter_out);

std::string passwordConverter(
    std::string password_basis);

std::string wordCalculator(
    std::string arithmetic_expression_using_words);

unsigned int palindromeCounter(
    std::string words_separated_by_spaces);

#endif  // PROVIDED_FUNCTIONS_H_
