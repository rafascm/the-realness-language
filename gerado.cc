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
  char _aa[256];
  int tb_1;
  char ts_2[256];
  strncpy(_te, "oiaa", 256);
  strncpy(_aa, "oiaa", 256);
  cout << _aa;
  cout << endl;
  tb_1 = strcmp(_aa, _te) ;
  tb_1 = tb_1 == 0;
  tb_1 = !tb_1;

  if( tb_1 ) goto l_else_1;
  cout << "é igual";
  cout << endl;
  goto l_end_2;
  l_else_1:;
  cout << "nao é igual";
  cout << endl;
  l_end_2:;
  strncpy(ts_2, "que ", 256);
  strncat(ts_2, _te, 256);
  cout << ts_2;
  cout << endl;
}

