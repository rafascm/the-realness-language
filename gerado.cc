#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int _teste;
char _test;
double _tes;
char _te[256];
int _t;

int main(){
  double _x[2];
  double _z[3];
  int ti_1;
  _x[0] = 0;
  _x[1] = 1;
  _z[0] = 0;
  _z[1] = 1;
  _z[2] = 2;
  ti_1 = memcmp(_z, _x, 24) ; 
  ti_1 = !ti_1;
  ti_1 = !ti_1;

  if( ti_1 ) goto l_else_1;
  cout << "igual";
  cout << endl;
  goto l_end_2;
  l_else_1:;
  cout << "diferente";
  cout << endl;
  l_end_2:;
}

