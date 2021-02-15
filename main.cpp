/*
 * author: xdanielsb
 * date: 30-11-2020
 */
#include <bits/stdc++.h>
#define endl '\n'
#define d(x) cout <<#x << " = " << x << ", ";
#define d0(x) cout <<#x << " = " << x << endl;
#define d1( x ) d(x); cout <<endl;
#define d2( x, y ) d(x); d(y); cout <<endl;
#define d3( x, y, z ) d(x); d(y); d(z); cout <<endl;
#define lst back()
#define endl '\n'


#include "src/core.hpp"

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

bool isCommentLine = false;
bool isCommentBlock = false;
bool openedQuote = 0;
bool errorFree = true;


enum{iskeyword, isoperator, isconstant,isstring,isblock, isnumbers, isident };
int ln = 1, last_id = -1;
vector < string > tokens;
map< string, int> symbols;


void error(const string &err){
  cerr << err <<endl;
  cout << "\t line:" << ln << endl;
  errorFree = false;
}
void report( int line, string type, string content){
  #ifdef verbose
    cout<< "----LINE #"<< line <<" " << type << " " << content << endl;
  #endif
}

bool check( string& buf){
  if( buf.size() && buf.back() == '\n') buf.erase(buf.end());
  if(isKeyWord(buf)){
    report(ln,"keyword", buf);
    last_id = iskeyword;
    symbols[buf] = iskeyword;
    return true;
  }
  if(isOperator(buf)){
    if(last_id == iskeyword)error("E01: you cannot have a keyword followed by an operator");
    if(last_id == -1)error("E06: you need to have a number or identifier before an operator");
    last_id = isoperator;
    report(ln, "operator", buf);
    symbols[buf] = isoperator;
    return true;
  }
  if(isString(buf)){
    if(last_id == isstring)error("E02: you cannot have a string followed by a string");
    if(last_id == iskeyword)error("E03: you cannot have a string followed by a keyword");
    if(last_id == isnumbers)error("E04: you cannot have a string followed by a number");
    if(last_id == isident)error("E05: you cannot have a string followed by an identifier");
    last_id = isstring;
    report(ln,"string", buf);
    symbols[buf] = isstring;
    return true;
  }
  if(isNumber(buf)){
    if(last_id == isstring)error("E07: you cannot have a number followed by a string");
    if(last_id == iskeyword)error("E08: you cannot have a number followed by a keyword");
    if(last_id == isnumbers)error("E09: you cannot have a number followed by a number");
    if(last_id == isident)error("E010: you cannot have a number followed by an identifier");
    last_id = isnumbers;
    symbols[buf] = isnumbers;
    report(ln, "number", buf);
    return true;
  }
  else if(isAlphaNum(buf)){
    if(last_id == isident)error("E011: you cannot have an identifier followed by an identifier");
    if(last_id == isstring)error("E12: you cannot have an id followed by a string");
    if(last_id == isnumbers)error("E14: you cannot have an id followed by a number");
    last_id = isident;
    symbols[buf] = isident;
    report(ln,"identifier", buf);
    return true;
  }
  else{
    if(buf.size()>0){
      report(ln,"not classified", buf);
    }
  }
  return false;
}


int main( int argc, char** argv ){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
  char ch;
  string buf="";
  stack<char> brack;
  const string &pathfile=argc<=1?"input/in1.rs":argv[1];
  fstream file(pathfile, std::fstream::in);

  if (!file.is_open())
    error("E15: cannot open the file");

  while (file >> std::noskipws >> ch){
    if( ch == '\n') {
      ln++;
    }
    if(openedQuote|| ch == '"'){
      buf+=ch;
      if(!openedQuote){
        openedQuote = true;
      }else if(openedQuote && ch=='"'){
        openedQuote = false;
        check(buf);
        buf ="";
      }
      continue;
    }
    if( isCommentLine || isCommentBlock){
      if(isCommentLine && ch =='\n'){
        isCommentLine = false;
        report(ln, "line-comment", buf);
        buf="";
      }else if(isCommentBlock && buf.lst == '*' && ch == '/'){
        isCommentBlock = false;
        report(ln, "block-comment", buf);
        buf="";
      }else{
        buf+=ch;
      }
      continue;
    }
    if ( buf.size()> 0 && buf.lst=='/'){
      if( ch=='/') {
        isCommentLine = true;
      }else if( ch=='*'){
        isCommentBlock = true;
      }
    }
    if( ch == '{' || ch == '('){
      tokens.push_back(string(1,ch));
      brack.push(ch=='{'?'}':')');
      report(ln, "scope", string(1, ch));
      last_id= isblock;
      buf="";
    }else if ( ch == '}' || ch == ')'){
      if(brack.size() == 0|| brack.top()!= ch) {
        error("E17: Malformed brackets");
      }
      tokens.push_back(string(1,ch));
      report(ln, "scope", string(1, ch));
      buf="";
      brack.pop();
    }else if (ch == ';'){
      if(check(buf))
        tokens.push_back(buf);
      last_id =-1;
      buf="";
    }else{
      if(isspace(ch) || ch=='\n'){
        if(buf.size()>0 && check(buf))
          tokens.push_back(buf);
        buf="";
      }else{
        buf+=ch;
      }
    }
  }
  if( brack.size()) error("E16: Malformed brackets");
  if( isCommentBlock) error("E17: Malformed comments");

  if(errorFree)
    cout << "Succesfull interpretation." <<endl;
  else
    cout << "Upps ... fix issues."<<endl;

  //tokens
  /* for( string s: tokens) d0(s); */

  //symbols
  /* for ( pair<string,int> f: symbols) d0(f.first); */
  return 0;
}
