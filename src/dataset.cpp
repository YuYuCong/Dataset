/*=================================================================================
 *	                    Copyleft! 2018 William Yu
 *          Some rights reserved：CC(creativecommons.org)BY-NC-SA
 *                      Copyleft! 2018 William Yu
 *      版权部分所有，遵循CC(creativecommons.org)BY-NC-SA协议授权方式使用
 *
 * Filename                : dataset.cpp
 * Description             : 
 * Reference               : 
 * Programmer(s)           : William Yu, windmillyucong@163.com
 * Company                 : HUST
 * Modification History	   : ver1.0, 2018.10.16, William Yu
 *                           
=================================================================================*/

#include "include_all.h"

/// Global Variables
#define gVLUM 400 //数据集大小
#define gFREC 1000 //采集周期：图片采集周期1000ms，视频采集1帧20ms
#define catchimg
//#define catchvideo
string path_to_data = "../data/";


/// Function Definitions

/** 
* 在字符串前面补0 
* @param length：字符串固定长度 
* @return 
*/  

template <typename T, typename S>
T fill_cast(const S& v, const int width, const char c)
{
        T result;
        std::stringstream inter;
        inter << std::setw(width) << std::setfill(c) << v;
        inter >> result;
        return result;
}

/**
 * @function main
 * @author William Yu
 */
int main(int argc,char** argv)
{
	VideoCapture capture(1); 
    cout<<"width:"<<capture.get(CV_CAP_PROP_FRAME_WIDTH)<<endl;
    cout<<"height:"<<capture.get(CV_CAP_PROP_FRAME_HEIGHT)<<endl;
    capture.set(CV_CAP_PROP_FRAME_WIDTH, 640);  
    capture.set(CV_CAP_PROP_FRAME_HEIGHT, 480); 

#ifdef catchvideo
    VideoWriter writer( path_to_data+"Video.avi", CV_FOURCC('M', 'J', 'P', 'G'), 25.0, Size(640, 480));
#endif

    Mat frame;
	int i = 0;
    string filenum;
    Mat imageRGB[3];

	while (capture.isOpened())
	{
        capture >> frame;
        imshow("frame", frame);
		
        char key = (char)waitKey(gFREC); 




        // split(frame, imageRGB);
        // for (int i = 0; i < 3; i++)
        // {
        //     equalizeHist(imageRGB[i], imageRGB[i]);
        // }
        // merge(imageRGB, 3, frame);
        // imshow("frame_equalizeHist", frame);





#ifdef catchimg
        //if ( key == 'c' ) //按c采集图像  
		{
            i++;
            filenum = to_string(i);
            //左补齐0
            filenum = fill_cast<string>(filenum, 3, '0');
            cout << "No." << filenum << endl;
            imwrite( path_to_data+"data"+filenum+".png", frame );  
		}

        if ( i >= gVLUM )
            break;
#endif






#ifdef catchvideo
		capture >> frame;
		writer << frame;
        waitKey(gFREC);
#endif





        if( key == 27 || key == 'q' || key == 'Q' ) // 'ESC'
           break;

	}
	return 0;
}

