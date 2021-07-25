import os
import re
import shutil

dirNameSrc = "C:\\src_cop\\code\\"
log = "log.txt"
rootFolder = "C:\\fix_defines"
becapFolder = "src_cop_old"
newFolder = "src_cop_new"

def DEF_VECTOR(N,T):
    return "typedef xr_vector< " + T + " > " + N + "; typedef " + N + "::iterator " + N + "_it;\n"
def DEF_LIST(N,T):
    return "typedef xr_list< " + T + " > " + N + "; typedef " + N + "::iterator " + N + "_it;\n"
def DEF_DEQUE(N,T):
    return "typedef xr_deque< " + T + " > " + N + "; typedef " + N + "::iterator " + N + "_it;\n"
def DEF_MAP(N,K,T):
    return "typedef xr_map< " + K + ", " + T + " > " + N + "; typedef " + N + "::iterator " + N + "_it;\n"
def DEFINE_DEQUE(T, N, I):
    return "typedef xr_deque< " + T + " > " + N + "; typedef " + N + "::iterator " +  I + ";\n"
def DEFINE_LIST(T, N, I):
    return "typedef xr_list< " + T + " > " + N + "; typedef " + N + "::iterator " +  I + ";\n"
def DEFINE_VECTOR(T, N, I):
    return "typedef xr_vector< " + T + " > " + N + "; typedef " + N + "::iterator " +  I + ";\n"
def DEFINE_MAP(K, T, N, I):
    return "typedef xr_map< " + K + "," + T + " > " + N + "; typedef " + N + "::iterator " +  I + ";\n"
def DEFINE_MAP_PRED(K, T, N, I, P):
    return "typedef xr_map< " + K + "," + T + ", " + P + " > " + N + "; typedef " + N + "::iterator " +  I + ";\n"
def DEFINE_MMAP(K, T, N, I):
    return "typedef xr_multimap< " + K + "," + T + " > " + N + "; typedef " + N + "::iterator " +  I + ";\n"
def DEFINE_SVECTOR(T, C, N, I):
    return "typedef svector< " + T + "," + C + " > " + N + "; typedef " + N + "::iterator " +  I + ";\n"
def DEFINE_SET(T, N, I):
    return "typedef xr_set< " + T + " > " + N + "; typedef " + N + "::iterator " +  I + ";\n"
def DEFINE_SET_PRED(T, N, I, P):
    return "typedef xr_set< " + T + ", " + P + " > " + N + "; typedef " + N + "::iterator " +  I + ";\n"
def DEFINE_STACK(T, N):
    return "typedef xr_stack< " + T + " > " + N + ";\n"
def DEF_UILIST(N,T):
    return DEF_VECTOR(N,T)

definesDict = {
    "DEF_VECTOR": DEF_VECTOR,
    "DEF_LIST":DEF_LIST,
    "DEF_DEQUE":DEF_DEQUE,
    "DEF_MAP":DEF_MAP,
    "DEFINE_DEQUE":DEFINE_DEQUE,
    "DEFINE_LIST":DEFINE_LIST,
    "DEFINE_VECTOR":DEFINE_VECTOR,
    "DEFINE_MAP":DEFINE_MAP,
    "DEFINE_MAP_PRED":DEFINE_MAP_PRED,
    "DEFINE_MMAP":DEFINE_MMAP,
    "DEFINE_SVECTOR":DEFINE_SVECTOR,
    "DEFINE_SET":DEFINE_SET,
    "DEFINE_SET_PRED":DEFINE_SET_PRED,
    "DEFINE_STACK":DEFINE_STACK,
    "DEF_UILIST":DEF_UILIST
}




fullBecapFolder = os.path.join(rootFolder, becapFolder )
if os.path.exists(fullBecapFolder):
    shutil.rmtree(fullBecapFolder, ignore_errors=True) 
os.makedirs(fullBecapFolder)
fullNewFolder = os.path.join(rootFolder, newFolder )
if os.path.exists(fullNewFolder):
    shutil.rmtree(fullNewFolder, ignore_errors=True) 
os.makedirs(fullNewFolder)

with open(log,"w") as fileLog:
    for root, dirs, files in os.walk(dirNameSrc):
        for filename in files:
            if filename.lower().endswith(tuple([".cpp", ".h", ".hpp", ".c"])):
                filenameFull = os.path.join(root, filename) 
                with open(filenameFull,"r") as file:
                    all_lines = file.readlines()
                new_lines = [] # буфер для новых строк
                i = 0
                for _str in all_lines:
                    strFix = _str
                    for define in definesDict:
                        if re.search(r"(" + define + ")([\s\(]+)", strFix) != None and re.match(r"([\s]*)(\/\/)", strFix) == None:
                            i += 1
                            if i == 1:
                                print(filenameFull)
                                fileLog.write(filenameFull + "\n")
                                # сохраняем старый файл
                                fullBecapRoot = os.path.join(fullBecapFolder,root.replace(dirNameSrc, ""))
                                if not os.path.exists(fullBecapRoot): # если каталога нет - создаем
                                    os.makedirs(fullBecapRoot)
                                shutil.copyfile(filenameFull, os.path.join(fullBecapFolder, fullBecapRoot, filename)) # копируем старый файл
                            print(strFix)
                            fileLog.write(strFix + "\n")
                            # производим замену строки
                            leftSpaces = strFix.replace(strFix.lstrip(), "") # получаем пробелы в начале строки
                            strFix = strFix.replace(define, "") # получаем типы аргументов из строки и конструируем Tuple
                            _args = re.sub(r"([\s\(\);]*)", "", strFix).split(",")
                            for i in range(0, len(_args)):
                                if(_args[i].find("const") != -1):
                                    _args[i] = _args[i].replace("const", " const ")
                            args = tuple(_args)
                            newString = definesDict[define](*args) # конструируем код для замены
                            strFix = leftSpaces + newString # конструируем новую строку
                            break
                    new_lines.append(strFix)
                # создаем новый файл
                if i != 0:
                    fullNewRoot = os.path.join(fullNewFolder,root.replace(dirNameSrc, ""))
                    if not os.path.exists(fullNewRoot): # если нового каталога нет - создаем
                        os.makedirs(fullNewRoot)
                    with open(os.path.join(fullNewFolder, fullNewRoot, filename),"w") as newFile: # записываем файл
                        newFile.writelines(new_lines)