#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int x;
int a;
int b;
int c;
int d;
double z;
string str;

int main()
{
int ti_1;
int ti_2;
int ti_3;
double td_4;
double td_5;
double td_6;
int ti_7;
  cout << "hello, world";
  cout << endl;
  a = 9;
  b = 10;
  ti_1 = 3 * a;
  ti_2 = 2 * b;
  ti_3 = ti_2 * b;
  td_4 = ti_3 + 1.0;
  td_5 = b / td_4;
  td_6 = ti_1 + td_5;
  x = td_6;
  str = "testando str";
  ti_7 = x + 10;
  cout << ti_7;
  cout << endl;
  cout << str;
  cout << endl;
}

