/*
 * author: xdanielsb
 * date: 29-11-2020
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


enum{iskeyword, isoperator, isconstant,isnew,isstring,isblock, isnumbers, isident };
int ln = 1, last_id = -1;

bool check( const string& buf){
  if(isKeyWord(buf)){
    cout<< " \n----LINE #"<< ln<< "  keyword: "<< buf << endl;
    last_id = iskeyword;
    return true;
  }
  if((last_id == iskeyword || last_id == isconstant || last_id==isnumbers || last_id ==isident) && isOperator(buf)){
    last_id = isoperator;
    cout<< " \n----LINE #"<< ln<< "  operator: "<< buf << endl;
    return true;
  }
  if(isString(buf)){
    last_id = isstring;
    cout<< " \n----LINE #"<< ln<< "  string: "<< buf << endl;
    return true;
  }
  if(isNumber(buf)){
    last_id = isnumbers;
    cout<< " \n----LINE #"<< ln<< "  number: "<< buf << endl;
    return true;
  }
  else if(isAlphaNum(buf)){
    last_id = isident;
    cout<< " \n----LINE #"<< ln<< "  identifier: "<< buf << endl;
    return true;
  }
  else{
    if(buf.size()>0)// Not clasified yet
      d0(buf);
  }
  return false;
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL

#endif
  char ch;

  string buf="";

  stack<char> brack;
  const string &pathfile="input/in2.rs";
  fstream file(pathfile, std::fstream::in);

  if (!file.is_open()){
    cout << "Cannot open the file\n";
    exit(0);
  }

  while (file >> std::noskipws >> ch){
    if( ch == '\n') ln++;
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
        cout<< " \n----LINE #"<< ln<< "  line-comment: "<< buf << endl;
        buf="";
      }else if(isCommentBlock && buf.lst == '*' && ch == '/'){
        isCommentBlock = false;
        cout<< " \n----LINE #"<< ln<< "  block-comment: "<< buf << "/" <<endl;
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
      brack.push(ch=='{'?'}':')');
      check(buf);
      last_id= isblock;
      buf="";
    }else if ( ch == '}' || ch == ')'){
      if(brack.size() == 0|| brack.top()!= ch) {
        cout << "Invalid region at Line #" << ln <<endl;
        exit(0);
      }
      buf="";
      brack.pop();
    }else if (ch == ';'){
      check(buf);
      last_id = isnew;
      buf="";
    }else{
      if(isspace(ch) || ch=='\n'){
        if(buf.size()>0)
          check(buf);
        buf="";
      }else{
        buf+=ch;
      }
    }
  }
  return 0;
}
