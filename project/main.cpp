#include "nditrack.h"
#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char**argv)
{
    const std::string PortName = "/dev/ttyUSB0";


    NDItracking::Ptr nditrack = std::make_shared<NDItracking>(PortName);
    
    sleep(3);
    
    while(true){

    	Sophus::SE3 Tcw = nditrack->getPoseTcw();
    	cout<<"Transformation matrix is:"<<endl<<Tcw.matrix()<<endl;
    	usleep(100);
    }

    return 0;
}
