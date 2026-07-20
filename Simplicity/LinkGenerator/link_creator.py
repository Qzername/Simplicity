from pathlib import Path

links = []

def format_params(method):
    declaration = ", "
    implementation = ", "

    for param in method.parameters:
        param_name = param.name
        param_type = param.type.format()

        declaration += param_type + " " + param_name + ", " 
        implementation += param_name + ", "

    declaration = declaration.removesuffix(", ")
    implementation = implementation.removesuffix(", ")
    
    declaration = declaration[len(", ")::]
    implementation = implementation[len(", ")::]

    declaration = declaration.replace("string&", "char*")

    return declaration, implementation

def create_link(class_name, sub_dir):
    Path(f"./links/{sub_dir}").mkdir(parents=True, exist_ok=True)

    file_path = f"./links/{sub_dir}{class_name}Link.h"
    
    links.append(file_path)
    f = open(file_path, "w")

    f.write("#pragma once\n\n")
    f.write("#define EXPORT __declspec(dllexport)\n\n")
    f.write(f"#include <{sub_dir}{class_name}.h>\n\n")
    f.write("extern \"C\" {\n")

    return f

def add_field_to_link(file, class_name, field):
    if field.access != "public":
        return

    field_type_name = field.type.format()
    
    is_class_type = field_type_name[0].isupper()
    pointer = "*" if is_class_type else ""
    address = "&" if is_class_type else ""

    getter_name = f"{class_name}_get{field.name.capitalize()}"

    file.write(f"   EXPORT {field_type_name}{pointer} {getter_name}({class_name}* obj)\n")
    file.write("   {\n")
    file.write(f"       return {address}obj->{field.name};\n")
    file.write("   }\n\n")

def add_function_to_link(file, function, namespace_name):
    function_name = function.name.segments[0].name

    return_type = function.return_type.format()

    decl, impl = format_params(function)

    file.write(f"   EXPORT {return_type} {namespace_name}_{function_name}({decl})\n")
    file.write("   {\n")
    file.write(f"       return {namespace_name}::{function_name}({impl});\n")
    file.write("   }\n\n")

def add_method_to_link(file, class_name, method):   
    method_name = method.name.segments[0].name
    
    if method.access != "public" or method.destructor:
        return

    if method.return_type == None:	
        decl, impl = format_params(method)

        file.write(f"   EXPORT {class_name}* {class_name}_create({decl.removeprefix(", ")})\n")
        file.write("   {\n")
        file.write(f"       return new {class_name}({impl});\n")
        file.write("   }\n\n")
        return
    
    return_type = method.return_type.format()

    decl, impl = format_params(method)

    if decl != "":
        decl = ", "+decl

    file.write(f"   EXPORT {return_type} {class_name}_{method_name}({class_name}* obj{decl})\n")
    file.write("   {\n")
    file.write(f"       obj->{method_name}({impl});\n")
    file.write("   }\n\n")

def close_link(file):
    file.write("}")
    file.close()

def compile_main():
    f = open("./links/mainHeader.h", "w")

    for link in links:
        f.write(f"#include <{link[len("./links/")::]}>\n")

    f.close()