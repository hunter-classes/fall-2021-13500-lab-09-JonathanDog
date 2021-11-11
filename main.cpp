#include <iostream>
#include "particle.h"
#include "coord3d.h"
#include "funcs.h"

int main()
{
	std::cout << std::endl;
	std::cout << "Task A" << std::endl;
	std::cout << "----------------------------------" << std::endl;

	Coord3D pointP = {10, 20, 30};
   	std::cout << "Length for Point(10,20,30)" << std::endl;
	std::cout << length(&pointP) << std::endl; // would print 37.4166
	
	std::cout << std::endl;
	std::cout << "Task B" << std::endl;
	std::cout << "-----------------------------------" << std::endl;

	Coord3D pointA = {10, 20, 30};
    Coord3D pointB = {-20, 21, -22};
	std::cout << "PointA = {10,20,30} & pointB = {-20, 21, -22)" << std::endl;
    std::cout << "Address of pointA: " << &pointA << std::endl;
    std::cout << "Address of pointB: " << &pointB << std::endl << std::endl;

    Coord3D * ans = fartherFromOrigin(&pointA, &pointB);
   
   	std::cout << "farthestFromOrigin ans = " << ans << std::endl;
	
	std::cout << std::endl;
    std::cout << "Task C" << std::endl;
    std::cout << "-----------------------------------" << std::endl;

	Coord3D pos = {0, 0, 100.0};
    Coord3D vel = {1, -5, 0.2};
	
    std::cout << "pos = 0, 0, 100.0 & vel = 1, -5, 0.2" << std::endl;;
	std::cout <<  "After 2 seconds = " << std::endl;
	move(&pos, &vel, 2.0); // object pos gets changed
    std::cout << pos.x << " " << pos.y << " " << pos.z << std::endl;
    // prints: 2 -10 100.4
	

	std::cout << std::endl;
    std::cout << "Task E" << std::endl;
    std::cout << "-----------------------------------" << std::endl;

	double x, y, z;
    std::cout << "Position: 5, 10, 15 " << std::endl;
    Coord3D *ppos = createCoord3D(5,10,15);
    
    std::cout << "Velocity: 2, -2, 5" << std::endl;
    Coord3D *pvel = createCoord3D(2,-2,5);

    move(ppos, pvel, 10.0);

    std::cout << "Coordinates after 10 seconds: " 
         << (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << std::endl;

    deleteCoord3D(ppos); // release memory
    deleteCoord3D(pvel);



	

	std::cout << std::endl;	
	std::cout << "Task F" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	
		
	std::cout << "Particle q = (1.0, 1.5, 2.0, 0.1, 0.2, 0.3)" << std::endl;
	std::cout << "Time = 0.0 & dt = 0.1" << std::endl;


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
