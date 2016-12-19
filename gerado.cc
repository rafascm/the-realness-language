#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

char _nome_i[256];
char _u_nome[256];

int main(){
  char _greeting[256];
  char ts_1[256];
  char ts_2[256];
  int ti_3;
  int ti_4;
  char ts_5[256];
  char ts_6[256];
  char ts_7[256];
  char ts_8[256];
  char _str1[256];
  char _str2[256];
  int tb_9;
  char ts_10[256];
  char ts_11[256];
  char ts_12[256];
  char ts_13[256];
  int tb_14;
  char ts_15[256];
  char ts_16[256];
  char ts_17[256];
  char ts_18[256];
  strncpy(_greeting, "Hiiii!", 256);
  strncpy(ts_1, "\n", 256);
  strncat(ts_1, _greeting, 256);
  strncpy(ts_2, ts_1, 256);
  strncat(ts_2, " Let's start some string testing!\n", 256);
  cout << ts_2;
  cout << endl;
  cout << "Tell me your first and last name :)";
  cout << endl;
  fgets(_nome_i, 256, stdin);
  ti_3 = strcspn(_nome_i, "\n");
  _nome_i[ti_3] = 0;
  fgets(_u_nome, 256, stdin);
  ti_4 = strcspn(_u_nome, "\n");
  _u_nome[ti_4] = 0;
  strncpy(ts_5, "\nWelcome ", 256);
  strncat(ts_5, _nome_i, 256);
  strncpy(ts_6, ts_5, 256);
  strncat(ts_6, " ", 256);
  strncpy(ts_7, ts_6, 256);
  strncat(ts_7, _u_nome, 256);
  strncpy(ts_8, ts_7, 256);
  strncat(ts_8, " to my reality.\n", 256);
  cout << ts_8;
  cout << endl;
  cout << "Showing string oprs == > < !=";
  cout << endl;
  strncpy(_str1, "Mama Ru", 256);
  strncpy(_str2, "Ruzie Q", 256);
  tb_9 = strcmp(_str1, _str2) ;
  tb_9 = tb_9 == 0;
  tb_9 = !tb_9;

  if( tb_9 ) goto l_else_1;
  strncpy(ts_10, _str1, 256);
  strncat(ts_10, " == ", 256);
  strncpy(ts_11, ts_10, 256);
  strncat(ts_11, _str2, 256);
  cout << ts_11;
  cout << endl;
  goto l_end_2;
  l_else_1:;
  strncpy(ts_12, _str1, 256);
  strncat(ts_12, " != ", 256);
  strncpy(ts_13, ts_12, 256);
  strncat(ts_13, _str2, 256);
  cout << ts_13;
  cout << endl;
  l_end_2:;
  tb_14 = strcmp(_str2, _str1) ;
  tb_14 = tb_14 > 0;
  tb_14 = !tb_14;

  if( tb_14 ) goto l_else_3;
  strncpy(ts_15, _str2, 256);
  strncat(ts_15, " > ", 256);
  strncpy(ts_16, ts_15, 256);
  strncat(ts_16, _str1, 256);
  cout << ts_16;
  cout << endl;
  goto l_end_4;
  l_else_3:;
  strncpy(ts_17, _str2, 256);
  strncat(ts_17, " < ", 256);
  strncpy(ts_18, ts_17, 256);
  strncat(ts_18, _str1, 256);
  cout << ts_18;
  cout << endl;
  l_end_4:;
  cout << "";
  cout << endl;
}

