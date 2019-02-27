#include <iostream> 
#include <list> 
#include <iterator> 
using namespace std; 
list <int> node[100];
int node_count;
void create_node(int node_count)
{
    for(int itr=0;itr<node_count;itr++)
    {
    	list <int> node[itr];
     }
    
}
//getting the edges
void get_edges(int edge_count)
{
    int start,end;
    for(int itr=0;itr<edge_count;itr++)
    {
    	char a[3];
        cout<<"enter an edge";
        cin>>a;
        start=a[0]-'A';
        end=a[1]-'A';
        node[start].push_back(end);
        //node[end].push_back(start);
        //Above comment is added for undirected graphs.
    }
}
//function for printing the elements in a list 
void showlist(list <int> g) 
{ 
    list <int> :: iterator it; 
    for(it = g.begin(); it != g.end(); ++it) 
        cout <<"->"<<char(*it+65); 
    cout << '\n'; 
} 
void printAllPaths(int u, int d, bool visited[], 
                            int path[], int &path_index) 
{ 
    // mark the node set visited to TRUE and store it in path
    visited[u] = true; 
    path[path_index] = u; 
    path_index++; 
  
    // current node is same as dest. print the value
    if (u == d) 
    { 
        cout<<"\nSTART";
        for (int i = 0; i<path_index; i++) 
            cout<<"->"<< char(path[i]+65); 
        cout << endl; 
          
    } 
    else // currentnode not equal to the destination 
    { 
        // go to all the adj nodes
        list<int>::iterator i; 
        for (i = node[u].begin(); i != node[u].end(); ++i) 
            if (!visited[*i]) 
                printAllPaths(*i, d, visited, path, path_index); 
    } 
  
    // Remove current vertex from path array and mark visited as False 
    path_index--; 
    visited[u] = false; 
} 
int main()
{
	int edge_count;
	char src;
  cout<<"enter the no of nodes";
  cin>>node_count;
  cout<<"enter the edges";
  cin>>edge_count;
  create_node(node_count);
  get_edges(edge_count);
  
  cout<<"\n\nNODE LIST"<<"\n";
  for(int itr=0;itr<node_count;itr++)
  {
      cout<<char(itr+65);
      cout<<"---";
      showlist(node[itr]);
      cout<<"\n";
  }
  cout<<"Enter the source";
  cin>>src; 
  cout<<"\n\nFrom the source "<<src<<":::::\n";
   for(int i=0;i<node_count;i++) 
   	if(i!=int(src-'A'))
   	{
   		cout<<"\nTo\t"<<char(i+65)<<"::\n";
    // array to store visited or not
    bool *visited = new bool[node_count]; 
    // array to store path
    int *path = new int[node_count]; 
    // Initialize path as empty
    int path_index = 0; 
    // Initialize all vertices visited array as False or 0
    for (int i = 0; i < node_count; i++) 
        visited[i] = false; 
    // function to print all paths
    printAllPaths(int(src-'A'),i, visited, path, path_index); 
   	}
   cout << '\n';

  
  return 0;
}