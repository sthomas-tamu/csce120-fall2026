#ifndef SOCIAL_MEDIA_POST_
#define SOCIAL_MEDIA_POST_

#include <iostream>
#include <string>

class SocialMediaPost {
  std::string text_;        // content of the post
  unsigned int num_likes_;  // number of likes
  int* liked_by_;           // ids of those who liked the post

 public:
  // default constructor
  SocialMediaPost(const std::string& s = "");

  // copy constructor
  SocialMediaPost(const SocialMediaPost& source);

  // destructor
  ~SocialMediaPost();

  // copy assignment operator
  SocialMediaPost& operator=(const SocialMediaPost& source);

  // getter methods
  std::string text() const { return text_; }
  unsigned int num_likes() const { return num_likes_; }
  int get_like(int index) const { return liked_by_[index]; }

  // someone likes the post!
  void add_like(int person_id);
};

// output operator
std::ostream& operator<<(std::ostream& os, const SocialMediaPost& post);

#endif  // SOCIAL_MEDIA_POST_H_
