import sys
import re
import json

if len(sys.argv) != 3:
    print("Usage: " + sys.argv[0] + " <block file> <verify json>")
    exit()

test_file = open(sys.argv[2], "r")
test_data = json.load(test_file)

test_file.close()

block_file = open(sys.argv[1], "r")

lines = block_file.readlines()

data_line = True
data_name = None
test_block = None
for line in lines:
    if line.startswith("const mat_block_t mat_block_"):
        data_line = True
        data_name = re.sub(r'_d = {\s?', '', line.replace("const mat_block_t mat_block_", "").replace("\n", ""))
        test_block = None
        for i in test_data:
            if i["name"] == data_name:
                test_block = i
                break

        if test_block is None:
            print("Could not find matching block for " + data_name)
            exit()
    elif line.startswith("};"):
        data_line = False

    if data_line:
        if line.startswith("    .resistance = "):
            resistance = float(line.replace("    .resistance = ", "").replace(",\n", ""))
            if test_block["diggable"] == False:
                test_block["hardness"] = -1
            if test_block["resistance"] != resistance:
                print("Resistance for", data_name, "differs!", test_block["resistance"], "vs", resistance)
                exit()
        elif line.startswith("    .hardness = "):
            hardness = float(line.replace("    .hardness = ", "").replace(",\n", ""))
            if test_block["hardness"] != hardness:
                print("Hardness for", data_name, "differs!", test_block["hardness"], "vs", hardness)
                exit()
        elif line.startswith("    .luminance = "):
            luminance = int(line.replace("    .luminance = ", "").replace(",\n", ""))
            if test_block["emitLight"] != luminance:
                print("Luminance for", data_name, "differs!", test_block["emitLight"], "vs", luminance)
                exit()

block_file.close()

print("All checks passed!")