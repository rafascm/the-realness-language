#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int a;
int b;
char str[256];
int i;
int  MDC(int a, int b ) {
int Result;
int ti_1;
int tb_2;
int ti_3;
int ti_4;
  ti_1 = a % b;
  tb_2 = ti_1 == 0;
  tb_2 = !tb_2;

  if( tb_2 ) goto l_else_1;
  Result = b;
  goto l_end_2;
l_else_1:;
  ti_3 = a % b;
  ti_4 = MDC( b, ti_3 );
  Result = ti_4;
l_end_2:;
 return Result;
}
int  WHATSTHET(int a, int b ) {
int Result;
int tb_5;
  tb_5 = a < b;
  tb_5 = !tb_5;

  if( tb_5 ) goto l_else_3;
  Result = 1;
  goto l_end_4;
l_else_3:;
  Result = 0;
l_end_4:;
 return Result;
}

int main() { 
int ti_6;
int tb_7;
char ts_8[256];
char ts_9[256];
char ts_10[256];
int ti_11;
int ti_12;
int tb_13;
  i = 0;
  a = 32;
  b = 48;
  ti_6 = WHATSTHET( a, b );
  tb_7 = ti_6 == 0;
  tb_7 = !tb_7;

  if( tb_7 ) goto l_else_5;
  cout << "mentira";
  cout << endl;
  goto l_end_6;
l_else_5:;
  cout << "verdade";
  cout << endl;
l_end_6:;
  strncpy( ts_8, "calculando mdc recursivo entre ", 256 );
  strncat( ts_8, "48", 256 );
  strncpy( ts_9, ts_8, 256 );
  strncat( ts_9, " e ", 256 );
  strncpy( ts_10, ts_9, 256 );
  strncat( ts_10, "32", 256 );
  strncpy( str, ts_10, 256 );
  cout << str;
  cout << endl;
  ti_11 = MDC( a, b );
  cout << ti_11;
  cout << endl;
  i = 0;
  ti_12 = 10;
l_teste_for_7:;
  tb_13 = i > ti_12;
  if( tb_13 ) goto l_fim_for_8;
  cout << "oi";
  cout << endl;
  i = i + 1;
  goto l_teste_for_7;
l_fim_for_8:;
}

