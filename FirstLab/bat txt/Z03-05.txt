@echo off
chcp 1251>nul
echo - - строка параметров: %1 %2 %3 
echo - - параметр 1:%1
echo - - параметр 2:%2
echo - - параметр 3:%3
set /A res=%1 %3 %2
echo - - Результат:%res%
pause