//#include <stdio.h>
//#include <algorithm>
//#include <vector>
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/opencv.hpp>
//#include <fstream>
//
////#include "FaceDetector.h"
////#include "../../Face_Detector_ncnn/FaceDetector.h"
//
//using namespace std;
//
//int main(int argc, char** argv)
//{
//    float a[8] = { 5,6,7,8,1,2,3,4 };
//    cv::Mat c = cv::Mat(2, 4, CV_32FC1, a);
//    //cout << c.channels() << " " << c.cols << " " << c.rows<<" "<<c << endl;
//
//	const float* const table = (const float*)0;
//	float** array = new float * [c.rows];
//	float* p;
//	float m[8];
//	for (int i = 0; i < c.rows; ++i)
//	{
//		p = c.ptr<float>(i);
//		for (int j = 0; j < c.cols; ++j)
//		{
//			m[i * c.rows + j] = p[j];
//			cout << m[i * c.rows + j] << endl;
//		}
//	}
//	
//
//    //cout << c.data[0] << endl;
//    return 0;
//}
//





#include<stdio.h>
#include <iostream>
int main(void)
{
    int array1[6][7] = {
            {16,4,3,12,6,0,3},
            {4,-5,6,7,0,0,2},
            {6,0,-1,-2,3,6,8},
            {5,3,4,0,0,-2,7},
            {-1,7,4,0,7,-5,6},
            {0,-1,3,4,12,4,2}
    };
    int b[6][7], c[6][7];
    int i, j, k;
    int max;
    int flag;

    for (i = 0; i < 6; i++)
        for (j = 0; j < 7; j++)
        {
            b[i][j] = array1[i][j];
            c[i][j] = -1;
        }
    for (i = 1; i < 5; i++)
    {
        for (j = 0; j < 7; j++)
        {
            max = 0;
            for (k = j - 2; k <= j + 2; k++)
            {
                if (k < 0) continue;
                else
                    if (k > 6) break;
                    else
                    {
                        if (b[i][j] + b[i - 1][k] > max)//取值i=1到4,j=2到6,k=0到6
                        {
                            max = b[i][j] + b[i - 1][k];
                            flag = k;
                            //std::cout << max <<" "<<i<<" "<<j<<" "<< k<< std::endl;
                        }
                    }
            }
            b[i][j] = max;
            c[i][j] = flag;
            //std::cout << max << " " << i << " " << j << " " << k << std::endl;
        }
    }
     
    std::cout << max << " " << i << " " << j << " " << k << std::endl;

    for (j = 1; j <= 5; j++)
    {
        max = 0;
        for (k = j - 2; k <= j + 2; k++)
        {
            if (k < 0)
                continue;
            else
                if (k > 6)  break;
                else
                {
                    if (b[i][j] + b[i - 1][k] > max)//取值i=1到5,取值j=2到5,,k=0到6
                    {
                        max = b[i][j] + b[i - 1][k];
                        flag = k;
                    }
                }
        }
        b[i][j] = max;
        c[i][j] = flag;
    }
    std::cout << max << " " << i << " " << j << " " << k << std::endl;

    max = 0;
    for (j = 1; j <= 5; j++)
    {
        if (b[i][j] > max)//取值i=0到5，j=1到5    
        {
            max = b[i][j];
            flag = j;
        }
    }
    std::cout << max << " " << i << " " << j << " " << k << std::endl;
    printf("�������Ž��Ϊ%d\n", max);
    printf("·��Ϊ��");
    printf("%d", array1[i][flag]);
    for (j = i; j > 0; j--)
    {
        flag = c[j][flag];
        printf("%5d", array1[j - 1][flag]);
    }
    printf("\n");
    return 0;
}

