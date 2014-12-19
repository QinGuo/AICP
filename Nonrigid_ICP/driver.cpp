#include <iostream>
#include <Eigen/Dense>
#include"Skeleton.h"
#include"ArticulatedICP.h"
#include"time.h"
#include"stdlib.h"
//using Eigen::MatrixXd;

Point CloudPoints[WIDTH*HEIGHT];
void readCloudPoints();

int main()
{
	
	//MatrixXd m(2,2);
	//m(0,0) = 3;
	//m(1,0) = 2.5;
	//m(0,1) = -1;
	//m(1,1) = m(1,0) + m(0,1);
	//Eigen::Matrix3f aa;
	//aa<<1,2,3,
	//	4,5,6,
	//	7,8,9;
	//std::cout <<aa<< std::endl;

	Skeleton mySkeleton;
	mySkeleton.makeHandSkeleton();
	//mySkeleton.printSkeletonPara();
	readCloudPoints();
	ArticulatedICP mArticulatedICP(CloudPoints,mySkeleton);
	mArticulatedICP.ICP_Loop(10);
	return 0;
}
void readCloudPoints()
{

	
	for(int i=0;i<HEIGHT;i++)
		for(int j=0;j<WIDTH;j++)
		{
			CloudPoints[i*WIDTH+j].x=rand()/1000.0;
			CloudPoints[i*WIDTH+j].y=rand()/1000.0;
			CloudPoints[i*WIDTH+j].z=rand()/1000.0;
			CloudPoints[i*WIDTH+j].v[0]=CloudPoints[i*WIDTH+j].x;
			CloudPoints[i*WIDTH+j].v[1]=CloudPoints[i*WIDTH+j].y;
			CloudPoints[i*WIDTH+j].v[2]=CloudPoints[i*WIDTH+j].z;
		}
}