////////////////////////////////////////////
// 程序：3D 爱心
// 作者：我想做三国志
// 编译环境：Visual Studio 2022，EasyX_20220901
// 编写日期：2023-3-23

#include <graphics.h>
#include <math.h>
#include <vector>
const double PI = 3.1415926536; 		// π
const int WIDTH = 640; 					// 屏幕宽度
const int HEIGHT = 480; 				// 屏幕高度
const int GAMEPAD = 60; 				// 游戏手柄，移动多少距离旋转 60
const double ProjectSurfaceDis = 500;	// 投影面距离
using std::vector;

// 三维向量
class Vec3
{
public:
	double xx, yy, zz;
	// 构造函数
	Vec3(double xx = 0, double yy = 0, double zz = 0) : xx(xx), yy(yy), zz(zz) {}
	// 向量相加
	Vec3	operator+(Vec3 num) { return Vec3(this->xx + num.xx, this->yy + num.yy, this->zz + num.zz); }
	// 向量乘法
	Vec3	operator*(double num) { return Vec3(this->xx * num, this->yy * num, this->zz * num); }
	// 向量点乘
	double	operator*(Vec3 num) { return this->xx * num.xx + this->yy * num.yy + this->zz * num.zz; }
	// 向量除法
	Vec3	operator/(double num) { return Vec3(this->xx / num, this->yy / num, this->zz / num); }
	// 向量相减
	Vec3	operator-(Vec3 num) { return Vec3(this->xx - num.xx, this->yy - num.yy, this->zz - num.zz); }
	// 得到此向量模长
	double	GetLength() { return sqrt(this->xx * this->xx + this->yy * this->yy + this->zz * this->zz); }
	// 得到两向量之间的 cos 值
	double	GetCosBetween(Vec3 num) { return (*this) * num / this->GetLength() / num.GetLength(); }
	// 得到此向量的单位向量
	Vec3	GetUnitVector() { return (*this) / this->GetLength(); }
	// 得到此向量在另一个向量上的投影
	Vec3	GetProjectionTo(Vec3 num) { return num.GetUnitVector() * (this->GetCosBetween(num) * this->GetLength()); }
	// 向量叉乘
	Vec3	MultiplicationCross(Vec3 num) { return Vec3(this->yy * num.zz - this->zz * num.yy, -this->xx * num.zz + this->zz * num.xx, this->xx * num.yy - this->yy * num.xx); }
	// 求将此向量关于 X 轴，Y 轴，Z 轴旋转 a、b、c 度后的向量
	Vec3	GetRotateVec(double a, double b, double c)
	{
		Vec3 result = this->GetUnitVector();
		result = Vec3(result.xx, result.yy * cos(a) - result.zz * sin(a), result.zz * cos(a) + result.yy * sin(a)).GetUnitVector();
		result = Vec3(result.xx * cos(b) - result.zz * sin(b), result.yy, result.zz * cos(b) + result.xx * sin(b)).GetUnitVector();
		result = Vec3(result.xx * cos(c) - result.yy * sin(c), result.yy * cos(c) + result.xx * sin(c), result.zz).GetUnitVector();
		return (result * this->GetLength());
	}
};

// 二维向量
class Vec2
{
public:
	double xx, yy;
	// 构造函数
	Vec2(double xx = 0, double yy = 0) : xx(xx), yy(yy) {}
	// 向量相加
	Vec2	operator+(Vec2 num) { return Vec2(this->xx + num.xx, this->yy + num.yy); }
	// 向量乘法
	Vec2	operator*(double num) { return Vec2(this->xx * num, this->yy * num); }
	// 向量点乘
	double	operator*(Vec2 num) { return this->xx * num.xx + this->yy * num.yy; }
	// 向量除法
	Vec2	operator/(double num) { return Vec2(this->xx / num, this->yy / num); }
	// 向量相减
	Vec2	operator-(Vec2 num) { return Vec2(this->xx - num.xx, this->yy - num.yy); }
	// 得到此向量模长
	double	GetLength() { return sqrt(this->xx * this->xx + this->yy * this->yy); }
	// 得到两向量之间的 cos 值
	double	GetCosBetween(Vec2 num) { return (*this) * num / this->GetLength() / num.GetLength(); }
	// 得到此向量的单位向量
	Vec2	GetUnitVector() { return (*this) / this->GetLength(); }
	// 得到此向量在另一个向量上的投影
	Vec2	GetProjectionTo(Vec2 num) { return num.GetUnitVector() * (this->GetCosBetween(num) * this->GetLength()); }
	// 得到此向量旋转 angle 后的向量
	Vec2	GetRotateVec(double angle) { return Vec2(this->xx * cos(angle) - this->yy * sin(angle), this->yy * cos(angle) + this->xx * sin(angle)); }
};

// 三维三角形
class Triangle
{
public:
	Vec3 a, b, c;
	int H;
	// H 有 360 个值可取
	// L 0~1 根据 cos 值决定
	// 构造函数
	Triangle() = default;
	Triangle(Vec3 a, Vec3 b, Vec3 c, int H = 0) : a(a), b(b), c(c), H(H) {}
};

// 得到三维空间中的点在投影面上的投影
Vec2 GetProjectInSurface(Vec3 project, Vec3 X_Across, Vec3 Y_Across, Vec2 pericenter)	// 这个是平行投影
{
	return pericenter +
		Vec2(project.GetLength() * project.GetCosBetween(X_Across),
			project.GetLength() * project.GetCosBetween(Y_Across));
}

// 交换两个变量
template<typename T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

// 得到三维点的深度
double GetDepth(Vec3 pos, Vec3 ZAcross, double cameraLength)
{
	double ori = pos * ZAcross / ZAcross.GetLength();
	return cameraLength - ori;
}

// 画填充三角形
void DrawTriangle(Triangle triangle, Vec3 X_Across, Vec3 Y_Across, Vec2 pericenter, double extent, double saturate,
	int w, int h, double* AuxiliaryDeepCamera)
{
	if (extent < 0 || extent > 1) return;
	Vec3 ZAcross = X_Across.MultiplicationCross(Y_Across);
	Vec3 arr[3] = { triangle.a, triangle.b, triangle.c };
	Vec2 a = GetProjectInSurface(triangle.a, X_Across, Y_Across, pericenter);
	Vec2 b = GetProjectInSurface(triangle.b, X_Across, Y_Across, pericenter);
	Vec2 c = GetProjectInSurface(triangle.c, X_Across, Y_Across, pericenter);
	// 重心法找深度
	COLORREF col = HSVtoRGB(triangle.H, saturate, max(extent, 0.1));
	if (a.yy > b.yy)
	{
		Swap(a, b);
		Swap(arr[0], arr[1]);
	}
	if (a.yy > c.yy)
	{
		Swap(a, c);
		Swap(arr[0], arr[2]);
	}
	if (b.yy > c.yy)
	{
		Swap(b, c);
		Swap(arr[1], arr[2]);
	}
	Vec3 v1 = arr[1] - arr[0], v2 = arr[2] - arr[0], v3 = arr[2] - arr[1];
	// a~b
	for (int i = (int)a.yy; i < (int)b.yy; i++)
	{
		if (i < 0 || i >= h)continue;
		double t_b = (i - (int)a.yy) / (double)((int)b.yy - (int)a.yy);
		double t_c = (i - (int)a.yy) / (double)((int)c.yy - (int)a.yy);
		double x_b = a.xx + (b.xx - a.xx) * t_b;
		double x_c = a.xx + (c.xx - a.xx) * t_c;
		Vec3 vh = v2 * t_c - v1 * t_b;	// 横向扫描线的三维向量
		Vec3 beg = arr[0] + v1 * t_b;	// 扫描线的起始向量
		if (x_b > x_c)
		{
			Swap(x_b, x_c);
			vh = vh * -1;
			beg = arr[0] + v2 * t_c;
		}
		for (int j = (int)x_b; j < (int)x_c; j++)
		{
			if (j < 0 || j >= w)continue;
			double t_h = (j - x_b) / (double)x_c;
			Vec3 v4 = beg + vh * t_h;
			double judge = GetDepth(v4, ZAcross, ProjectSurfaceDis);
			double pnum = AuxiliaryDeepCamera[i * w + j];
			if (judge < pnum || judge>0 && pnum <= 0.0)
			{
				putpixel(j, i, col);
				AuxiliaryDeepCamera[i * w + j] = judge;
			}
		}
	}
	// b~c
	for (int i = (int)b.yy; i < (int)c.yy; i++)
	{
		if (i < 0 || i >= h)continue;
		double t_b = (i - (int)b.yy) / (double)((int)c.yy - (int)b.yy);
		double t_c = (i - (int)a.yy) / (double)((int)c.yy - (int)a.yy);
		double x_b = b.xx + (c.xx - b.xx) * t_b;
		double x_c = a.xx + (c.xx - a.xx) * t_c;
		Vec3 vh = v2 * t_c - v3 * t_b;
		Vec3 beg = arr[1] + v3 * t_b;
		if (x_b > x_c)
		{
			Swap(x_b, x_c);
			vh = vh * -1;
			beg = arr[0] + v2 * t_c;
		}
		for (int j = (int)x_b; j < (int)x_c; j++)
		{
			if (j < 0 || j >= w)continue;
			double t_h = (j - x_b) / (double)x_c;
			Vec3 v4 = beg + vh * t_h;
			double judge = GetDepth(v4, ZAcross, ProjectSurfaceDis);
			double pnum = AuxiliaryDeepCamera[i * w + j];
			if (judge < pnum || judge>0 && pnum <= 0.0)
			{
				putpixel(j, i, col);
				AuxiliaryDeepCamera[i * w + j] = judge;
			}
		}
	}
}

// 矩阵乘法，其实只是向量之间一一对应相乘得到另一个向量
Vec3 MartixMultiple(Vec3 a, Vec3 b)
{
	return Vec3(a.xx * b.xx, a.yy * b.yy, a.zz * b.zz);
}

// 将三维三角形颠倒，也就是此三维三角形关于 xoy 平面，xoz 平面，yoz 平面对称的另一个三维三角形
Triangle ReversedTriangle(Triangle input, Vec3 dir)
{
	return Triangle(MartixMultiple(input.a, dir), MartixMultiple(input.b, dir), MartixMultiple(input.c, dir), input.H);
}

// 生成三角网，根据椭球面生成三角网，radiusX 是 X 轴半径，radiusY 是 Y 轴半径，radiusZ 是 Z 轴半径，layers 是层数
vector<Triangle> GenerateTriangleMesh(double radiusX, double radiusY, double radiusZ, int layers)
{
	vector<Triangle> parent;
	vector<Triangle> child;
	parent.push_back(Triangle(Vec3(1, 0, 0), Vec3(0, 1, 0), Vec3(0, 0, 1)));
	for (int i = 0; i < layers; i++)
	{
		for (Triangle i : parent)
		{
			Vec3 a_b = (i.a + i.b).GetUnitVector();
			Vec3 a_c = (i.a + i.c).GetUnitVector();
			Vec3 b_c = (i.b + i.c).GetUnitVector();
			child.push_back(Triangle(i.a, a_b, a_c));
			child.push_back(Triangle(a_b, i.b, b_c));
			child.push_back(Triangle(a_c, b_c, i.c));
			child.push_back(Triangle(b_c, a_c, a_b));
		}
		parent = child;
		child.clear();
	}
	Vec2 beginDir(1, 0);
	for (Triangle& i : parent)
	{
		Triangle temp = ReversedTriangle(i, Vec3(radiusX, radiusY, radiusZ));
		Triangle temp_1 = Triangle(temp.a, temp.b, temp.c);
		Triangle temp_2 = Triangle(temp.c, temp.b, temp.a);
		Triangle triArr[8] = { ReversedTriangle(temp_1, Vec3(1,  1,  1)), ReversedTriangle(temp_2, Vec3(-1,  1,  1)),
							   ReversedTriangle(temp_2, Vec3(1, -1,  1)), ReversedTriangle(temp_2, Vec3(1,  1, -1)),
							   ReversedTriangle(temp_1, Vec3(-1, -1,  1)), ReversedTriangle(temp_1, Vec3(1, -1, -1)),
							   ReversedTriangle(temp_1, Vec3(-1,  1, -1)), ReversedTriangle(temp_2, Vec3(-1, -1, -1)) };
		for (int index = 0; index < 8; index++)
		{
			triArr[index].H = 0;
			child.push_back(triArr[index]);
		}
	}
	return child;
}

// 鼠标横向拖动时 X 轴，Y 轴关于 Y 轴旋转
Vec3 HorizontalRotate(Vec3 X_Across, Vec3 Y_Across, double angle)
{
	Vec3 Z_Across = X_Across.MultiplicationCross(Y_Across);
	X_Across = X_Across * cos(angle) + Z_Across * sin(angle);
	return X_Across.GetUnitVector();
}

// 鼠标竖向拖动时 X 轴，Y 轴关于 X 轴旋转
Vec3 VerticalRotate(Vec3 X_Across, Vec3 Y_Across, double angle)
{
	Vec3 Z_Across = X_Across.MultiplicationCross(Y_Across);
	Y_Across = Y_Across * cos(angle) + Z_Across * sin(angle);
	return Y_Across.GetUnitVector();
}

// 绘画三角形集合
void DrawTriangleSet(vector<Triangle>& triangleSet, Vec3 X_Across, Vec3 Y_Across, Vec2 pericenter, double saturate = 1,
	double* AuxiliaryDeepCamera = nullptr, int w = 0, int h = 0)
{
	Vec3 Z_Across = X_Across.MultiplicationCross(Y_Across);
	for (Triangle& tri : triangleSet)
	{
		Vec3 normalVec = (tri.b - tri.a).MultiplicationCross(tri.c - tri.a).GetUnitVector();
		double extent = normalVec * Z_Across;
		if (extent > 0)
			DrawTriangle(tri, X_Across, Y_Across, pericenter, extent, saturate, w, h, AuxiliaryDeepCamera);
	}
}

// 旋转三维三角形
void RotateTriangle(Triangle& tri, double a, double b, double c)
{
	tri.a = tri.a.GetRotateVec(a, b, c);
	tri.b = tri.b.GetRotateVec(a, b, c);
	tri.c = tri.c.GetRotateVec(a, b, c);
}

// 旋转三角形集合
void RotateTriangleSet(vector<Triangle>& triSet, double a, double b, double c)
{
	for (Triangle& i : triSet)
	{
		RotateTriangle(i, a, b, c);
	}
}

// 将三角形切开一部分所形成的多边形的三角形
vector<Triangle> GetCutTriangles(Triangle tri)
{
	vector<Triangle>result;
	if (tri.a.xx < 0 && tri.b.xx < 0 && tri.c.xx < 0)return result;
	Vec3 temp[3];
	bool flag = false;
	if (tri.a.xx < 0 && tri.b.xx > 0 && tri.c.xx > 0)
	{
		temp[0] = tri.a;
		temp[1] = tri.b;
		temp[2] = tri.c;
	}
	else if (tri.b.xx < 0 && tri.a.xx>0 && tri.c.xx > 0)
	{
		temp[0] = tri.b;
		temp[1] = tri.c;
		temp[2] = tri.a;
	}
	else if (tri.c.xx < 0 && tri.a.xx>0 && tri.b.xx > 0)
	{
		temp[0] = tri.c;
		temp[1] = tri.a;
		temp[2] = tri.b;
	}
	else if (tri.a.xx > 0 && tri.b.xx <= 0 && tri.c.xx <= 0)
	{
		flag = true;
		temp[0] = tri.a;
		temp[1] = tri.b;
		temp[2] = tri.c;
	}
	else if (tri.b.xx > 0 && tri.a.xx <= 0 && tri.c.xx <= 0)
	{
		flag = true;
		temp[0] = tri.b;
		temp[1] = tri.c;
		temp[2] = tri.a;
	}
	else if (tri.c.xx > 0 && tri.a.xx <= 0 && tri.b.xx <= 0)
	{
		flag = true;
		temp[0] = tri.c;
		temp[1] = tri.a;
		temp[2] = tri.b;
	}
	Vec3 temp_b = temp[1] - temp[0];
	Vec3 temp_c = temp[2] - temp[0];
	double t_b = abs(temp[0].xx) / abs(temp_b.xx);
	double t_c = abs(temp[0].xx) / abs(temp_c.xx);
	Vec3 p_1 = temp[0] + temp_b * t_b, p_2 = temp[0] + temp_c * t_c;
	if (!flag)
	{
		result.push_back(Triangle(p_1, temp[1], p_2, tri.H));
		result.push_back(Triangle(temp[1], temp[2], p_2, tri.H));
	}
	else
	{
		result.push_back(Triangle(temp[0], p_1, p_2));
	}
	return result;
}

// 生成心脏三角形网格
vector<Triangle> GenerateHeartTM(double radiusX, double radiusY, double radiusZ, double angle)
{
	vector<Triangle> triangleMesh = GenerateTriangleMesh(radiusX, radiusY, radiusZ, 5);
	RotateTriangleSet(triangleMesh, 0, 0, -angle);
	vector<Triangle> tempTM;
	for (int i = 0; i < triangleMesh.size(); i++)
	{
		if (triangleMesh[i].a.xx < 0 || triangleMesh[i].b.xx < 0 || triangleMesh[i].c.xx < 0)
		{
			vector<Triangle> temp = GetCutTriangles(triangleMesh[i]);
			for (int j = 0; j < temp.size(); j++)
			{
				tempTM.push_back(temp[j]);
				tempTM.push_back(ReversedTriangle(Triangle(temp[j].c, temp[j].b, temp[j].a), Vec3(-1, 1, 1)));
			}
		}
		else
		{
			tempTM.push_back(triangleMesh[i]);
			tempTM.push_back(ReversedTriangle(Triangle(triangleMesh[i].c, triangleMesh[i].b, triangleMesh[i].a), Vec3(-1, 1, 1)));
		}
	}
	return tempTM;
}

// 主函数
int main()
{
	Vec3 X_Across(1, 0, 0), Y_Across(0, 1, 0);
	vector<Triangle> triangleMesh = GenerateHeartTM(150, 100, 100, PI / 4);
	// 深度值，点到投影面的距离
	double* AuxiliaryDeepCamera = new double[WIDTH * HEIGHT];
	memset(AuxiliaryDeepCamera, 0, sizeof(double) * WIDTH * HEIGHT);
	initgraph(WIDTH, HEIGHT);
	BeginBatchDraw();
	bool isExit = false;
	bool isLPress = false;
	double saturate = 1;
	Vec2 ori_L;
	ExMessage msg;
	while (!isExit)
	{
		while (peekmessage(&msg, EM_KEY | EM_MOUSE))
		{
			if (msg.message == WM_KEYDOWN)
			{
				if (msg.vkcode == VK_ESCAPE) isExit = true;
			}
			else if (msg.message == WM_MOUSEMOVE || msg.message == WM_LBUTTONDOWN || msg.message == WM_LBUTTONUP)
			{
				if (!isLPress && msg.lbutton)
				{
					ori_L = Vec2(msg.x, msg.y);
					isLPress = true;
				}
				else if (isLPress && msg.lbutton)
				{
					Vec2 next = Vec2(msg.x, msg.y);
					ori_L = next - ori_L;
					double Th = 0;
					double Fi = 0;
					Th = ori_L.xx / GAMEPAD * PI / 3;
					Fi = ori_L.yy / GAMEPAD * PI / 3;
					X_Across = HorizontalRotate(X_Across, Y_Across, Th);
					Y_Across = VerticalRotate(X_Across, Y_Across, Fi);
					ori_L = next;
				}
				else if (isLPress && !msg.lbutton)
				{
					isLPress = false;
				}
			}
		}
		cleardevice();
		memset(AuxiliaryDeepCamera, 0, sizeof(double) * WIDTH * HEIGHT);
		DrawTriangleSet(triangleMesh, X_Across, Y_Across, Vec2(WIDTH / 2, HEIGHT / 2), saturate, AuxiliaryDeepCamera, WIDTH, HEIGHT);
		FlushBatchDraw();
	}
	delete[] AuxiliaryDeepCamera;
	return 0;
}
