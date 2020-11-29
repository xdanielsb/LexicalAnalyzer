/*
 * author: xdanielsb
 * date: 29-11-2020
 */
#include <bits/stdc++.h>
#define endl '\n'
#define d(x) cout <<#x << " = " << x << ", ";
#define d1( x ) d(x); cout <<endl;
#define d2( x, y ) d(x); d(y); cout <<endl;
#define d3( x, y, z ) d(x); d(y); d(z); cout <<endl;
#define F first
#define S second
#define PB push_back
#define size( x )   int( ( x ).size( ) )
#define endl '\n'
#define all(x) x.begin(),x.end()


#include "src/core.hpp"

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL

#endif
  char ch;
  string buffer;
  const string &pathfile="input/in1.rs";
  fstream file(pathfile, std::fstream::in);

  if (!file.is_open()){
    cout << "Cannot open the file\n";
    exit(0);
  }

  while (file >> std::noskipws >> ch){
    cout <<ch;
    //here should be called the core for the lexical analyser
  }
  return 0;
}
