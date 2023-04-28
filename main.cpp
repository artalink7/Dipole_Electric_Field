#include "VectorField.h"
#include "MaterialPoint.h"

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv) {
    if (argc != 4) {
        cout <<"Usage: "<< argv[0] << " <x> <y> <z>" <<endl;
        exit(-1);
    }
    cout<<" The numbers you just inserted are the point's coordinate onto which is computed a dipole electric field" << endl;

    double x = atof(argv[1]);
    double y = atof(argv[2]);
    double z = atof(argv[3]);
    Position r (x,y,z);
    

    const double e = 1.60217653E-19;
    const double me = 9.1093826E-31;
    const double mp = 1.67262171E-27;
    const double d = 1.E-10;

    //Creation of the particles, super easy with the class implemented
    MaterialPoint electron(me, -e, 0., 0. , -d/2);
    MaterialPoint proton(mp, e, 0., 0., d/2);

    //Computing the dipole field as the the sum of the two fields produced by the particles
    VectorField E = electron.ElectricField(r) + proton.ElectricField(r);
    cout<< " E = (" <<E.GetFx() << " , "<< E.GetFy()<<" , "<< E.GetFz()<< ")"<<endl;
    return 0;
}
