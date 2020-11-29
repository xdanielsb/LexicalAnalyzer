#include<bits/stdc++.h>
using namespace std;

const vector<std::string> keywords{"let", "in" "fn", "std", "struct", "println", "use", "return"};
const vector<std::string> statements{"for", "while", "if", "else"};
const vector<std::string> operators{"*", "+", "-", "%", "/", "=", "-=", "*=", "+=", "/=", "++", "--", "=="};
const vector<std::string> separators{"{", "}", ";"};

bool isKeyWord(const std::string &str){
  return  std::find(keywords.begin(), keywords.end(), str) != keywords.end() ||
    std::find(statements.begin(), statements.end(), str) != statements.end() ||
}

bool isSeparator(const std::string &str){
  return  std::find(separators.begin(), separators.end(), str) != separators.end()
}

bool isOperator(const std::string &str){
  return  std::find(operators.begin(), operators.end(), str) != operators.end()
}

bool isString(const std::string &str){
  return str[0] == '"' && str[str.size()-1] == '"';
}

bool isNumber( const std::string &str){
  return std::all_of(str.begin(), str.end(), ::isdigit);
}

