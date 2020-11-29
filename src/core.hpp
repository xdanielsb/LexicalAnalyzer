#include<bits/stdc++.h>
using namespace std;

const vector<std::string> keywords{"mut", "let", "in", "fn", "std", "struct", "println!", "use", "return"};
const vector<std::string> statements{"for", "while", "if", "else"};
const vector<std::string> operators{"*", "<" ,">", "+", "-", "%", "/", "=", "-=", "*=", "+=", "/=", "++", "--", "==", "&", "|", "^"};

bool isKeyWord(const std::string &str){
  return ( find(keywords.begin(), keywords.end(), str) != keywords.end() )||
          ( find(statements.begin(), statements.end(), str) != statements.end());
}

bool isOperator(const std::string &str){
  return  std::find(operators.begin(), operators.end(), str) != operators.end();
}

bool isString(const std::string &str){
  return str.size()>1&& str[0] == '"' && str[str.size()-1] == '"';
}

bool isAlphaNum(const std::string &str){
  return str.size()>0 && std::all_of(str.begin(), str.end(), ::isalnum);
}

bool isNumber( const std::string &str){
  return str.size()>0 && std::all_of(str.begin(), str.end(), ::isdigit);
}

