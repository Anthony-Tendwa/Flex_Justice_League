#include <iostream>
#include <string>
#include <regex>

bool isComment(const std::string& line){
    //regular expression pattern to match the single-line and multi-line
    std::regex commentPat(R"(^\s*//|^\s*/\*|^\s*\*/|^\s*\*)");
    
    //check if the line matches the commeny pat
    return std::regex_search(line, commentPat);

}

int main(){
    std::string codeLines[] = {
        "int main () {",  //not a comment
        " // This is a comment", // comment
        " std::cout <<'Good morning' <<std::endl;", // not a comment
        " /*", //comment
        " */", // end of a comment

    };
   for (const std::string& line : codeLines){
       if (isComment(line)){
           std::cout << "'" << line << "' is a comment." <<std::endl;
       }
       else {
          std::cout << "'" << line << "' is not a comment." << std::endl;


       }
   }
   return 0;
  }
   
//Describe the logic used?
//The function 'isComment' takes the string 'line' as input and uses a regular expression pattern to match the comments.
//The regular expression pattern used matches single-line comments and starts of multi-line comments and ends with multi-line comments.
//The main function created is used to call the line 'isComment' function to determine if its a comment or not then prints the result.
//Was lexical analysis or syntax analysis important in your logic? if yes, how?
//The function isComment is a lexical analysis functiom used to check if a line starts with a comment character.
//Syntax analysis is also present by the use of /* and */ characters of multi-line comments to checj if the program grammar structure is correct.
