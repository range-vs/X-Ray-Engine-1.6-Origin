set pathToRadStudio="C:\Program Files (x86)\Embarcadero\Studio\21.0\bin\"
rem path to rad studio bin
set pathToLibs=bins\Win32\Debug\

copy %pathToLibs%elpackB6.bpl %pathToRadStudio%elpackB6.bpl
copy %pathToLibs%elpkdbB6.bpl %pathToRadStudio%elpkdbB6.bpl
copy %pathToLibs%elpproB6.bpl %pathToRadStudio%elpproB6.bpl
copy %pathToLibs%editorB.bpl %pathToRadStudio%editorB.bpl

pause