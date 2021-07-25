set pathToFixHeaders=code\SDK\components\ElPack\Code\Source\fix_headers
rem path to fix headers
set pathToAddLibs=code\SDK\components\ElPack\Code\Source\
rem path to headers

for /R %pathToFixHeaders% %%f in (*.hpp) do copy "%%f" %pathToAddLibs%

pause