#include "include/node.hh"

int main(int count, char** args)
{
  node X = node();
  node A = node();
  nodeShoot B = nodeShoot();
  nodePass C = nodePass();
  A.addNode(&B);
  A.addNode(&B);
  B.addNode(&C);
  B.addNode(&C);
  C.addNode(&A);
  X.addNode(&A);
  X.addNode(&A);
  
  X.printChildren({}, {&X});
  return 0;
}