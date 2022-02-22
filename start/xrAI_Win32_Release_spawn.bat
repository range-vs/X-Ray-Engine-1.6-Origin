set currDir=%cd%\..\bins\Win32\Release\
Pushd "E:\Program Files\X-Ray CoP SDK\editors"
"%currDir%xrAI.exe" -no_separator_check -s test_sdk_level
pause