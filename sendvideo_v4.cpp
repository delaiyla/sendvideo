#include <string>
#include <vector>
#include <iostream>
#include <fstream>

bool fileExists(const std::string& filename) {
    std::ifstream file(filename.c_str());
    return file.good();
}

std::vector<std::string> readLinesFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::string> lines;

    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    return lines;
}

int main() {
	std::vector<std::string> outputLines;
	std::vector<std::string> inputLines;
	
    if (fileExists("sendvideo_output.txt")) {
        outputLines = readLinesFromFile("sendvideo_output.txt");
    } else std::ofstream file("sendvideo_output.txt");
    
     if (fileExists("sendvideo_input.txt")) {
        inputLines = readLinesFromFile("sendvideo_input.txt");
    } else std::ofstream file("sendvideo_input.txt");
	
    std::ifstream inputFile("sendvideo_input.txt");
    if (!inputFile) {
        std::cerr << "Failed to open input file" << std::endl;
        return 1;
    }

    std::string stream;
    std::vector<std::string>::iterator ip = outputLines.begin();
    while (std::getline(inputFile, stream)) {
        std::string command = "ffmpeg -hide_banner -re -fflags +genpts -flags +global_header -stream_loop -1 -thread_queue_size 4096  -i " +
                              stream + 
					//		  " -c:v copy " +
							  " -c:v libx265 -vtag hvc1 -b:v 2M" +  
							  
							  " -c:a " +


//#ifdef _WIN32
//	"libvo_aacenc" +
//#else


	   			   			  //		 "copy" +
	   			   			  	"aac" +
//#endif 	
						  
							  " -b:a 128K -vsync 1 -fflags nobuffer -preset ultrafast -tune zerolatency " +
   		   					  " -muxpreload 3.5 -muxdelay 0.1 " +
				//	          " -thread_queue_size 2048 " +
							  " -f rtsp -muxdelay 0.1 " +
							  " -pix_fmt yuv420p " +
						      " -muxpreload 3.5 " +
                              " -indexmem 1M -rtbufsize 2M -probesize 1M " +
							  " -analyzeduration 0 " +
                       
					   		  " -avoid_negative_ts \"make_zero\" " +
                              " -rtsp_transport tcp " + *ip;
							  // > /dev/null 2>&1 < /dev/null &
        if(ip != outputLines.end()) ++ip;

        // Execute the ffmpeg command
        //std::cout << command << std::endl;
        
 		// Запус отдельным процессом каждого отправляемого видеопотока на сервер

 #if defined(_WIN32)
        system(("start cmd.exe @cmd /k " + command).c_str());
 #else
		system(("screen -d -m -S jabber " + command).c_str());
 #endif
    }

    inputFile.close();

    return 0;
}