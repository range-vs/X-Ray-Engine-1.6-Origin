

buildOrderPrew = "<BuildOrder>"
buildOrderNext = "</BuildOrder>"
nameFile = "LevelEditor.cbproj"

all_lines = []
maxBuildOrder = -1

with open(nameFile,"r") as file:
    all_lines = file.readlines()

for line in all_lines:
    if(line.find(buildOrderPrew) != -1):
        newLine = line
        newLine = line.replace(buildOrderPrew, "").replace(buildOrderNext, "")
        tmpMaxBuildOrder = int(newLine)
        maxBuildOrder = max(tmpMaxBuildOrder, maxBuildOrder)

print(maxBuildOrder)