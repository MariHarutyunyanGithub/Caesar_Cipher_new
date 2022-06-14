
#include <fstream>
#include <iostream>

void program_start();//defined in Caesar_Cipher_main.cpp

std::string text_path;//the path of file with source text 
std::string code_path;//the path of file coded text
std::ifstream finput;//declares an object of type ifstream
std::ofstream foutput;//declares an object of type ofstream
std::string origin_text;//contains the original text
std::string coded_text;//will contain the coded text

std::string to_code(std::string text, int shift)
{
	for (int i{}; i < text.length(); ++i){
		if (text[i] >= '0' + shift && text[i] <= '9'|| text[i] >= 'A' + shift && text[i] <= 'Z' || text[i] >= 'a' + shift && text[i] <= 'z'){
			text[i] -= shift;
		}
		else if (text[i] >= '0' && text[i] < '0' + shift){
			text[i] += ('9' - '0'- shift + 1);
			
		}
		else if (text[i] >= 'A' && text[i] < 'A' + shift || text[i] >= 'a' && text[i] < 'a' + shift){
			text[i] += ('Z' - 'A' - shift + 1);
		}
	}
	return text;
}

void prepare_for_coding()
{		
	std::cout << "Please, enter the path of file to read the text.\n";		       
	do{
		std::cin >> text_path;
		if ("exit" == text_path){
			std::cout << "you quit the program";
			exit(0);
		}
		finput.open(text_path);
		if (!finput.is_open()){
           	std::cout << "the file " << text_path << " is not opened, please, try again, or input 'exit' to exit the program" << std::endl;
        }
	}while(!finput.is_open());	

	std::cout << "The file " << text_path << " is opened!\n";
    std::cout << "Please, input the shift value.\n";
    int shift_value{};
    std::cin >> shift_value;
	while(!finput.eof()){
		std::getline(finput, origin_text);
		coded_text += to_code(origin_text, shift_value);
	}
    finput.close();//close the opened file
	std::cout << "Per text is encrypted successfully!" << std::endl;
    std::cout << "Now enter the path of file to write coded text.\n";
    do{
		std::cin >> code_path;
		if ("exit" == code_path){
			std::cout << "you quit the program";
			exit(0);
		}
		foutput.open(code_path);
		if (!foutput.is_open()){
			std::cout << "the file " << code_path << " is not opened try again or insert 'exit' to exit the program.\n" << std::endl;
		}
	}while(!foutput.is_open());	

	std::cout << "The file " << code_path << " is opened!\n";
	foutput << coded_text;
	std::cout << "The coded text has been successfully entered in " << code_path << std::endl;
	foutput.close();

	std::cout << "is there another file you want to encrypt or decrypt?   yes/no\n";
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