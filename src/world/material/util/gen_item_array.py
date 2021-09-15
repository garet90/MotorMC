import json
import sys

if len(sys.argv) == 1:
    print("Please specify an input file!")
    exit()

f = open(sys.argv[1])

data = json.load(f)

f.close()

for i in data["minecraft:item"]["entries"]:
	name = i.split(':')[1]
	print("mat_item_" + name + ",")