class View{
	Matrix *frameCamera;
	Matrix *view;
	Matrix *projection;
	Matrix *volumeVisualization;
	int modeProjection;

	double left, right,  bottom,  top,  near,  far;
public:
	View(int mode);
	void setModeProjection(int mode);
	int getModeProjection();

	Matrix getFrameMatrix();
	Matrix* getModelViewMatrix();

	void setVolumeVisualization(double left, double right, double bottom, double top, double near, double far);
	Matrix* getProjectionMatrix();

	void setCameraPosition(double x, double y, double z, double rotationX, double rotationY, double rotationZ);

	void lookAt(double x, double y, double z,double targetX,double targetY,double targetZ,double upX,double upY,double upZ);
};