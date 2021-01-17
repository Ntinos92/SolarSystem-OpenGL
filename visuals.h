struct normal
{
	float x;
	float y;
	float z;
};

struct point
{
	float x;
	float y;
	float z;
};

struct face
{
	int vtx[3][2];
};

struct model
{
	point obj_points[9200];
	face obj_faces[19000];
	normal obj_normal[9200];
	int vertices;
	int faces;
	int normals;
};


//-------- Functions --------------------------------

void Render();
// The function responsible for drawing everything in the 
// OpenGL context associated to a window. 

void Resize(int w, int h);
// Handle the window size changes and define the world coordinate 
// system and projection type

void Setup();
// Set up the OpenGL state machine and create a light source

void Idle();

void ReadFile(model*);
//Function for reading a model file

void DisplayModel(model);
// Function for displaying a model


void Keyboard(unsigned char key, int x, int y);
// Function for keyboard commands
