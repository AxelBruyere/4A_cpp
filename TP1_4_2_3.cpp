#include <iostream>
#include <string>
#include <vector>


std::vector<std::string> mon_vecteur = {"Bonjour","comment","allez","vous","?"};

int main(){
	
	std::cout<<mon_vecteur.size()<<std::endl;
	std::cout<<mon_vecteur.capacity()<<std::endl;

	std::cout<<"1) ";
	for (int k = 0;k<mon_vecteur.size();k++)
		std::cout<<mon_vecteur[k]<<" ";
	std::cout<<std::endl;

	std::cout<<"2) ";
	for (auto it_begin = mon_vecteur.begin(),it_end = mon_vecteur.end();it_begin<it_end;it_begin++)
		std::cout<<*it_begin<<" ";
	std::cout<<std::endl;

	std::cout<<"3) ";
	for (auto mot : mon_vecteur)
		std::cout<<mot<<" ";
	std::cout<<std::endl;



	return 0;
}
