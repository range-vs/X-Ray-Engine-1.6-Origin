import os
import shutil
import xml.etree.ElementTree as ET


ext = ".vcxproj"
path = "../../"

pathOut = "C:/copy_vcxproj"

def removeNodes(project, conditionalGeneral, conditionalDebug, conditionalRelease):
    itemGroup = project[0]
    for cfg in itemGroup:
        for k in cfg.attrib:
            if k == conditionalGeneral and cfg.attrib[k].find(conditionalDebug) != 0 and cfg.attrib[k].find(conditionalRelease) != 0:
                print(cfg.attrib[k])
                itemGroup.remove(cfg)
                return True
    return False

def removeNodesBig(project, conditionalGeneral, conditionalDebug, conditionalRelease):
    for cfg in project:
        for k in cfg.attrib:
            if k == conditionalGeneral and cfg.attrib[k].find(conditionalDebug) == -1 and cfg.attrib[k].find(conditionalRelease) == -1:
                print(cfg.attrib[k])
                project.remove(cfg)
                return True
    return False
        

if os.path.exists(pathOut):
    shutil.rmtree(pathOut)
os.mkdir(pathOut)
for root, dirs, files in os.walk(path):
    for file in files:
        if file.endswith(ext):
            newPath = root.replace("../", "")
            if not os.path.exists(os.path.join(pathOut, newPath)):
                os.makedirs(os.path.join(pathOut, newPath))
            shutil.copyfile(os.path.join(root, file), os.path.join(pathOut, newPath, file))

ET.register_namespace("", "http://schemas.microsoft.com/developer/msbuild/2003") 
for root, dirs, files in os.walk(pathOut):
    for file in files:
        tree = ET.parse(os.path.join(root, file))
        rootXML = tree.getroot()
        project = rootXML.getchildren()
        while True:
            if not removeNodes(project, "Include", "Debug|", "Release|"):
                break
        for cfg in project:
            while True:
                if not removeNodesBig(project,"Condition", "=='Debug|", "=='Release|"):
                    break
        for e in rootXML.getchildren():
            rootXML.remove(e)
        for e in project:
            rootXML.append(e)
        project = rootXML.getchildren()
        newXML = ET.ElementTree()
        newXML._setroot(rootXML)
        with open(os.path.join(root, file), "wb") as f:
            newXML.write(f)
        print("--------------------------------------------")

# TODO: тест сборки win32 debug, потом release