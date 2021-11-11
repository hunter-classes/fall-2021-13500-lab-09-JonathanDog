#include <iostream>
#include "particle.h"
#include "coord3d.h"
#include "funcs.h"

int main()
{
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
