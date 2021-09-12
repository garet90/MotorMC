import sys

if len(sys.argv) != 3:
    print("Usage: " + sys.argv[0] + " <block file> <tag>")
    exit()

block_file = open(sys.argv[1], "r")
blocks = block_file.readlines()
block_file.close()

i = 0
current_block = None
while i < len(blocks):
	block = blocks[i]
	i += 1
	if block.startswith("const mat_block_t mat_block_"):
		current_block = block.replace("const mat_block_t mat_block_", "").replace("_d = {", "").strip()
	if block is not None and sys.argv[2] in block:
		print("\t\tmat_block_" + current_block + ",")