#include<bits/stdc++.h>
#ifndef _CDefines
#define _CDefines
using namespace std;

const vector<string> keywords{"mut", "let", "in", "fn", "std", "struct", "println!", "print!", "use", "return"};
const vector<string> statements{"for", "while", "if", "else"};
const vector<string> operators{"*", "<" ,">", "+", "-", "%", "/", "=", "-=", "*=", "+=", "/=", "++", "--", "==", "&", "|", "^"};

bool isKeyWord(const string &str){
  return ( find(keywords.begin(), keywords.end(), str) != keywords.end() )||
    ( find(statements.begin(), statements.end(), str) != statements.end());
}

bool isOperator(const string &str){
  return  find(operators.begin(), operators.end(), str) != operators.end();
}

bool isString(const string &str){
  return str.size()>1&& str[0] == '"' && str[str.size()-1] == '"';
}

bool isAlphaNum(const string &str){
  return str.size()>0 && all_of(str.begin(), str.end(), ::isalnum);
}

bool isNumber( const string &str){
  return str.size()>0 && all_of(str.begin(), str.end(), ::isdigit);
}
#endif
