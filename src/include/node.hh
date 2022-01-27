#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include "context.hh"

struct node
{
  void addNode(node* newChild);
  void printChildren(std::vector<bool> last, std::vector<node*> parents);
  
  std::string type;
  int activate(const context &c);
  std::vector<node*> children;
  node(std::string type = "default") : type{type} {} 
};

/* Child Node types */
struct nodeShoot : public node
{
  nodeShoot() : node("shoot") {}
  int activate(const context &c);
};

struct nodePass : public node
{
  nodePass() : node("pass") {}
  int activate(const context &c);
};