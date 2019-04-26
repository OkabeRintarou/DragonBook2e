#include <iostream>
#include <string>

using namespace std;

class InputStream {
public:
  InputStream(string s) : str(std::move(s)) {
    cur = 0;
  }

  string::size_type tell() const { return cur; }

  char get() {
    return cur < str.size() ? str[cur++] : -1;
  }

  void seek(string::size_type pos) { cur = pos; }

  bool is_end() const { return cur == str.size(); }

  string to_string() const {
    string ret = "(";
    ret.append(str.substr(0, cur));
    ret.append(" , ");
    ret.append(str.substr(cur));
    ret.push_back(')');
    return ret;
  }

private:
  string str;
  string::size_type cur;
};

bool S(InputStream &is);

bool aSa(InputStream &is) {
  char c;
  c = is.get();
  if (c == 'a') {
    if (S(is)) {
      c = is.get();
      if (c == 'a') {
        return true;
      }
    }
  }
  return false;
}

bool aa(InputStream &is) {
  char c;
  c = is.get();
  if (c == 'a') {
    c = is.get();
    return c == 'a';
  }

  return false;
}

bool S(InputStream &is) {

  auto pos = is.tell();

  if (aSa(is)) {
    return true;
  }

  is.seek(pos);

  return aa(is);
}

void match(string &str) {
  InputStream is(str);
  bool r = S(is);
  if (!r) {
    cout << "failed" << endl;
  } else if (is.is_end()) {
    cout << "succeeded! " << is.to_string() << endl;
  } else {
    cout << "partially matched. " << is.to_string() << endl;
  }
}

int main() {

  for (int i = 0; i <= 32; i++) {
    cout << i << " : ";
    string str(i, 'a');
    match(str);
  }

  return 0;
}
