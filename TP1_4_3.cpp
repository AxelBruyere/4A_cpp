#include <iostream>
#include <vector>
#include <string>


std::vector <std::string> mon_vecteur = {"oui","non","peut-être"};


void affiche(std::vector<std::string> const vecteur){
	std::cout<<"1) ";
	for (auto valeur : vecteur)
		std::cout<<valeur<<" ";

	std::cout<<std::endl;
}

void concatener(std::vector<std::string> const vecteur){
	std::string vec_concat;
	for (auto valeur : vecteur)
		vec_concat = vec_concat + valeur + " ";
	std::cout<<"2) "<<vec_concat<<std::endl;
}

char* ajout_virgule(std::vector<std::string> vec){
	for (int k=0;k<vec.size()-1;k++){
		vec[k] = vec[k]+",";
		std::cout<<vec[k]<<std::endl;
	}


}


int main(){
	
	affiche(mon_vecteur);
	concatener(mon_vecteur);
        char* mon_vecteur = ajout_virgule(char* mon_vecteur);
	affiche(char* mon_vecteur);	

	return 0;
}
