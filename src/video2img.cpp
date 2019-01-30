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
 *                           ver1.0, 2019.01.28, William Yu, add cmdLineParser
=================================================================================*/

#include "include_all.h"

/// Global Variables
const char* keys =
{
    "{help h           |                            | show help message}"
    "{@path_to_video   |../data/video/video.mp4     | input video}"
    "{@path_to_output  |../data/video/frameoutput/  | output img}"
    "{k                |1                           | Compression ratio}"
    "{VLUM v           |400                         | 数据集大小}"
    "{FREC f           |1                           | 采集周期：图片采集周期1000ms，视频采集1帧20ms}"
};

/// Function Definitions

/** 
 * @function help
 * @author William Yu
 * @brief print a help message, and the OpenCV version
 */
static void help()
{
    cout << "\nSplit video frame to img,"
            "\nUsing OpenCV version " << CV_VERSION << endl;
    cout << "\nCall:\n"
            "    $ cd ./bin\n\n"
            "    $ ./video2img [path_to_video -- Default ../data/video/video.mp4] [path_to_video -- Default ../data/video/frameoutput/] -k=[压缩率 -- Default 1 不压缩] -v=[图片数 -- Default 400]\n"
            "    eg. $ ./video2img  ../data/video/video.mp4 ../data/video/frameoutput/ -k=0.8 -v=200\n\n";
}

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
    CommandLineParser parser(argc, argv, keys);  
    if (parser.has("help"))  { help();  return 0; }
    string path_to_video = parser.get<string>( 0 );
    string path_to_output = parser.get<string>( 1 );
    double k = parser.get<double>( "k" );
    int gVLUM = parser.get<double>( "VLUM" );
    int gFREC = parser.get<double>( "FREC" );
	
    VideoCapture capture(path_to_video); 
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
        imwrite( path_to_output + "data" + filenum + ".png", frame );  

        if ( i >= gVLUM )
            break;

        if( key == 27 || key == 'q' || key == 'Q' ) // 'ESC'
           break;

	}
	return 0;
}