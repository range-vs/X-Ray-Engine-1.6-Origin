set pathToMkexp="C:\Program Files (x86)\Embarcadero\Studio\21.0\bin\mkexp.exe"
rem path to coff2omf
set pathToDlls=bins\Win64\Release\
rem path to compiled dlls
set pathToAddDlls=code\SDK\binaries\Win64\
rem path to additional dlls
set pathOutLibs=libraries\Win64\Release\
rem path to out generated libraries

%pathToMkexp% %pathOutLibs%etoolsb.a %pathToDlls%etools.dll
%pathToMkexp% %pathOutLibs%openalb.a %pathToDlls%openal.dll
%pathToMkexp% %pathOutLibs%dsoundb.a %pathToAddDlls%dsound.dll"
%pathToMkexp% %pathOutLibs%xrParticlesB.a %pathToDlls%xrParticles.dll
%pathToMkexp% %pathOutLibs%xrPhysicsB.a %pathToDlls%xrPhysics.dll
%pathToMkexp% %pathOutLibs%dinput8B.a %pathToAddDlls%dinput8.dll
%pathToMkexp% %pathOutLibs%FreeImageB.a %pathToAddDlls%FreeImage.dll
%pathToMkexp% %pathOutLibs%DXTB.a %pathToDlls%DXT.dll
%pathToMkexp% %pathOutLibs%MagicFMB.a %pathToDlls%MagicFM.dll
%pathToMkexp% %pathOutLibs%d3dx9d_41.a %pathToAddDlls%d3dx9d_41.dll"
%pathToMkexp% %pathOutLibs%LWOB.a %pathToDlls%LWO.dll

copy code\SDK\binaries\Win64\FreeImage.dll %pathToDlls%FreeImage.dll
copy code\SDK\binaries\Win64\amd_ags_x64.dll %pathToDlls%amd_ags_x64.dll

pause