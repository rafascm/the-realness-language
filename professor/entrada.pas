Program HelloWorld;

Var
   a,b :Integer;
   str : String;
   i : Integer;

Function MDC( a, b : Integer ): Integer;
Begin
   If a Mod b = 0 Then
      Result := b
   Else
      Result := MDC( b, a Mod b );
End;

Function WHATSTHET(a,b : Integer): Boolean;
Begin
   If a < b Then
      Result := 1
Else
      Result := 0;
End;

Begin
   i :=0;
   a := 32;
   b := 48;
   If WHATSTHET(a,b) = 0 Then
      WriteLn('mentira')
   Else
      WriteLn('verdade');

   str := 'calculando mdc recursivo entre ' + '48' + ' e ' + '32';
   WriteLn(str);
   WriteLn( MDC( a, b ) );

   For i := 0 To 10 Do
      WriteLn('oi');


End.
