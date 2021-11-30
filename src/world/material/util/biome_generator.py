import json
import sys
from os import listdir

if len(sys.argv) == 1:
    print("Please specify an input folder!")
    exit()

biomes = []

print("#include \"material.h\"")
print("#include \"../../util/str_util.h\"")
print("")

for f in listdir(sys.argv[1]):
    file = open(sys.argv[1] + "/" + f)
    data = json.load(file)
    name = f.split('.')[0]
    biomes.append("mat_biome_" + name + "_d")
    print("const mat_biome_t mat_biome_" + name + "_d = {")
    print("\t.name = UTL_CSTRTOSTR(\"minecraft:" + name + "\"),")
    print("\t.precipitation = mat_precipitation_" + data["precipitation"] + ",")
    if "depth" in data:
        print("\t.depth = " + str(data["depth"]) + ",")
    print("\t.temperature = " + str(data["temperature"]) + ",")
    if "temperature_modifier" in data:
        print("\t.temperature_modifier = mat_temperature_modifier_" + data["temperature_modifier"] + ",")
    if "scale" in data:
        print("\t.scale = " + str(data["scale"]) + ",")
    print("\t.downfall = " + str(data["downfall"]) + ",")
    print("\t.category = mat_biome_category_" + data["category"] + ",")
    print("\t.effects = {")
    print("\t\t.sky_color = " + str(data["effects"]["sky_color"]) + ",")
    print("\t\t.water_fog_color = " + str(data["effects"]["water_fog_color"]) + ",")
    print("\t\t.fog_color = " + str(data["effects"]["fog_color"]) + ",")
    if "foliage_color" in data["effects"]:
        print("\t\t.has_foliage_color = true,")
        print("\t\t.foliage_color = " + str(data["effects"]["foliage_color"]) + ",")
    if "grass_color" in data["effects"]:
        print("\t\t.has_grass_color = true,")
        print("\t\t.grass_color = " + str(data["effects"]["grass_color"]) + ",")
    if "grass_color_modifier" in data["effects"]:
        print("\t\t.grass_color_modifier = mat_grass_color_modifier_" + data["effects"]["grass_color_modifier"] + ",")
    if "music" in data["effects"]:
        print("\t\t.music = {")
        print("\t\t\t.sound = UTL_CSTRTOSTR(\"" + data["effects"]["music"]["sound"] + "\"),")
        print("\t\t\t.max_delay = " + str(data["effects"]["music"]["max_delay"]) + ",")
        print("\t\t\t.min_delay = " + str(data["effects"]["music"]["min_delay"]) + ",")
        print("\t\t},")
    if "ambient_sound" in data["effects"]:
        print("\t\t.ambient_sound = UTL_CSTRTOSTR(\"" + data["effects"]["ambient_sound"] + "\"),")
    if "additions_sound" in data["effects"]:
        print("\t\t.additions_sound = {")
        print("\t\t\t.sound = UTL_CSTRTOSTR(\"" + data["effects"]["additions_sound"]["sound"] + "\"),")
        print("\t\t\t.tick_chance = " + str(data["effects"]["additions_sound"]["tick_chance"]) + ",")
        print("\t\t},")
    if "mood_sound" in data["effects"]:
        print("\t\t.mood_sound = {")
        print("\t\t\t.sound = UTL_CSTRTOSTR(\"" + data["effects"]["mood_sound"]["sound"] + "\"),")
        print("\t\t\t.offset = " + str(data["effects"]["mood_sound"]["offset"]) + ",")
        print("\t\t\t.tick_delay = " + str(data["effects"]["mood_sound"]["tick_delay"]) + ",")
        print("\t\t\t.block_search_extent = " + str(data["effects"]["mood_sound"]["block_search_extent"]) + ",")
        print("\t\t},")
    print("\t},")
    if "particle" in data["effects"]:
        print("\t.particle = {")
        print("\t\t.probability = " + str(data["effects"]["particle"]["probability"]) + ",")
        print("\t\t.options = {")
        print("\t\t\t.type = UTL_CSTRTOSTR(\"" + data["effects"]["particle"]["options"]["type"] + "\"),")
        print("\t\t},")
        print("\t},")
    print("};")
    file.close()

print("const mat_biome_t* mat_biomes[] = {")
for biome in biomes:
    print("\t&" + biome + ",")
print("};")