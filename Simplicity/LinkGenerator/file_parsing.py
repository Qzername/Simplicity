from cxxheaderparser.simple import parse_string
import link_creator as lc

def parse(content, sub_dir):
    data = parse_string(content)

    for namespace in data.namespace.namespaces.values():
        f = lc.create_link(namespace.name, sub_dir)

        for function_obj in namespace.functions:
            function_name = function_obj.name.segments[0].name
            return_type = function_obj.return_type.format()
            decl, impl = lc.format_params(function_obj)

            lc.add_function_to_link(f, function_obj, namespace.name)
            print(f"{return_type} {function_name}({decl})")

        lc.close_link(f)

    for class_obj in data.namespace.classes:
        class_name = class_obj.class_decl.typename.segments[0].name
        
        f = lc.create_link(class_name, sub_dir)

        print(class_name + ":")

        for field in class_obj.fields:
            lc.add_field_to_link(f, class_name, field)
            print('\t', "(field)", field.name)
            
        for method in class_obj.methods:    
            lc.add_method_to_link(f, class_name, method)

            method_name = method.name.segments[0].name
            return_type = method.return_type.format() if method.return_type != None else ""
            
            param_str = ""

            for param in method.parameters:
                param_name = param.name
                param_type = param.type.format()
                param_str += param_type + " " + param_name + ", "  

            if len(param_str) > 0:
                param_str = param_str.removesuffix(", ")
                
            print(f"\t {return_type} {method_name}({param_str})")

        lc.close_link(f)