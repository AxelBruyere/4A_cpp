#pragma once

#ifndef GRILLE_HPP
#define GRILLE_HPP

#include <iostream>
#include <vector>


template <typename T>
struct grille
{
    /** \brief La taille suivant x de la grille **/
    int Nx;
    /** \brief La taille suivant y de la grille **/
    int Ny;

    /** \brief Les donnees de la grille **/
    std::vector<T> data;

    /** Certifie que (x,y) soit bien contenu dans l'image
     *  \return rien, mais quitte si les coordonnee sont hors de la grille
     **/
    void assert_coord(int x,int y) const
    {
        if(x<0 || x>=Nx || y<0 || y>=Ny)
        {
            std::cerr<<"Index "<<x<<","<<y<<" hors bornes."<<std::endl;
            exit(1);
        }
    }

    /** \brief Operateur "get" pour des coordonnees (x,y) **/
    T const& operator()(int x,int y) const
    {
        assert_coord(x,y);
        return data[y+Ny*x];
    }

    /** \brief Operateur "get/set" pour des coordonnees (x,y) **/
    T& operator()(int x,int y)
    {
        assert_coord(x,y);
        return data[y+Ny*x];
    }

    /** \brief Redimentionne la grille a une nouvelle taille
      * Les parametres (Nx,Ny) sont remis a jour, et le vecteur
      * de donnees est redimensionne (mais il n'efface pas les donnees
      * precedente).
      **/
    void resize(int Nx_arg,int Ny_arg)
    {
        Nx=Nx_arg;
        Ny=Ny_arg;
        data.resize(Nx_arg*Ny_arg);
    }
    
};


#endif