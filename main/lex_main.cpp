#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(){
    //taking input file and error case for file not opening
    std::ifstream file(".//test_files/test1.jky");
    if(!file.is_open()){
        std::cerr << "Could not open the file\n";
        return 1;
    }
    //coverting it all into string 
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();
    // test 1 in demo
    std::cout <<"test 1 raw string:- " << content << "\n";
    return 0;
}
