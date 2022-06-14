#include <fstream>
#include <iostream>

void program_start();//defined in Caesar_Cipher.cpp
extern std::ifstream finput;//defined in Caesar_Cipher_code.cpp
extern std::ofstream foutput;//defined in Caesar_Cipher_code.cpp
extern std::string code_path;//defined in Caesar_Cipher_code.cpp
extern std::string coded_text;//defined in Caesar_Cipher_code.cpp
std::string decoded_text;//will contain the decoded text
std::string new_path;//the path of file decoded text

std::string to_decode(std::string coded_text, int shift)
{
	for (int i{}; i < coded_text.length(); ++i){
		if (coded_text[i] >= '0' && coded_text[i] <= '9' - shift || coded_text[i] >= 'A' && coded_text[i] <= 'Z' - shift || coded_text[i] >= 'a' && coded_text[i] <= 'z' - shift){
			coded_text[i] += shift;
		}
		else if (coded_text[i] > '9' - shift  && coded_text[i] <= '9'){
			coded_text[i] -= ('9' - '0' - shift + 1) ;
		}
		else if (coded_text[i] > 'Z' - shift && coded_text[i] <= 'Z' || coded_text[i] > 'z' - shift && coded_text[i] <= 'z'){
			coded_text[i] -= ('Z' - 'A' - shift + 1);
		}
	}
	return coded_text;
}

void prepare_for_decoding()
{
	std::cout << "Please, enter the path of file to read coded text.\n";		
	do{
		std::cin >> code_path;//the path of file coded text
		if ("exit" == code_path){
			std::cout << "you quit the program";
			exit(0);
		}
		finput.open(code_path);
		if (!finput.is_open()){
           	std::cout << "the file " << code_path << " is not opened, please, try again, or input 'exit' to exit the program\n" << std::endl;
        }
	}while(!finput.is_open());	

	std::cout << "The file " << code_path << " is opened!\n";
    std::cout << "Please, input the shift value.\n";
    int shift_value{};
    std::cin >> shift_value;
	while(!finput.eof()){
		std::getline(finput, coded_text);
		decoded_text += to_decode(coded_text, shift_value);
	}
    finput.close();//close the opened file
	std::cout << "Per text is decoded successfully!" << std::endl;
	std::cout << "Now enter the path of file to write decoded text.\n";
    do{
		std::cin >> new_path;
		if ("exit" == new_path){
			std::cout << "you quit the program";
			exit(0);
		}
		foutput.open(new_path);
		if (!foutput.is_open()){
			std::cout << "the file " << new_path << " is not opened try again or insert 'exit' to exit the program.\n" << std::endl;
		}
	}while(!foutput.is_open());	

	std::cout << "The file " << new_path << " is opened!\n";
	foutput << decoded_text;
	std::cout << "The decoded text has been successfully entered in " << new_path << std::endl;
	foutput.close();//close the opened file

	std::cout << "is there another file you want to encrypt or decrypt? yes/no\n";
	std::string answer;
	do{
		std::cin >> answer;
		if (answer != "yes" && answer != "no"){
			std::cout << "your input is not valid, please, enter yes or no.\n";
		}
	}while (answer != "yes" && answer != "no");
	if ("no" == answer){
		std::cout << "you quit the program";
		exit(0);
	}
	else {
		program_start();//start again
	}    
}