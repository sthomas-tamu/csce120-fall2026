#include <iostream>
#include <string>
#include <vector>

// Song class and output operator
class Song {
  // data members
  std::string title_;
  std::string artist_;
  std::string genre_;
  unsigned int duration_;  // in seconds

 public:
  // constructor
  Song(const std::string t = "", const std::string a = "", const std::string g = "", unsigned int d = 0)
    : title_{t}, artist_{a}, genre_{g}, duration_{d} {}

  // accessors
  std::string title() const { return title_; }
  std::string artist() const { return artist_; }
  std::string genre() const { return genre_; }
  unsigned int duration() const { return duration_; }
};

std::ostream& operator<<(std::ostream& os, const Song& s) {
  os << s.title() << " by " << s.artist()
     << " [" << s.genre() << "] (" << s.duration() << "s)";
  return os;
}


// Helper function to display a playlist
void display_playlist(const std::string& label, const std::vector<Song*>& playlist) {
  std::cout << label << ":" << std::endl;
  for (const Song* song : playlist) {
    std::cout << "\t" << *song << std::endl;
  }
  /*
  // Or could iterate using indexes
  for (unsigned int i = 0; i < playlist.size(); ++i) {
    std::cout << "\t" << *(playlist.at(i)) << std::endl;
  }
  */
  std::cout << std::endl;
}


// Helper function to create all available songs
void create_all_songs(std::vector<Song*>& playlist) {
  // create a list of songs on the heap
  Song* song1 = new Song("Bohemian Rhapsody", "Queen",           "Rock", 354);
  Song* song2 = new Song("Imagine",           "John Lennon",     "Rock", 183);
  Song* song3 = new Song("Billie Jean",       "Michael Jackson", "Pop",  294);
  Song* song4 = new Song("Hotel California",  "Eagles",          "Rock", 391);

  // add them to the complete playlist
  playlist.push_back(song1);
  playlist.push_back(song2);
  playlist.push_back(song3);
  playlist.push_back(song4);
}


int main() {
  // make the complete playlist
  std::vector<Song*> complete;
  create_all_songs(complete);

  // add only rock songs to a new playlist
  std::vector<Song*> rock;
  for (Song* song : complete) {
    if (song->genre() == "Rock") {
      rock.push_back(song);
    }
  }
  /* 
  // Or could iterate using indexes
  for (std::size_t i = 0; i < complete.size(); ++i) {
    if (complete.at(i)->genre() == "Rock") {
      rock.push_back(complete.at(i));
    }
  }
  */

  // add not rock songs to a new playlist
  std::vector<Song*> not_rock;
  for (Song* song : complete) {
    if (song->genre() != "Rock") {
      not_rock.push_back(song);
    }
  }
  /* 
  // Or could iterate using indexes
  for (std::size_t i = 0; i < complete.size(); ++i) {
    if (complete.at(i)->genre() != "Rock") {
      not_rock.push_back(complete.at(i));
    }
  }
  */

  // print each playlist
  display_playlist("Complete List", complete);
  display_playlist("Rock List", rock);
  display_playlist("Not Rock List", not_rock);

  // release memory of complete list
  for (Song* song : complete) {
    delete song;
    song = nullptr;
  }
  /*
  // Or could iterate using indexes
  for (std::size_t i = 0; i < complete.size(); ++i) {
    delete complete.at(i);
    complete.at(i) = nullptr;
  }
  */

  return 0;
}
