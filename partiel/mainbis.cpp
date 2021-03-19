
#include <iostream>
#include <string>

template <unsigned N>

struct Vec
{
    public :
    int tab[N];
    
    /*
    Vec<N> operator+(const Vec<N>& v) const
    {
    }*/

    static std::string to_string(const Vec<N>& v)
    {
        std::string str;
        str += '[';
        for (unsigned i=0; i<N; i++)
        {
            str += std::to_string(v.tab[i]) + ' ';
        }
        str += ']';
        return str;
    }
};

template<unsigned N>
Vec<N> operator+(const Vec<N>& v1, const Vec<N>& v2)
{
    for (unsigned i=0; i<N; i++)
    {
        v.tab[i] = v1.tab[i] + v2.tab[i];
    }
    return v;
}

int main(){

    
    
    return 0;
}