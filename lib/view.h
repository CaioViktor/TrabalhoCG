class View{
	Matrix *frameCamera;
	Matrix *view;
	Matrix *volumeVisualization;
	Matrix *projection;
	int modeProjection;

	Matrix getMatrixOrtho();
	Matrix getMatrixPespective();

	double left, right,  bottom,  top,  near,  far;
public:
	View(int mode);
	void setModeProjection(int mode);
	int getModeProjection();

	Matrix getFrameMatrix();
	Matrix getModelViewMatrix();

	void setVolumeVisualization(double left, double right, double bottom, double top, double near, double far);
	Matrix getProjectionMatrix();

	void setCameraPosition(double x, double y, double z, double rotationX, double rotationY, double rotationZ);

};