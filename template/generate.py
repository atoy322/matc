import os
import re


comment = re.compile(r"/\* (.+) \*/", re.DOTALL)

supported_types = {
        "I": "int",
        "F": "float",
        "D": "double",
        "L": "long"
}
printf_formats = {
        "I": "3d",
        "F": "5.2f",
        "D": "5.2f",
        "L": "4ld"
}

files = [i for i in os.listdir(".") if i[-1]=="c" or i[-1]=="h"]


for file in files:
    with open(file, "r") as f:
        content = f.read()

    match = comment.search(content)
    
    if match == None:
        continue

    template = match.group(1)
    code = ""

    for key in supported_types.keys():
        code += "\n"
        code += template.replace("XXX", key)
        code = code.replace("YYY", supported_types[key])
        code = code.replace("__FMT__", printf_formats[key])
        code += "\n"
    
    print(f"----- {file} ------")
    print(code)

    content = content.replace("// {INSERT}", code)

    with open(f"generated/{file}", "w") as f:
        f.write(content)

