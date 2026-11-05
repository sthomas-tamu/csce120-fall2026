#include <iostream>
#include <string>

#include "SocialMediaPost.h"

int main() {
  // create a social media post, have several people like it
  SocialMediaPost post("The best day ever!");
  post.add_like(5);
  post.add_like(2);
  post.add_like(4);
  post.add_like(2);
  std::cout << "My post:\n" << post << std::endl;

  // create another social media post, no one likes it yet
  SocialMediaPost post2("Another great day.");
  std::cout << "Another post:\n" << post2 << std::endl;

  // copy one post to another
  post2 = post;
  std::cout << "Set this post to the original one. It is now:\n"
    << post2 << std::endl;

  return 0;
}
