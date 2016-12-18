#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int _a;

int main(){
  char _mat[4];
  int _i;
  int tb_1;
  int ti_2;
  int _j;
  int tb_3;
  int ti_4;
  int ti_5;
  int ti_6;
  int tb_7;
  int ti_8;
  int tb_9;
  int _ai;
  int tb_10;
  int ti_11;
  int _aj;
  int tb_12;
  int ti_13;
  int ti_14;
  char tc_15;
  int ti_16;
  int tb_17;
  int ti_18;
  int tb_19;
  _i = 0;
l_teste_for_3:;
  tb_1 = _i < 2;
  tb_9 = !tb_1;

if (tb_9) goto l_fim_for_4;
 
  _j = 0;
l_teste_for_1:;
  tb_3 = _j < 2;
  tb_7 = !tb_3;

if (tb_7) goto l_fim_for_2;
 
  ti_5 = _i*2;
  ti_5 = ti_5 + _j;
  _mat[ti_5] = 'a';
 
  ti_4 = _j + 1;

  _j = ti_4;
  goto l_teste_for_1;
l_fim_for_2:;
 
  ti_2 = _i + 1;

  _i = ti_2;
  goto l_teste_for_3;
l_fim_for_4:;
  _ai = 0;
l_teste_for_7:;
  tb_10 = _ai < 2;
  tb_19 = !tb_10;

if (tb_19) goto l_fim_for_8;
 
  _aj = 0;
l_teste_for_5:;
  tb_12 = _aj < 2;
  tb_17 = !tb_12;

if (tb_17) goto l_fim_for_6;
 
  ti_14 = _ai*2;
  ti_14 = ti_14 + _aj;
  tc_15 = _mat[ti_14];
  cout << tc_15;
  cout << endl;
 
  ti_13 = _aj + 1;

  _aj = ti_13;
  goto l_teste_for_5;
l_fim_for_6:;
 
  ti_11 = _ai + 1;

  _ai = ti_11;
  goto l_teste_for_7;
l_fim_for_8:;
  cout << "ola";
  cout << endl;
}

