@echo off

set MATLAB=C:\Users\Utilisateur\Desktop\Matlab_2018_2022

cd .

if "%1"=="" ("C:\Users\UTILIS~1\Desktop\MATLAB~4\bin\win64\gmake"  -f GJK_rtw.mk all) else ("C:\Users\UTILIS~1\Desktop\MATLAB~4\bin\win64\gmake"  -f GJK_rtw.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
An_error_occurred_during_the_call_to_make
