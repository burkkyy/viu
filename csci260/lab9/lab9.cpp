#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>

#define P(x) std::cout << x << std::endl
#define PRIME 53

std::string loadText(const std::string& filename){
  std::ifstream f(filename);
  std::string contents((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
  return contents;
}

int pow(int x, int y){
  int total = x;
  for(int i = 1; i < y; i++){ total *= x; }
  return total;
}

int hash(const std::string s, int start, int end){
  int hs = 0;
  for(int i = start; i <= end; i++){
    hs = hs * PRIME + s[i];
  }
  return hs;
}

int karp_rabin_search(const std::string& s, const std::string& p){
  int lenp = p.length();
  int lens = s.length();
  int hp = hash(p, 0, lenp - 1);
  int hs = hash(s, 0, lenp - 1);
  int d = pow(PRIME, lenp - 1);

  for(int i = 0; i <= lens-lenp; i++) {
    if (hp == hs && s.substr(i, lenp) == p){
      return i;
    } else {
      hs = (hs - s[i] * d) * PRIME + s[i + lenp];
    }
  }
  return -1;
}

std::string findAround(const std::string& data, const std::string& s){
  int index = karp_rabin_search(data, s);

  if(index == -1){
    throw "Could note find string";
  }

  int data_length = data.length();
  int len = s.length();
  std::string str = "";

  // Get string before
  int start = index - len;
  for(int i = start; i < index && i >= 0; i++){
    str += data[i];
  }

  str += s;

  // Get string after
  start = index + len;
  for(int i = start; i < start + len && i < data_length; i++){
    str += data[i];
  }

  return str;
}

int main(int argc, const char** argv){
  (void)argc;
  (void)argv;

  if(argc < 3){
    std::cout << "Invalid input. Usage:\n./app <FILENAME> <STRING PATTERN>" << std::endl;
    return 0;
  }

  std::string input_filename = argv[1];
  std::string pattern = argv[2];  
  std::string data = loadText(input_filename);

  try {
    std::string found = findAround(data, pattern);
    std::cout << "Found string pattern: " << found << std::endl;
  } catch(const char* e){
    std::cout << e << std::endl;
  }
  
  return 0;
}
