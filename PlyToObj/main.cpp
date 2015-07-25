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

/*---------------------GLOBAL-------------------------*/

int vert_count;
clock_t start_t , end_t;

int main()
{
	start_t = clock();

	string file_path("resources/test.ply");
	ifstream fin;
	fin.open(file_path.c_str());
	
	if(!fin)
	{
		cout << "Cannot Open File" << file_path << "!!\n";
		system("PAUSE");
		return -1;
	}

	string data_buf;
	string head;
	
	while( fin >> head)
	{
		if( head.compare("end_header") == 0)
		{
			break;
		}
		else
		{
			getline(fin, data_buf);
		}
	}
	getline(fin , data_buf);
	Obj myobj;
	vert_count = 0;
	while( getline(fin , data_buf) )
	{
		float x , y , z , nx , ny , nz;
		int r , g , b;
		istringstream sin( data_buf.c_str() );

		sin >> x >> y >> z >> nx >> ny >> nz >> r >> g >> b;
		Vert_pos temp_pos;
		temp_pos.x = x;  temp_pos.y = y;  temp_pos.z = z; 
		myobj.positions.push_back(temp_pos);

		Vert_normal temp_normal;
		temp_normal.x = nx;  temp_normal.y = ny;  temp_normal.z = nz; 
		myobj.normals.push_back(temp_normal);

		Vert_color temp_color;
		temp_color.r = r;  temp_color.g = g;  temp_color.b = b; 
		myobj.colors.push_back(temp_color);
		
		vert_count++;
	}

	Vert_pos* pos_data = myobj.positions.data();
	Vert_normal* normal_data = myobj.normals.data();
	
	ofstream fout;
	fout.open("resources/output.obj");
	for(int i=0;i<vert_count;i++)
	{
		Vert_pos* data = pos_data+i;
		fout << "v " << data->x << " " << data->y << " " << data->z <<endl;
	}
	for(int i=0;i<vert_count;i++)
	{
		Vert_normal* data = normal_data+i;
		fout << "vn " << data->x << " " << data->y << " " << data->z <<endl;
	}
	end_t = clock();

	cout << "Elapsed time = " << end_t - start_t << endl;

	system("PAUSE");
	return 0;
}
