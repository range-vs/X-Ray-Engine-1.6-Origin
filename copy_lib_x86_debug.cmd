set pathToCoff2Omf="C:\Program Files (x86)\Embarcadero\Studio\21.0\bin\coff2omf.exe"
rem path to coff2omf
set pathToLibs=libraries\Win32\Debug\
rem path to compiled libs
set pathToAddLibs=code\SDK\libraries\Win32\
rem path to additional libs
set pathToDlls=bins\Win32\Debug\
rem path to compiled dlls

%pathToCoff2Omf% %pathToLibs%etools.lib %pathToLibs%etoolsb.lib
%pathToCoff2Omf% %pathToAddLibs%dsound.lib %pathToLibs%dsoundb.lib
%pathToCoff2Omf% %pathToLibs%openal.lib %pathToLibs%openalb.lib
%pathToCoff2Omf% %pathToLibs%xrphysics.lib %pathToLibs%xrphysicsb.lib
%pathToCoff2Omf% %pathToLibs%lwo.lib %pathToLibs%lwob.lib
%pathToCoff2Omf% %pathToLibs%dxt.lib %pathToLibs%dxtb.lib
%pathToCoff2Omf% %pathToAddLibs%freeimage.lib %pathToLibs%freeimageb.lib
%pathToCoff2Omf% %pathToAddLibs%dinput8.lib %pathToLibs%dinput8b.lib
%pathToCoff2Omf% %pathToLibs%magicfm.lib %pathToLibs%magicfmb.lib

copy code\SDK\binaries\Win32\FreeImage.dll %pathToDlls%FreeImage.dll
copy code\SDK\binaries\Win32\amd_ags_x86.dll %pathToDlls%amd_ags_x86.dll

pause