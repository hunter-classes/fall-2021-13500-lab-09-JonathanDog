#include <iostream>
#include <cmath>
#include "funcs.h"
#include "coord3d.h"
#include "particle.h"
// add functions here

double length(Coord3D *p) {
	Coord3D a = *p;
	return sqrt(pow(a.x,2) + pow(a.y,2) + pow(a.z,2));	
}

Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2) {
	//Coord3D pointA = *p1;
	//Coord3D pointB = *p2;

	double lengthA = length(p1);
	double lengthB = length(p2);
	
	if(lengthA > lengthB) {
		return p1;
	} else {
		return p2;
	}

}

void move(Coord3D *ppos, Coord3D *pvel, double dt) {
	ppos->x = ppos->x + pvel->x * dt;
	ppos->y = ppos->y + pvel->y * dt;
	ppos->z = ppos->z + pvel->z * dt;
}

Coord3D* createCoord3D(double x, double y, double z) {
	Coord3D* created = new Coord3D;
	created->x = x;
	created->y = y;
	created->z = z;
	return created;
}

void deleteCoord3D(Coord3D *p) {
	delete p;
}

Particle* createParticle(double x, double y, double z, double vx, double vy, double vz) {
	Particle* created = new Particle;
	created->x = x;
	created->y = y;
	created->z = z;
	created->vx = vx;
	created->vy = vy;
	created->vz = vz;

	return created;
}

void setVelocity(Particle *p, double vx, double vy, double vz) {
	p->vx = vx;
	p->vy = vy;
	p->vz = vz;
}

Coord3D getPosition(Particle *p) {
	Coord3D a ={p->x, p->y, p->z};
	return a; 
}

void move(Particle *p, double dt) {
	p->x = p->x + p->vx * dt;
	p->y = p->y + p->vy * dt;
	p->z = p->z + p->vz * dt;
}

void deleteParticle(Particle *p) {
	delete p;

}
