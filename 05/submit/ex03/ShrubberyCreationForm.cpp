#include <iostream>
#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form(FORM_NAME, MIN_SIGN, MIN_EXEC)
{
    setTarget("self");
    std::cout << FORM_NAME << " form, targetted to " << getTarget() << ", created" << std::endl;
    return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : Form(FORM_NAME, MIN_SIGN, MIN_EXEC)
{
    setTarget(target);
    std::cout << FORM_NAME << " form, targetted to " << getTarget() << ", created" << std::endl;
    return;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &f) : Form(FORM_NAME, MIN_SIGN, MIN_EXEC)
{
    *this = f;
    std::cout << FORM_NAME << " form, targetted to " << getTarget() << ", created" << std::endl;
    return;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << FORM_NAME << " form, destroyed" << std::endl;
    return;
}

// not sure if this would work, or would have a better way
ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
    Form::operator=(rhs);
    setTarget(rhs.getTarget());
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!(getSigned()))
    {
        std::cout << "Form not yet signed" << std::endl;
        return;
    }
    checkExec(executor);
    std::string filename(getTarget() + "_shrubbery");
    // need to use .data(), ofs don't accept filename
    std::ofstream ofs(filename.data());
    if (!ofs)
    {
        std::cout << "File creation " << filename << " failed" << std::endl;
        return;
    }
    ofs
        << ""

           "           *             ,\n"
           "                       _/^\\_\n"
           "                      <     >\n"
           "     *                 /.-.\\         *\n"
           "              *        `/&\\`                   *\n"
           "                      ,@.*;@,\n"
           "                     /_o.I %_\\    *\n"
           "        *           (`'--:o(_@;\n"
           "                   /`;--.,__ `')             *\n"
           "                  ;@`o % O,*`'`&\\\n"
           "            *    (`'--)_@ ;o %'()\\      *\n"
           "                 /`;--._`''--._O'@;\n"
           "                /&*,()~o`;-.,_ `\"\"`)\n"
           "     *          /`,@ ;+& () o*`;-';\\\n"
           "               (`\"\"--.,_0 +% @' &()\\\n"
           "               /-.,_    ``''--....-'`)  *\n"
           "          *    /@%;o`:;'--,.__   __.'\\\n"
           "              ;*,&(); @ % &^;~`\"`o;@();         *\n"
           "              /(); o^~; & ().o@*&`;&%O\\\n"
           "        jgs   `\"=\"==\"==,,,.,=\"==\"===\"`\n"
           "           __.----.(\\-''#####---...___...-----._\n"
           "         '`         \\)_`\"\"\"\"\"`\n"
           "                 .--' ')\n"
           "               o(  )_-\\\n"
           "                 `\"\"\"` `\n"
        << std::endl;
    std::cout << "file " << filename << " created in current directory" << std::endl;
    ofs.close();
    return;
}
