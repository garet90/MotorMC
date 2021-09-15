import json
import sys
import glob
from os import path

if len(sys.argv) != 3:
    print("Usage: item_generator.py <registries.json> <item tags>")
    exit()

f = open(sys.argv[1])

data = json.load(f)

f.close()

items = [None] * len(data["minecraft:item"]["entries"])

for i, n in enumerate(data["minecraft:item"]["entries"]):
	items[i] = { "name": n.split(':')[1], "tags": [] }

tags = [f.replace(sys.argv[2], "")[1:].replace("\\", "/").replace(".json", "") for f in glob.glob(sys.argv[2] + "/**/*",recursive=True) if path.isfile(f)]

def get_all_items_with_tag(tag):
	f = open(sys.argv[2] + "/" + tag + ".json", "r")
	j = json.load(f)
	f.close()
	ret = []
	for item in j["values"]:
		item = item.replace("minecraft:", "")
		if item.startswith("#"):
			ret += get_all_items_with_tag(item[1:])
		else:
			ret.append(item)
	res = []
	for x in ret:
		if x not in res:
			res.append(x)
	return res

print("#include \"items.h\"")
print()

for tag in tags:
	tag_items = get_all_items_with_tag(tag)
	for item in tag_items:
		for i in items:
			if i["name"] == item:
				i["tags"].append(tag)
				break

for item in items:
	print("const mat_item_t mat_item_" + item["name"] + "_d = {")
	for tag in item["tags"]:
		print("\t." + tag + " = true,")
	print("};")

print()
print("const mat_item_t* mat_items[] = {")
for item in items:
	print("\t&mat_item_" + item["name"] + "_d,")
print("};")