from pathlib import Path

links = []

def create_link(class_name):
    Path("./links/").mkdir(parents=True, exist_ok=True)

    file_path = "./links/" + class_name + "Link.h"
    
    links.append(file_path)
    f = open(file_path, "w")

    f.write("#pragma once\n")
    f.write("\n")
    f.write("#define EXPORT __declspec(dllexport)\n")
    f.write("\n")
    f.write(f"#include <{class_name}.h>\n")
    f.write("\n")
    f.write("extern \"C\" {\n")

    return f

def add_field_to_link(file, class_name, field):
    file.write(f"   EXPORT {class_name}* {class_name}_create()\n")
    file.write("   {\n")
    file.write(f"       return new {class_name}()\n")
    file.write("   }\n\n")

def add_method_to_link(file, class_name, method):   
    method_name = method.name.segments[0].name
    
    if method.access != "public" or method.destructor:
        return

    if method.return_type == None:	
        file.write(f"   EXPORT {class_name}* {class_name}_create()\n")
        file.write("   {\n")
        file.write(f"       return new {class_name}()\n")
        file.write("   }\n\n")
        return
    
    return_type = method.return_type.format()

    parameters = ", "
    called_method_parameters = ", "

    for param in method.parameters:
        param_name = param.name
        param_type = param.type.format()
        parameters += param_type + " " + param_name + " "  

        called_method_parameters = param_name + ", "

    parameters = parameters.removesuffix(", ")
    called_method_parameters = called_method_parameters.removesuffix(", ")
                
    file.write(f"   EXPORT {return_type} {class_name}_{method_name}({class_name}* window{parameters})\n")
    file.write("   {\n")
    file.write(f"       window->{method_name}({called_method_parameters});\n")
    file.write("   }\n\n")

def close_link(file):
    file.write("}")

def compile_main():
    pass