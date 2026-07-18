import sys
import os
import file_parsing  as fp
import glob
curr_dir = os.path.dirname(os.path.abspath(sys.argv[0]))
library_include_path = curr_dir+"/../Simplicity/include/"
files = glob.glob(library_include_path+ "**/*", recursive=True)

for file in files:
	print(file)

	if file.endswith("coreDefinitions.h"):
		continue

	if not file.endswith(".h"):
		continue

	header_file = open(file, "r")
	content = header_file.read()

	if not "CPP_LIB_EXP" in content:
		continue

	content = content.replace("CPP_LIB_EXP ", "")
	content = content.replace("explicit", "")

	fp.parse(content)