#include <iostream>
#include <string>
#include <list>


struct Conteneur
{
	int a;
	std::string mot;


	void affiche(){
		std::cout<<a<<std::endl;
		std::cout<<mot<<std::endl;
}

};

struct personne
{
	std::string nom;
	std::string prenom;
	personne():nom("Inconnu"),prenom("Inconnu"){}
	personne(std::string nom,std::string  prenom):nom(nom),prenom(prenom){}
	void affiche(){
	std::cout<<"Je m'appelle "<<prenom<< " "<<nom<<std::endl;
	}
};
class etudiant:public personne
{
	public:
	float note;
	etudiant():personne(),note(0.0f){}
	etudiant(std::string nom,std::string prenom):personne(nom,prenom),note(0.0f){}
	etudiant(std::string nom,std::string prenom,float note):personne(nom,prenom),note(note){}
	void affiche(){
		std::cout<<"Je m'appelle "<<prenom<<" "<<nom<<" et j'ai la note de "<<note<<std::endl;
	}
};
	


void denomer(personne p)
{
	std::cout<<p.nom<<" "<<p.prenom<<std::endl;
}


int main(){
	//Conteneur conteneur_1;
	//conteneur_1.a = 6;
	//conteneur_1.mot = "coucou";
	//conteneur_1.affiche();
	
	//Conteneur conteneur_2 = {4,"bonjour"};
	//conteneur_2.affiche();

	//Conteneur tableau[] = { {18,"poisson"},{12,"charcuterie"},{2,"soda"},{0,"eau"} };
	//for (auto valeur : tableau)
	//	valeur.affiche();
	

	personne unknown;
	personne michel_dumas("Dumas","Michel");

	unknown.affiche();
	michel_dumas.affiche();

	etudiant Axel_Bruyere("Bruyere","Axel",20.0f);
	Axel_Bruyere.affiche();


	etudiant A("Franck","Ribery",2);
	etudiant B("Einstein","Albert",18);
	personne C("Huster","Francis");
	std::list<personne> L;
	L.push_back(A);
	L.push_front(B);
	L.push_front(C);
	for(personne p : L)
	denomer(p);	
	
	
	return 0;
}
