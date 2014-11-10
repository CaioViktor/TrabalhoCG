#include "../lib/main.h"

View::View(int mode){
	modeProjection = mode;
	frameCamera = Matrix::getIdentity();
	view = Matrix::getIdentity();
	projection = Matrix::getIdentity();
	volumeVisualization = Matrix::getIdentity();

	left   = 0;
	right  = 0;
	bottom = 0;
	top    = 0;
	near   = 0;
	far    = 0;

}

void View::setModeProjection(int mode){
	if(modeProjection != mode){
		modeProjection = mode;
		Matrix *matrixProjection = new Matrix();
		if(modeProjection == PROJECTION_PESPECTIVE){

			matrixProjection->setPosition(0,0, (2*near)/(right - left));
			matrixProjection->setPosition(0,2, (right + left)/(right - left));
			matrixProjection->setPosition(1,1, (2*near)/(top - bottom));
			matrixProjection->setPosition(1,2, (top + bottom)/(top - bottom));
			matrixProjection->setPosition(2,2, -(far + near)/(far - near));
			matrixProjection->setPosition(2,3, -(2*far * near)/(far - near));
			matrixProjection->setPosition(3,2, -1);
		}
		if(modeProjection == PROJECTION_ORTOGONAL){
			matrixProjection->setPosition(0,0, 2/(right - left));
			matrixProjection->setPosition(0,3, -(right + left)/(right - left));
			matrixProjection->setPosition(1,1, 2/(top - bottom));
			matrixProjection->setPosition(1,3, -(top + bottom)/(top - bottom));
			matrixProjection->setPosition(2,2, -2/(far-near));
			matrixProjection->setPosition(2,3, -(far+near)/(far-near));
			matrixProjection->setPosition(3,3, 1);
		}
		projection = matrixProjection;
	}
}

int View::getModeProjection(){
	return modeProjection;
}

Matrix View::getFrameMatrix(){
	return (*frameCamera);
}

Matrix* View::getModelViewMatrix(){
	return view;
}
Matrix* View::getProjectionMatrix(){
	return projection;
}

void View::setVolumeVisualization(double left, double right, double bottom, double top, double near, double far){

	this->left   = left;
	this->right  = right;
	this->bottom = bottom;
	this->top    = top;
	this->near   = near;
	this->far    = far;

	Matrix *matrixProjection = new Matrix();
	if(modeProjection == PROJECTION_PESPECTIVE){

		matrixProjection->setPosition(0,0, (2*near)/(right - left));
		matrixProjection->setPosition(0,2, (right + left)/(right - left));
		matrixProjection->setPosition(1,1, (2*near)/(top - bottom));
		matrixProjection->setPosition(1,2, (top + bottom)/(top - bottom));
		matrixProjection->setPosition(2,2, -(far + near)/(far - near));
		matrixProjection->setPosition(2,3, -(2*far * near)/(far - near));
		matrixProjection->setPosition(3,2, -1);
	}
	if(modeProjection == PROJECTION_ORTOGONAL){
		matrixProjection->setPosition(0,0, 2/(right - left));
		matrixProjection->setPosition(0,3, -(right + left)/(right - left));
		matrixProjection->setPosition(1,1, 2/(top - bottom));
		matrixProjection->setPosition(1,3, -(top + bottom)/(top - bottom));
		matrixProjection->setPosition(2,2, -2/(far-near));
		matrixProjection->setPosition(2,3, -(far+near)/(far-near));
		matrixProjection->setPosition(3,3, 1);
	}

	// cout << "Calculou pespective\n";
	projection = matrixProjection;
	// projection->printMatrix();
}


void View::setCameraPosition(double x, double y, double z, double rotationX, double rotationY, double rotationZ){
	Matrix matrix;
	stackMatrix stack;

	stack.push(Matrix::getTranslation( x, y, z));
	stack.push(Matrix::getRotationX(rotationX));
	stack.push(Matrix::getRotationY(rotationY));
	stack.push(Matrix::getRotationZ(rotationZ));
	matrix = (*stackMatrix::concatenate(&stack));

	(*frameCamera) = matrix;
	(*view) = (*matrix.getInverse());
}
