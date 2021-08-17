
final = ["#pragma once"]
parsed = []

def pathConcat(p1, p2):
    path = p1.split("/")[:-1] + p2.split("/")
    i = 0
    while i < len(path):
        if path[i] == ".." and i > 0 and path[i - 1] != "..":
            path.pop(i - 1)
            path.pop(i - 1)
            i -= 1
            continue
        i += 1
    return "/".join(path)

def processFile(name):
    print("Processing file '" + name + "'...")
    with open(name, 'r') as file:
        lines = file.read().split('\n')

        blockLevel = 0
        blockInclude = False

        for line in lines:
            if line.isspace() or line == "" or line.startswith("//") or (line.startswith ("/*") and "*/" in line):
                continue

            if '{' in line:
                blockLevel += 1

            if blockLevel == 0:
                blockInclude = False
                if line.startswith('#include "'):
                    spl = line.split('"')
                    if len(spl) > 1:
                        path = pathConcat(name, spl[1])
                        if not (path in parsed):
                            processFile(path)
                            parsed.append(path)
                elif not (line == "#pragma once" or line.startswith("extern") or line.startswith("static const")):
                    final.append(line)
            elif blockInclude:
                final.append(line)
            elif blockLevel == 1:
                if line.startswith("#define") or line.startswith("typedef") or line.startswith("struct"):
                    blockInclude = True
                    final.append(line)
                else:
                    blockInclude = False
            
            if '}' in line:
                blockLevel -= 1

processFile("plugin.h")

final.append("static const plg_interface_t* motor;")
final.append("")

with open("plugin-header.h", 'w') as file:
    file.write("\n".join(final))