/*Write a program that provides a menu for the
user with two options: code, decode. The coding
and decoding should be performed based on the Caesar Cipher
The program should read a normal text from a
text file, code it with the Caesar Cipher 
algorithm and save it in another text file.
The program can also read already coded text 
from a text file, decode it and save it in another text file.*/
#include <iostream>

extern void prepare_for_coding();//defined in Caesar_Cipher_code.cpp
extern void prepare_for_decoding();//defined in Caesar_Cipher_decode.cpp

void program_start()
{
	std::string key;//what does the user want to do?
	std::cout << "If you want to code the text, enter '1'\n"
			  << "If you want to decode the text, enter '2'\n";

	do{
		std::cin >> key;
		if(key != "1" && key != "2"){
			std::cout << "Your input value is not valid, please, enter '1' for coding or '2' for decoding the text.\n";
		}
	}while(key != "1" && key != "2");

	if ("1" == key){
		prepare_for_coding();		
	}
	else if ("2" == key){
		prepare_for_decoding();			
	}
}

int main(){	
	std::cout << "Welcome to the world of codes!\n";
	program_start();		
	return 0;
}