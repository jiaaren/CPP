#include <iostream>
#include <fstream>
#include <algorithm>

class ClassName
{
    ClassName();
    ~ClassName();
};

void write_cpp(char *className, std::ofstream &cpp)
{
    cpp << "#include \"" << className << ".hpp\"" << std::endl
        << std::endl
        << className << "::" << className << "(void)" << std::endl
        << "{" << std::endl
        << "\treturn;" << std::endl
        << "}" << std::endl
        << std::endl
        << className << "::~" << className << "(void)" << std::endl
        << "{" << std::endl
        << "\treturn;" << std::endl
        << "}" << std::endl
        << std::endl;
}

void write_hpp(char *className, std::ofstream &hpp)
{
    std::string name;
    int i = 0;
    while (className[i])
        name = name + (char)(toupper(className[i++]));

    hpp << "#ifndef " << name << "_H" << std::endl
        << "#define " << name << "_H" << std::endl
        << std::endl
        << "class " << className << std::endl
        << "{" << std::endl
        << "\t" << className << "();" << std::endl
        << "\t~" << className << "();" << std::endl
        << "};" << std::endl
        << std::endl
        << "#endif" << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "./make_class [Class1] [ClassN]" << std::endl;
        return (1);
    }
    int i = 1;
    while (i < argc)
    {
        std::string className = argv[i];
        std::ofstream cpp((className + ".cpp").data());
        if (!cpp)
        {
            std::cout << "file creation failed" << std::endl;
            return (2);
        }
        write_cpp(argv[i], cpp);
        std::ofstream hpp((className + ".hpp").data());
        if (!hpp)
        {
            std::cout << "file creation failed" << std::endl;
            return (2);
        }
        write_hpp(argv[i], hpp);
        cpp.close();
        hpp.close();
        i++;
    }
}