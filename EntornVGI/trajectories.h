//******** PRACTICA VISUALITZACI� GR�FICA INTERACTIVA (Escola Enginyeria - UAB)
//******** Entorn b�sic VS2022 MULTIFINESTRA amb OpenGL 4.6, interf�cie MFC/GLFW i llibreries GLM
//******** Carme Juli�, D�bora Gil, Enric Mart� G�dia (Novembre 2025)
// trajectories.h : Definici� de les trajectories per corbes Spline o Catmull-Rom i Matriu canvi de base.

#ifndef TRAJECT_H
#define TRAJECT_H

//------------ DEFINICI� DE CONSTANTS

// --------------- VGI. Nombre de frames de l'animaci� per a l'escena Paisatge
#define NFRAMES 25		// Numero de frames en Paisatge B-Spline o Catmull_Rom


const int H_TRAJ = -50;
const int S_TRAJ = 2;
const double hV = 10.0;


// Numero Pts control
const int npts = 9;

// Vector dels punts de control Tie (Traject�ria m�s suau, amb baixa torsi�) - Origen davant cabina
const CPunt3D PtsH[] = { {256.0 + 16.0,256.0,41.0,1.0},{-256.0,256.0,1.0,1.0},{-256.0f,0.0f,41.0f,1.0},{-160.0,-70.0,86.0,1.0},
{-16.0,-100.0f,191.0,1.0},{256.0 - 32.0,64.0 - 32.0,86.0,1.0},{256.0 + 16.0,256.0,41.0,1.0},{-256.0,256.0,1.0,1.0},
{-256.0,0.0,41.0,1.0} };

// Vector dels punts de control Tie (Traject�ria menys suau, amb alta torsi�) - Origen davant cabina
const CPunt3D PtsH2[] = { {256.0 + 16.0,256.0,41.0,1.0},{-256.0,256.0,1.0,1.0},{-256.0f,0.0f,41.0f,1.0},{-128.0 - 16.0,0.0,86.0,1.0},
{-16.0,64.0 + 32.0 + 32.0f,161.0,1.0},{256.0 - 32.0,64.0 - 32.0,86.0,1.0},{256.0 + 16.0,256.0,41.0,1.0},{-256.0,256.0,1.0,1.0},
{-256.0,0.0,41.0,1.0} };

// Vector dels punts de control Tie (trajectoria escalada)
// Vector dels punts de control Tie (trajectoria escalada)
// Vector dels punts de control Tie (trajectoria escalada)
// Vector dels punts de control Tie (trajectoria escalada)
const CPunt3D PtsH3[] = {
    { S_TRAJ * (256.0 + 16.0),  S_TRAJ * 256.0,                S_TRAJ * (30.0 + H_TRAJ),   1.0 },
    { -256.0 * S_TRAJ,          256.0 * S_TRAJ,                S_TRAJ * (-10.0 + H_TRAJ),  1.0 },
    { -256.0 * S_TRAJ,          0.0,                           S_TRAJ * (30.0 + H_TRAJ),   1.0 },
    { S_TRAJ * (-128.0 - 16.0), 0.0,                           S_TRAJ * (75.0 + H_TRAJ),   1.0 },
    { -16.0 * S_TRAJ,           S_TRAJ * (64.0 + 32.0 + 32.0), S_TRAJ * (150.0 + H_TRAJ),  1.0 },
    { S_TRAJ * (256.0 - 32.0),  S_TRAJ * (64.0 - 32.0),        S_TRAJ * (75.0 + H_TRAJ),   1.0 },
    { S_TRAJ * (256.0 + 16.0),  S_TRAJ * 256.0,                S_TRAJ * (30.0 + H_TRAJ),   1.0 },
    { -256.0 * S_TRAJ,          256.0 * S_TRAJ,                S_TRAJ * (-10.0 + H_TRAJ),  1.0 },
    { -256.0 * S_TRAJ,          0.0,                           S_TRAJ * (30.0 + H_TRAJ),   1.0 }
};



//------------ FI DEFINICI� DE CONSTANTS

//------------------------------- MATRIUS CANVIS DE BASE PER ALINEAR EIXOS OBJECTE AMB EIXOS TRIEDRE FRENET ------------
void Base_Matrix(CPunt3D VT, CPunt3D VNP, CPunt3D VBN, GLfloat* pMatrix);
CPunt3D p3DxMatrix(CPunt3D p, GLfloat pMatrix[16]);
//------------------------------- FI MATRIUS CANVIS DE BASE PER ALINEAR EIXOS OBJECTE AMB EIXOS TRIEDRE FRENET ----------


#endif