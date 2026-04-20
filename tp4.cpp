#include <iostream>
#include <cmath>
using namespace std;

class vecteur3d {

    float x,y,z;

public:
    // Constructeur 
    vecteur3d(float c1=0.0, float c2=0.0, float c3=0.0) {
        x = c1;  y = c2;  z = c3;
    }

//   1-a) surcharge de == et != (fonctions MEMBRE)
    // Return true si les deux vecteurs sont =
    bool operator==(const vecteur3d& v) const {
        return (x == v.x) && (y == v.y) && (z == v.z);
    }

    // Return true si les deux vecteurs sont !=
    bool operator!=(const vecteur3d& v) const {
        return !(*this == v);   // réutilise operator==
    }

//    1-b) : egal() et different() (fonctions AMIES)

    friend bool egal(const vecteur3d& v1, const vecteur3d& v2);
    friend bool different(const vecteur3d& v1, const vecteur3d& v2);

//     2)opérateurs + (somme) et * (produit vectoriel)
//     Fonctions MEMBRE

    // Somme : (x1+x2,y1+y2,z1+z2)
    vecteur3d operator+(const vecteur3d& v) const {
        return vecteur3d(x + v.x,  y + v.y,  z + v.z);
    }

    // Produit vectoriel : v1×v2=(y1z2-z1y2,z1x2-x1z2,x1y2-y1x2)
    vecteur3d operator*(const vecteur3d& v) const {
        return vecteur3d(
            y*v.z - z*v.y,   // composante x
            z*v.x - x*v.z,   // composante y
            x*v.y - y*v.x    // composante z
        );
    }

//    3) methode affiche()

    void affiche() const {
        cout << "(" << x << ", " << y << ", " << z << ")";
    }

//    4) 

    friend float norme(vecteur3d v);

};  


//fcts amies

bool egal(const vecteur3d& v1, const vecteur3d& v2) {
    return (v1.x == v2.x) && (v1.y == v2.y) && (v1.z == v2.z);
}

bool different(const vecteur3d& v1, const vecteur3d& v2) {
    return !egal(v1, v2);   
}

float norme(vecteur3d v) {
    return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}

