#include <iostream>
#include <string>
#include <list>


std::list<std::string> liste = {"Oui","Non","Bonjour","Yolo"};

int main(){
	for (std::string& valeur : liste){
		valeur[1] = 'z';
		std::cout<<valeur<<std::endl;
	}
}
