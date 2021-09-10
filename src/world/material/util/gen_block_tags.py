import sys
import json
import glob
from os import path

if len(sys.argv) != 2:
    print("Usage: " + sys.argv[0] + " <block tags>")
    exit()

tags = [f.replace(sys.argv[1], "")[1:].replace("\\", "/").replace(".json", "") for f in glob.glob(sys.argv[1] + "/**/*",recursive=True) if path.isfile(f)]

def get_all_blocks_with_tag(tag):
	f = open(sys.argv[1] + "/" + tag + ".json", "r")
	j = json.load(f)
	f.close()
	ret = []
	for block in j["values"]:
		block = block.replace("minecraft:", "")
		if block.startswith("#"):
			ret += get_all_blocks_with_tag(block[1:])
		else:
			ret.append(block)
	res = []
	for x in ret:
		if x not in res:
			res.append(x)
	return res

out = ""

for tag in tags:
	tag_blocks = get_all_blocks_with_tag(tag)
	out += "const mat_tag_t mat_block_tag_" + tag.replace("/", "_") + "_d = {\n\t.identifier = UTL_CSTRTOSTR(\"minecraft:" + tag + "\"),\n\t.count = " + str(len(tag_blocks)) + ",\n\t.entries = {\n"
	for block in tag_blocks:
		out += "\t\tmat_block_" + block.replace("/", "_") + ",\n"
	out += "\t}\n"
	out += "};\n"

print(out)