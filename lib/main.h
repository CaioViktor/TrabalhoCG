#define PROJECTION_OPENGL 0
#define PROJECTION_PESPECTIVE 1
#define PROJECTION_ORTOGONAL 2
#define PROJECTION_PESPECTIVE_LOOK 3
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/glui.h>
#include <sstream> 
#include <iostream>
#include <cmath>
#include <string>
#include "matrix.h"
#include "vector.h"
#include "vertex.h"
#include "listVertex.h"
#include "face.h"
#include "listFace.h"
#include "objectClass.h"
#include "topology.h"
#include "stackMatrix.h"
#include "leitor.h"
#include "view.h"
#include "applyToAll.h"
#include "material.h"
using namespace std;
void selectObject();
void initGLUISave();
void clearOpenGL();
void setFrustum();