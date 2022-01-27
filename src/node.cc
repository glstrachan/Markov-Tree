
#include "include/node.hh"

void node::addNode(node* newChild)
{
  children.push_back(newChild);
}

void node::printChildren(std::vector<bool> last, std::vector<node*> parents)
{
  std::string indent = "";
  for(int i = 0; i < last.size(); i++)
  {
    indent += (i == last.size() - 1 ? (last[i] ? "└──" : "├──") : (last[i] ? "   " : "│  "));
  }

  std::cout << indent << "[" << "\033[1;3" << (type[0] + 3) % 8 << "m" << type << "\033[0m" << "]" << std::endl;

  if (std::count(parents.begin(), parents.end(), this) > 1) return;

  for(int i = 0; i < children.size(); i++)
  {
    node* child = children[i];

    last.push_back(i == children.size() - 1);
    parents.push_back(child);

    child->printChildren(last, parents);

    last.pop_back();
    parents.pop_back();
  }
}

int node::activate(const context &c)
{
  return (c.time > 3 ? 1 : 0);
}

int nodePass::activate(const context &c)
{
  return (c.time > 3 ? 1 : 0);
}

int nodeShoot::activate(const context &c)
{
  return (c.time > 3 ? 1 : 0);
}