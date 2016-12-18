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
  int _x[2];
  double _z[3];
  int tb_1;
  int ti_2;
  int ti_3;
  int ti_4;
  _x[0] = 0;
  _x[1] = 1;
  _z[0] = 0;
  _z[1] = 1;
  _z[2] = 2;


  tb_1 = 0;
  ti_2 = _x[0];
  ti_3 = 1 == ti_2;
  ti_3 = !ti_3;
  if (ti_3) goto l_not_in_2;
    tb_1 = 1;
  goto l_in_1;
l_not_in_2:;

  ti_2 = _x[1];
  ti_4 = 1 == ti_2;
  ti_4 = !ti_4;
  if (ti_4) goto l_not_in_3;
    tb_1 = 1;
  goto l_in_1;
l_not_in_3:;

l_in_1:;
  tb_1 = !tb_1;

  if( tb_1 ) goto l_else_4;
  cout << "ta dentro";
  cout << endl;
  goto l_end_5;
  l_else_4:;
  cout << "nao ta dentro";
  cout << endl;
  l_end_5:;
}

