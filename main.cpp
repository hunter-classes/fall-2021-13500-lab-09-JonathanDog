#include <iostream>
#include "particle.h"
#include "coord3d.h"
#include "funcs.h"

int main()
{
  	Coord3D pointA = {10,20,30};
	std::cout << length(&pointA) << std::endl;
	
	Coord3D pointP = {10, 20, 30};
    Coord3D pointQ = {-20, 21, -22};

    std::cout << "Address of P: " << &pointP << std::endl;
    std::cout << "Address of Q: " << &pointQ << std::endl << std::endl;

    Coord3D * ans = fartherFromOrigin(&pointP, &pointQ);
   
    std::cout << "ans = " << ans << std::endl; // So which point is farther?
	
	    
	Coord3D pos = {0, 0, 100.0};
    Coord3D vel = {1, -5, 0.2};

    move(&pos, &vel, 2.0);
	std::cout << pos.x << " " << pos.y << " " << pos.z << std::endl;

	double x, y, z;
	std::cout << "Enter position: ",
	std::cin >> x >> y >> z;
	Coord3D *ppos = createCoord3D(x,y,z);

	std::cout << "Enter velocity: ";
	std::cin >> x >> y >> z;
	Coord3D *pvel = createCoord3D(x,y,z);

	move(ppos, pvel, 10.0);
	
	 std::cout << "Coordinates after 10 seconds: " 
         << (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << std::endl;
	
	deleteCoord3D(ppos); // release memory
    deleteCoord3D(pvel);
	
	std::cout << "-----------------------------------" << std::endl;

	Particle *q= createParticle(1.0, 1.5, 2.0, 0.1, 0.2, 0.3);
    double time = 0.0;
    double dt = 0.1;
    while(time < 3.0) {
        // update its velocity
        setVelocity(q, 10.0 * time, 0.3, 0.1);

        // move the particle
        move(q, dt);
        time += dt;

        // reporting its coordinates
       std::cout << "Time: " << time << " \t";
        std::cout << "Position: "
             << getPosition(q).x << ", "
             << getPosition(q).y << ", "
             << getPosition(q).z << std::endl;
    }
    // remove the particle, deallocating its memory
    deleteParticle(q);
	
	return 0;
}
