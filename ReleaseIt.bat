@echo off
:: Copy binary files x64
xcopy Release-x64\*.dll RELEASE\x64\ /y /v
xcopy Release-x64\*.lib RELEASE\x64\ /y /v
:: Copy binary files x86
xcopy Release-Win32\*.dll RELEASE\x86\ /y /v
xcopy Release-Win32\*.lib RELEASE\x86\ /y /v
:: Copy header-files
xcopy libs\ecm\ecm\*.h RELEASE\include\ecm\ /y /v /s
xcopy libs\ecm\ecm\*.hpp RELEASE\include\ecm\ /y /v /s
xcopy libs\ecm.algorithm\ecm\*.h RELEASE\include\ecm\ /y /v /s
xcopy libs\ecm.algorithm\ecm\*.hpp RELEASE\include\ecm\ /y /v /s
:: Pack released library
"C:\Program Files\7-Zip\7z.exe" a -r -mx9 .\RELEASE\ecm_win32_x64_full.7z .\RELEASE\x64\
"C:\Program Files\7-Zip\7z.exe" a -r -mx9 .\RELEASE\ecm_win32_x86_full.7z .\RELEASE\x86\
"C:\Program Files\7-Zip\7z.exe" a -r -mx9 .\RELEASE\ecm_win32_x64_full.7z .\RELEASE\include\
"C:\Program Files\7-Zip\7z.exe" a -r -mx9 .\RELEASE\ecm_win32_x86_full.7z .\RELEASE\include\
::pause
timeout -t 10
