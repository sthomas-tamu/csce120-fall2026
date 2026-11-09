#include "SocialMediaPost.h"

// default constructor
SocialMediaPost::SocialMediaPost(const std::string& s)
  : text_{std::string{s}}, num_likes_{0}, liked_by_{nullptr} {}


// copy constructor
SocialMediaPost::SocialMediaPost(const SocialMediaPost& source)
  : text_{source.text_}, num_likes_{source.num_likes_}, liked_by_{nullptr} {
  if (source.num_likes_ != 0) {
    liked_by_ = new int[source.num_likes_];
    for (unsigned int i = 0; i < source.num_likes_; ++i)
      liked_by_[i] = source.liked_by_[i];
  }
}


// destructor
SocialMediaPost::~SocialMediaPost() {
  // TODO(@Student)
}


// copy assignment operator
SocialMediaPost& SocialMediaPost::operator=(const SocialMediaPost& source) {
  // TODO(@Student)

  return *this;
}


void SocialMediaPost::add_like(int person_id) {
  // TODO(@Student)

  // only add if not already in list
}


std::ostream& operator<<(std::ostream& os, const SocialMediaPost& post) {
  os << "\tText: \"" << post.text() << "\"\n";
  os << "\t" << post.num_likes() << " likes\n";
  if (post.num_likes() > 0) {
    os << "\tpeople who liked this post:";
    for (unsigned int i = 0; i < post.num_likes(); ++i)
      os << " " << post.get_like(i);
    os << std::endl;
  }
  return os;
}
