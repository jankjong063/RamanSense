@echo off

REM Define the source and destination paths
set "source=C:\Users\88691\AppData\Local\Temp\arduino\sketches\CC913CD616C6E8897D81536F75601F29\RamanSense.ino.elf"
set "destination=%~dp0\RamanSense.ino.elf"

REM Check if source file exists
if exist "%source%" (
    echo Copying file to the project folder...
    copy "%source%" "%destination%"
    echo File copied successfully.
) else (
    echo Source file not found. Ensure the .elf file is generated.
)

pause
