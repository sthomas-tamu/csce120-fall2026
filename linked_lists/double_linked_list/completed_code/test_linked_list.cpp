#include "linked_list.h"

void print_test(const std::string& label, const LinkedList& l) {
  std::cout << label << ":\t\"" << l << "\"\n";
}


int main() {
  std::cout << "== Testing Constructors ==\n";

  LinkedList s1;
  print_test("s1: default constructor", s1);

  LinkedList s2("hello");
  print_test("s2: construct from a c-string", s2);

  std::string temps = "World";
  LinkedList s3(temps);
  print_test("s3: construct from std::string", s3);


  std::cout << "\n== Testing Print Reverse ==\n";
  std::cout << "s1 reversed: \"";
  s1.print_reverse();
  std::cout << "\"\n";
  std::cout << "s2 reversed: \"";
  s2.print_reverse();
  std::cout << "\"\n";
  std::cout << "s3 reversed: \"";
  s3.print_reverse();
  std::cout << "\"\n";


  std::cout << "\n== Testing Insert Front and Back ==\n";
  s1.insert_front('a');
  s1.insert_back('c');
  print_test("s1: add 'a' to front and 'c' to back", s1);
  s1.insert_front('b');
  print_test("s1: add 'b' to front", s1);


  std::cout << "\n== Testing Find ==\n";
  std::cout << "s3: \"" << s3 << "\"\n";
  std::cout << "\ts3 has r: " << std::boolalpha << s3.contains('r') << std::endl;
  std::cout << "\ts3 has z: " << std::boolalpha << s3.contains('z') << std::endl;


  std::cout << "\n == Testing Remove ==\n";
  s3.remove('W');
  print_test("s3: remove W", s3);
  s3.remove('z');
  print_test("s3: remove z", s3);
  s3.remove('d');
  print_test("s3: remove d", s3);
  s3.remove('l');
  print_test("s3: remove l", s3);
  s3.remove('r');
  print_test("s3: remove r", s3);
  s3.remove('o');
  print_test("s3: remove o", s3);
  s3.remove('!');
  print_test("s3: remove !", s3);


  std::cout << "\n == Testing Insert After and Insert Before ==\n";
  std::cout << "s2: \"" << s2 << "\"\n";
  s2.insert_after('=', 'e');
  print_test("s2: insert = after e", s2);
  s2.insert_after('!', 'o');
  print_test("s2: insert ! after o", s2);
  s2.insert_after('k', 'z');
  print_test("s2: insert k after z", s2);
  s2.insert_before('?', 'l');
  print_test("s2: insert ? before l", s2);
  s2.insert_before('-', 'z');
  print_test("s2: insert - before z", s2);
  std::cout << std::endl;

  return 0;
}
