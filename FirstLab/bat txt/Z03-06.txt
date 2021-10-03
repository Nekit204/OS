@echo off
chcp 1251 > nul
if "%1" == "" goto A1 

if "%1"=="удалить" if "%2"=="" goto A2
if "%1"=="создать" if "%2"=="" goto A2

if "%1" =="удалить" goto A4
if "%1" =="создать" goto A5

if not "%1"=="удалить" goto A3
if not "%1"=="создать" goto A3


:A1
echo - - строка параметров:
echo - - режим файла:
echo - - имя файла:
echo - - -++ режим = {создать, удалить}
echo - - -++ файл = имя файла
goto end

:A2
echo - - строка параметров:%1
echo - - режим файла:%1
echo - - имя файла:
echo - - -+ не задано имя файла
goto end

:A3
echo - - строка параметров:%1
echo - - режим файла:%1
echo - - имя файла:%2
echo - - -+ режим задан не корректно
goto end

:A4
if exist D:\study\3course\OS\FirstLab\%2 (
del D:\study\3course\OS\FirstLab\%2
echo - - строка параметров:%1
echo - - режим файла:%1
echo - - имя файла:%2
echo - - -+ файл %2 удален
goto end
) else (
echo - - строка параметров:%1
echo - - режим файла:%1
echo - - имя файла:%2
echo - - -+ файла %2 не найден
goto end
)
:A5
if exist D:\study\3course\OS\FirstLab\%2 (
echo - - строка параметров:%1
echo - - режим файла:%1
echo - - имя файла:%2
echo - - -+ файла %2 уже есть
goto end
) else (
echo > %2
echo - - строка параметров:%1
echo - - режим файла:%1
echo - - имя файла:%2
echo - - -+ файл %2 создан
goto end
)

:end
pause