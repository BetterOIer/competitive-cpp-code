@echo off
:loop
    data.exe > in.txt
    sample1.exe < in.txt > out1.txt
    sample2.exe < in.txt > out1.txt
    fc out1.txt out2.txt
if not errorlevel 1 goto loop
pause
goto loop