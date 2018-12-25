/*=================================================================================
 *	                    Copyleft! 2018 William Yu
 *          Some rights reserved：CC(creativecommons.org)BY-NC-SA
 *                      Copyleft! 2018 William Yu
 *      版权部分所有，遵循CC(creativecommons.org)BY-NC-SA协议授权方式使用
 *
 * Filename                : video2img.cpp
 * Description             : 
 * Reference               : 
 * Programmer(s)           : William Yu, windmillyucong@163.com
 * Company                 : HUST
 * Modification History	   : ver1.0, 2018.10.24, William Yu
 *                           
=================================================================================*/

#include "include_all.h"

/// Global Variables
#define gVLUM 400 //数据集大小
#define gFREC 0 //采集周期：图片采集周期1000ms，视频采集1帧20ms

string path_to_data = "../data/video/";
string videoname = "head.mp4";

#define k 0.5  //数据压缩比例

/// Function Definitions

/** 
 * @function fill_cast
 * @author William Yu
 * @brief 在字符串前面补0
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
	VideoCapture capture(path_to_data + videoname); 
    cout<<"width:"<<capture.get(CV_CAP_PROP_FRAME_WIDTH)<<endl;
    cout<<"height:"<<capture.get(CV_CAP_PROP_FRAME_HEIGHT)<<endl;

    Mat frame;
	int i = 0;
    string filenum;

	while (capture.isOpened())
	{
        capture >> frame;
        imshow("frame", frame);
		
        char key = (char)waitKey(gFREC); 

        resize(frame, frame, Size(k*capture.get(CV_CAP_PROP_FRAME_WIDTH), k*capture.get(CV_CAP_PROP_FRAME_HEIGHT)), 0, 0, CV_INTER_LINEAR);
        
        i++;
        filenum = to_string(i);
        //左补齐0
        filenum = fill_cast<string>(filenum, 3, '0');
        cout << "No." << filenum << endl;
        imwrite( path_to_data + "data" + filenum + ".png", frame );  

        if ( i >= gVLUM )
            break;

        if( key == 27 || key == 'q' || key == 'Q' ) // 'ESC'
           break;

	}
	return 0;
}

