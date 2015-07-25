#ifndef _DEFINE_H_
#define _DEFINE_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <time.h>
using namespace std;

/*
	define obj attributes;
*/

typedef struct Vert_pos
{
	float x , y , z;
}Vert_pos;

typedef struct Vert_normal
{
	float x , y , z;
}Vert_normal;

typedef struct Vert_color
{
	int r , g , b;
}Vert_color;

typedef struct Obj
{
	vector<Vert_pos> positions;
	vector<Vert_normal> normals;
	vector<Vert_color> colors;
}Obj;


#endif