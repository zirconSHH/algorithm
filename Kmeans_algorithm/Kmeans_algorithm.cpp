// Kmeans_algorithm.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

class point
{
public:
	point(double a = 0, double b = 0) :x(a), y(b) {};

	double getx() const { return x; }
	double gety() const { return y; }

	void changex(const double& a) { x = a; }
	void changey(const double& a) { y = a; }
	void chanageto(const double& a, const double& b) { x = a; y = b; }

	double distanceto(const point& p);
private:
	double x;
	double y;
};

double getdistance(const point& pt1, const point& pt2)
{
	double tmp = pow(pt1.getx() - pt2.getx(), 2) + pow(pt1.gety() - pt2.gety(), 2);
	return sqrt(tmp);

}


vector<point> Kmeans(const vector<point>& points, int centernum, int iternum = 100)
{
	int pointnum = points.size();
	vector<point> centerpoints;
	for (int i = 0; i < centernum; i++)
	{
		centerpoints.push_back(points[i]);
	}

	vector<int> labels;

	for (int i = 0; i < pointnum; i++)
	{
		labels.push_back(0);
	}

	bool ifchange = true;
	int counter = 0;
	while (ifchange == true && counter < 100)
	{
		ifchange = false;
		for (int pointNum = 0; pointNum < pointnum; ++pointNum)
		{
			double mindistance = getdistance(points[pointNum], centerpoints[0]);
			for (int cluster = 0; cluster < centernum; ++cluster)
			{
				double tmp = getdistance(points[pointNum], centerpoints[cluster]);
				if (tmp < mindistance)
				{
					mindistance = tmp;
					labels[pointNum] = cluster;
					ifchange = true;
				}
			}

		}

		for (int j = 0; j < centernum; j++)
		{
			int count = 0;
			double xsum = 0;
			double ysum = 0;
			for (int i = 0; i < pointnum; i++)
			{
				if (labels[i] == j)
				{
					count++;
					xsum += points[i].getx();
					ysum += points[i].gety();
				}
			}
			centerpoints[j].changex(xsum / count);
			centerpoints[j].changey(ysum / count);
		}

		counter++;
	}

	return centerpoints;
}





int main()
{
	vector<point> points;
	int pointnum = 100;
	int K = 5;

	for (int i = 0; i < pointnum; i++)
	{
		point point1;
		point1.changex(rand() % 500 / 10);
		point1.changey(rand() % 500 / 10);
		points.push_back(point1);
	}

	vector<point> res(Kmeans(points, K));

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i].getx() << "," << res[i].gety() << endl;
	}

	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

double point::distanceto(const point& p)
{
	double tmp = pow(this->getx() - p.getx(), 2) + pow(this->gety() - p.gety(), 2);
	return sqrt(tmp);

}

