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
  if (liked_by_ != nullptr)
    delete[] liked_by_;
}


// copy assignment operator
SocialMediaPost& SocialMediaPost::operator=(const SocialMediaPost& source) {
  if (this == &source)  // check self-assignment
    return *this;

  text_ = source.text_;
  num_likes_ = source.num_likes_;

  // clean up any existing memory
  if (liked_by_ != nullptr) {
    delete[] liked_by_;
    liked_by_ = nullptr;  // set dangling pointer to null in case no likes
  }

  // allocate new memory and initialize data
  if (source.num_likes_ > 0) {
    liked_by_ = new int[source.num_likes_];
    for (unsigned int i = 0; i < source.num_likes_; ++i)
      liked_by_[i] = source.liked_by_[i];
  }

  return *this;
}


void SocialMediaPost::add_like(int person_id) {
  // only add if not already in list
  bool found = false;
  for (unsigned int i = 0; i < num_likes_; ++i) {
    if (liked_by_[i] == person_id) {
      found = true;
      break;
    }
  }

  if (!found) {
    int* new_ary = new int[num_likes_ + 1];

    // copy over everything
    for (unsigned int i = 0; i < num_likes_; ++i)
      new_ary[i] = liked_by_[i];

    // insert the new person_id
    new_ary[num_likes_] = person_id;

    // update the array and its size
    delete[] liked_by_;
    num_likes_++;
    liked_by_ = new_ary;
  }
}


bool SocialMediaPost::remove_like(int person_id) {
  bool found = false;
  for (unsigned int i = 0; i < num_likes_; ++i) {
    if (liked_by_[i] == person_id) {
      found = true;
      break;
    }
  }

  if (found) {
    // create a new list with 1 less
    int* new_ary = new int[num_likes_ - 1];

    // copy over likes but skip person_id
    unsigned int new_i = 0;
    for (unsigned int i = 0; i < num_likes_; ++i) {
      if (liked_by_[i] != person_id) {
        new_ary[new_i] = liked_by_[i];
        new_i++;
      }
    }

    // update the array and its size
    delete[] liked_by_;
    num_likes_--;
    liked_by_ = new_ary;
  }

  return found;
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
