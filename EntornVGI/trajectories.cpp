//******** PRACTICA VISUALITZACI� GR�FICA INTERACTIVA (Escola Enginyeria - UAB)
//******** Entorn b�sic VS2022 MULTIFINESTRA amb OpenGL 4.6, interf�cie MFC i llibreries GLM
//******** Carme Juli�, D�bora Gil, Enric Mart� G�dia (Novembre 2025)
// trajectories.h : Definici� de les trajectories per corbes Spline o Catmull-Rom i Matriu canvi de base.

#include "stdafx.h"
#include "constants.h"
//#include "fractals.h"
#include "trajectories.h"

#include <math.h>

// Base_Matrix: Matriu de canvi de base del Tie seguint la correspondencia entre els eixos del Tie i el Triedre de Frenet:
//					- (0,1,0): VT
//					- (0,0,1): VBN 
//					- (1,0,0): VNP 
//
//     �	VNP.x	VT.x	VBN.x	0	 �
//     �								 �
// M = �	VNP.y	VT.y	VBN.y	0	 �
//     �                           		 �
//     �	VNP.z	VT.z	VBN.z	0	 �
//     �								 �
//     �     0		  0		  0		1	 �
// 
// This is of course a 4x4 matrix.  Notice that a rotational matrix can just
//	be a 3x3 matrix, but since OpenGL uses a 4x4 matrix, we need to conform to the man.
//	Remember that the identity matrix of a 4x4 matrix has a diagonal of 1's, where
//	the rest of the indices are 0.  That is where we get the 0's lining the sides, and
//	the 1 at the bottom-right corner.  Since OpenGL matrices are row by column, we fill
//	in our matrix accordingly below.
void Base_Matrix(CPunt3D VT, CPunt3D VNP, CPunt3D VBN, GLfloat* pMatrix)
{
	//GLfloat pMatrix[16];

// Make sure the matrix has allocated memory to store the rotation data
	if (!pMatrix) return;

	// First row
	pMatrix[0] = VNP.x;
	pMatrix[1] = VNP.y;
	pMatrix[2] = VNP.z;
	pMatrix[3] = 0.0f;

	// Second row
	pMatrix[4] = VT.x;
	pMatrix[5] = VT.y;
	pMatrix[6] = VT.z;
	pMatrix[7] = 0.0f;

	// Third row
	pMatrix[8] = VBN.x;
	pMatrix[9] = VBN.y;
	pMatrix[10] = VBN.z;
	pMatrix[11] = 0.0f;

	// Fourth row
	pMatrix[12] = 0.0f;
	pMatrix[13] = 0.0f;
	pMatrix[14] = 0.0f;
	pMatrix[15] = 1.0f;

	// Now pMatrix[] is a 4x4 homogeneous matrix that can be applied to an OpenGL Matrix
		//return pMatrix;
}


// p3DxMatrix : Multiplicaci� del punt p per la matriu pMatrix per la dreta p' = pMatrix * p.
CPunt3D p3DxMatrix(CPunt3D p, GLfloat pMatrix[16])
{
	CPunt3D auxRes;

	// Coordenada X punt transformat
	auxRes.x = pMatrix[0] * p.x + pMatrix[4] * p.y + pMatrix[8] * p.z + pMatrix[12] * p.w;

	// Coordenada Y punt transformat
	auxRes.y = pMatrix[1] * p.x + pMatrix[5] * p.y + pMatrix[9] * p.z + pMatrix[13] * p.w;

	// Coordenada Z punt transformat
	auxRes.z = pMatrix[2] * p.x + pMatrix[6] * p.y + pMatrix[10] * p.z + pMatrix[14] * p.w;

	// Coordenada W punt transformat
	auxRes.w = pMatrix[3] * p.x + pMatrix[7] * p.y + pMatrix[11] * p.z + pMatrix[15] * p.w;

	return auxRes;
}
