set currDir=%cd%\..\bins\Win32\Debug\
Pushd "E:\Program Files\X-Ray CoP SDK\editors"
"%currDir%xrAI.exe" -f test_sdk_level_x86 -draft -keep_temp_files
pause