@echo off
title Unit tests
ECHO Compiling all tests...
cd tests

g++ -std=c++11 LoggerTest.cpp -w -D _ATEST_ -o out/LoggerTest.exe
ECHO LoggerTest.cpp compilation done

g++ -std=c++11 IPSplitterTest.cpp -w -D _ATEST_ -o out/IPSplitterTest.exe
ECHO IPSplitterTest.cpp compilation done

g++ -std=c++11 ConnectorTest.cpp -w -D _ATEST_ -o out/ConnectorTest.exe
ECHO ConnectorTest.cpp compilation done

cd out
for %%i in (*.exe) do (
    ECHO Testing %%i
    %%i
)
ECHO Press any key to exit...
pause>nul