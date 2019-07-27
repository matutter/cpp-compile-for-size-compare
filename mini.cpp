#include <iostream>
#include <vector>
#include <string>
#include <ostream>
#include <memory>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ostream;
using std::unique_ptr;
using std::make_unique;
using std::move;

template <typename T>
void printout(vector<T> v) {
  for ( const auto& s: v ) {
    cout << s << endl;
  }
}

struct Guts {
  Guts(int i, string s): i(i), s(s) {}
  virtual ~Guts() = default;
  int i = 0;
  string s = "s";
};

ostream &operator<<(ostream &os, Guts const &g) { 
    return os  << "[" << g.i << "," << g.s << "]";
}

#ifndef NSMART_PTR
  ostream &operator<<(ostream &os, unique_ptr<Guts>& g) { 
      return os  << "[" << g->i << "," << g->s << "]";
  }
#else
  ostream &operator<<(ostream &os, Guts* g) { 
      return os  << "[" << g->i << "," << g->s << "]";
  }
#endif

void do_smart_pointer_stuff_maybe() {
  #ifdef WITH_SMART_PTR
    vector<unique_ptr<Guts>> v = {};
    v.emplace_back( new Guts(0, "xxx") );
    v.emplace_back( new Guts(1, "yyy") );
    v.emplace_back( new Guts(2, "zzz") );
    while( !v.empty() ) {
      unique_ptr<Guts> g = move(v.back());
      cout << g << endl;
      v.pop_back();
    }
  #else
    vector<Guts*> v = {
      new Guts(0, "xxx"),
      new Guts(1, "yyy"),
      new Guts(2, "zzz")
    };
    for ( auto g: v ) {
      cout << g << endl;
    }
  #endif
}

int main(void) {

  cout << "[mini:running]" << endl;

  vector<string> vs = { "aaa", "bbb", "ccc" };
  vector<int> vi = { 0, 1, 2 };
  vector<float> vf = { 0.1, 1.2, 2.3 };
  vector<Guts> vg = { {0, "aaa"}, {1, "bbb"}, {2, "ccc"} };
  printout(vs);
  printout(vi);
  printout(vf);
  printout(vg);
  do_smart_pointer_stuff_maybe();

  return 0;
}
