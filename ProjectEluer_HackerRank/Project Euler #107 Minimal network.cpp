#include <iostream>

#include <set>
#include <map>
#include <queue>

typedef unsigned int Node;
typedef unsigned int Weight;

struct Edge
{
  Node from;
  Node to;
  Weight weight;

  bool operator<(const Edge& other) const
  {
    
    if (weight != other.weight)
      return weight > other.weight;

    
    if (from   != other.from)
      return from   < other.from;

    return to < other.to;
  }
};

std::map<std::pair<Node, Node>, Weight> network;
std::set<Node> nodes;

unsigned int initialSum = 0;

void addEdge(Node from, Node to, Weight weight)
{
  initialSum += weight;

  if (from > to)
    std::swap(from, to);

  auto fromTo = std::make_pair(from, to);
  if (network.count(fromTo) != 0)
   
    if (network[fromTo] <= weight)
      return;

  network[fromTo] = weight;
  nodes.insert(from);
  nodes.insert(to);
}

int main()
{
#ifdef ORIGINAL

  for (unsigned int i = 0; i < 40; i++)
    for (unsigned int j = 0; j < 40; j++)
    {
      char c = 0;
      unsigned int weight = 0;
      while (c != ',' && c != '\n')
      {
        c = std::cin.get();
        if (c >= '0' && c <= '9')
        {
          weight *= 10;
          weight += c - '0';
        }
      }

      if (weight != 0 && i < j)
        addEdge(i, j, weight);
    }

#else

  unsigned int numNodes, numEdges;
  std::cin >> numNodes >> numEdges;
  for (unsigned int i = 0; i < numEdges; i++)
  {
    Node   from, to;
    Weight weight;
    std::cin >> from >> to >> weight;
    addEdge(from, to, weight);
  }
#endif

  std::set<Edge> minimal;

  std::set<Node> done;
  done.insert(*nodes.begin());

  while (done.size() < nodes.size())
  {
   
    std::priority_queue<Edge> next;
    for (auto e : network)
    {
      auto fromTo  = e.first;
      bool hasFrom = done.count(fromTo.first)  != 0;
      bool hasTo   = done.count(fromTo.second) != 0;
      if (hasFrom == hasTo) 
        continue;

      next.push({fromTo.first, fromTo.second, e.second});
    }

    auto add = next.top();

    done.insert(add.from); 
    done.insert(add.to);

    minimal.insert(add);
  }

  unsigned int optimizedSum = 0;
  for (auto i : minimal)
    optimizedSum += i.weight;

#ifdef ORIGINAL
  auto gain = initialSum - optimizedSum;
  std::cout << gain << std::endl;
#else
  std::cout << optimizedSum << std::endl;
#endif


}