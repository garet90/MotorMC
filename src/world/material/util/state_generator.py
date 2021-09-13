import json
import sys

if len(sys.argv) == 1:
    print("Please specify an input file!")
    exit()

f = open(sys.argv[1])

data = json.load(f)

f.close()

items = []
base_protocol = [-1] * len(data)
default_protocol = [-1] * len(data)

block_id = 0
for i in data:
    name = "mat_block_" + i.split(':')[1]

    base_protocol[block_id] = data[i]["states"][0]["id"]

    for j in data[i]["states"]:
        while j["id"] >= len(items):
            items.append(None)
        items[j["id"]] = name
        if "default" in j and j["default"]:
            default_protocol[block_id] = j["id"]
    block_id += 1

print("const uint16_t mat_blocks_protocol[] = {")

for i in items:
    print("\t" + i + ",")

print("};")
print("")
print("const uint16_t mat_blocks_base_protocol[] = {")

for i in base_protocol:
    print("\t" + str(i) + ",")

print("};")
print("")
print("const uint16_t mat_blocks_default_protocol[] = {")

for i in default_protocol:
    print("\t" + str(i) + ",")

print("};")