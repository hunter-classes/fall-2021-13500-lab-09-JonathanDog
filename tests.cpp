#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
#include "coord3d.h"
#include "cmath"

// Only compared a certian amount of decimal spaces as the entire thing was not working
TEST_CASE("Testing Task A Length") {
	Coord3D pointP = {10, 20, 30};
	double answer = int(length(&pointP) * 10000) / double(10000);
	CHECK(answer == double(37.41655));

	Coord3D pointX = {5, 8, 10};
	answer = int(length(&pointX) * 10000) / double(10000);
	CHECK(answer == double(13.7477));

}

TEST_CASE("Testing Task B fartherFromOrigin") {
	Coord3D pointP = {10,20,30};
	Coord3D pointQ = {-20, 21, -22};
	Coord3D * ans = fartherFromOrigin(&pointP, &pointQ);
	CHECK(ans == &pointP);

	Coord3D pointA = {5, 10 ,30};
	Coord3D pointB = {-5, -100, -20};
	ans = fartherFromOrigin(&pointA, &pointB);
	CHECK(ans == &pointB);
}

TEST_CASE("Testing Task C move") {
	Coord3D posA = {0, 0, 100.0};
	Coord3D velA = {1, -5, 0.2};
	move(&posA, &velA, 2.0);
	CHECK(posA.x == 2);
	CHECK(posA.y == -10);
	CHECK(posA.z == 100.4);

	Coord3D posB = {5, 8, 50};
	Coord3D velB = {-2, 10, .8};
	move(&posB, &velB, 1.5);
	CHECK(posB.x == 2);
	CHECK(posB.y == 23);
	CHECK(posB.z == 51.2);
}


