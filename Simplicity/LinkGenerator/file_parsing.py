from cxxheaderparser.simple import parse_string
import link_creator as lc

def parse(content):
    data = parse_string(content)

    for class_obj in data.namespace.classes:
        class_name = class_obj.class_decl.typename.segments[0].name
        
        f = lc.create_link(class_name)

        print(class_name + ":")

        for field in class_obj.fields:
            lc.add_field_to_link(f, class_name, field)
            
        for method in class_obj.methods:    
            lc.add_method_to_link(f, class_name, method)

            method_name = method.name.segments[0].name
        

            if method.return_type != None:	
                return_type = method.return_type.format()
            else:
                return_type = ""

            param_str = ""

            for param in method.parameters:
                param_name = param.name
                param_type = param.type.format()
                param_str += param_type + " " + param_name + ", "  

            if len(param_str) > 0:
                param_str = param_str.removesuffix(", ")
                
            print("  ", return_type, method_name + "("+ param_str+")")

        lc.close_link(f)