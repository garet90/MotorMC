import sys
import re
import json
import glob
from os import path

if len(sys.argv) != 3:
    print("Usage: " + sys.argv[0] + " <block file> <verify tags>")
    exit()

block_file = open(sys.argv[1], "r")

blocks = "".join(block_file.readlines())

block_file.close()

tags = [f.replace(sys.argv[2], "")[1:].replace("\\", "/").replace(".json", "") for f in glob.glob(sys.argv[2] + "/**/*",recursive=True) if path.isfile(f)]

def get_all_blocks_with_tag(tag):
	f = open(sys.argv[2] + "/" + tag + ".json", "r")
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

for tag in tags:
	tag_blocks = get_all_blocks_with_tag(tag)
	tag = tag.replace("/", "_")
	if len(tag_blocks) == 0:
		print("Something went wrong at " + tag + "!")
		exit()
	for tag_block in tag_blocks:
		p = re.compile("const mat_block_t mat_block_" + tag_block + "_d = \{\s?\r?\n([\s\S]*?)\r?\n\};")
		i = list(p.finditer(blocks))
		if len(i) == 0:
			print("Couldn't find source for " + tag + "!")
			exit()
		block = i[0].group(1)
		if tag not in block:
			pre = blocks[:i[0].end() - 3]
			post = blocks[i[0].end() - 3:]
			if pre.endswith(","):
				blocks = pre + "\n\t." + tag + " = true," + post
			else:
				blocks = pre + ",\n\t." + tag + " = true," + post

print(blocks)