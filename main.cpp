#include <iostream>
#include <Eigen/Dense>
 
using namespace Eigen;
 
int main()
{
  std::cout << "Motesque Magic Eigen" << std::endl;
  MatrixXd m(2,2);
  m(0,0) = 3;
  m(1,0) = 2.5;
  m(0,1) = -1;
  m(1,1) = m(1,0) + m(0,1);
  std::cout << m << std::endl;
}