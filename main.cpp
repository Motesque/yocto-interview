
#include <Eigen/Dense>
#include <iostream>
#include <fstream>

using namespace Eigen;

int check_os_super_strict() {
  std::ifstream osInfoFile;
  osInfoFile.open("/etc/os-release");
  if (osInfoFile.is_open())
  {
    std::string line;
    while (getline(osInfoFile, line))
    {
      if (line.find("18.04.4 LTS (Bionic Beaver)") != std::string::npos) 
      {
        return 0;
      }
    }
    osInfoFile.close();
  } 
  std::cout << "This OS is not supported! Not sure why..." << std::endl;
  return -1;
}


int main()
{
  if (check_os_super_strict() != 0) {
    exit(-1);
  }
  std::cout << "Motesque Magic Eigen" << std::endl;
  MatrixXd m(2,2);
  m(0,0) = 3;
  m(1,0) = 2.5;
  m(0,1) = -1;
  m(1,1) = m(1,0) + m(0,1);
  std::cout << m << std::endl;
}