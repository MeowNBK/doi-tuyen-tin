@echo off
REM Kiểm tra tham số
IF "%~1"=="" (
    echo Vui long cung cap ten file C++ lam tham so.
    echo Cu phap: runcpp.bat filename.cpp
    exit /b 1
)

REM Lưu tham số vào biến
SET "FILENAME=%~1"

REM Kiểm tra file tồn tại
IF NOT EXIST "%FILENAME%" (
    echo File %FILENAME% khong ton tai.
    exit /b 1
)

REM Lấy tên file không có đuôi
SET "BASENAME=%~n1"

REM Tạo thư mục output nếu chưa có
IF NOT EXIST "output" (
    mkdir output
)

REM Kiểm tra thời gian sửa đổi của file .cpp và exe
SET "SRC=%FILENAME%"
SET "EXE=output\%BASENAME%.exe"

IF EXIST "%EXE%" (
    FOR %%I IN ("%SRC%") DO SET "SRCTIME=%%~tI"
    FOR %%I IN ("%EXE%") DO SET "EXETIME=%%~tI"

    REM Nếu file exe mới hơn hoặc cùng thời điểm, chạy luôn
    IF "%SRCTIME%" LEQ "%EXETIME%" (
        "%EXE%"
        exit /b 0
    )
)

REM Nếu khong co exe hoac file cpp moi hon, bien dich lai
echo Bien dich %FILENAME%...
g++ "%FILENAME%" -o "%EXE%"
IF ERRORLEVEL 1 (
    echo Loi khi bien dich.
    exit /b 1
)

REM Chay file exe
"%EXE%"
