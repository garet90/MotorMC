import json
import sys

if len(sys.argv) == 1:
    print("Please specify an input file!")
    exit()

f = open(sys.argv[1])

data = json.load(f)

items = []

for i in data:
    name = "mat_block_" + i.split(':')[1]
    for j in data[i]["states"]:
        while j["id"] >= len(items):
            items.append(None)
        
        items[j["id"]] = name

print("const mat_block_id_t mat_blocks_protocol[] = {")

for i in items:
    print("\t" + i + ",")

print("};")

f.close()