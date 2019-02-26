#include <iostream> 
#include <list> 
#include <iterator> 
#include<map>
#include <set>
using namespace std; 
list <int> node[100];
set <char> color_set;   
map<int,char> color;
int color1=1;
void start_coloring(int node_count)
{
    int color_val=65;
    list <int> :: iterator it; 
    //Initializing color for of the node
    for(int itr=0;itr<node_count;itr++)
    {
        if(color.find(itr)->second==32)
       {
          //starting color 65-A......
           int start_val=65;
           l:
           	int flag=0;
           list <int> :: iterator it1; 
           //checking for the present color in the adj. list
        for(it1 = node[itr].begin(); it1 != node[itr].end(); ++it1) 
        {
            if(color.find(*it1)->second==start_val)
            {
                start_val++;
                goto l;
            }
        }
        if(flag==0)
        {
            color.find(itr)->second=start_val;
            color_set.insert(start_val);
            continue;
        }
       }
    }
}
//printing color of each node
void show_color()
{
    map<int, char>::iterator itr; 
    for (itr = color.begin(); itr != color.end(); ++itr) { 
        cout << '\t' << itr->first 
             << '\t' << itr->second << '\n'; 
    } 
}
//Creating node and assigning a blank color to it
void create_node(int node_count)
{
    for(int itr=0;itr<node_count;itr++)
    {list <int> node[itr];
     color.insert(pair<int, char>(itr, 32)); }
    
}
//getting the edges
void get_edges(int edge_count)
{
    int start,end;
    for(int itr=0;itr<edge_count;itr++)
    {
        cout<<"enter the starting of an edge";
        cin>>start;
        cout<<"enter the ending of an edge";
        cin>>end;
        node[start].push_back(end);
        node[end].push_back(start);
    }
}
//function for printing the elements in a list 
void showlist(list <int> g) 
{ 
    list <int> :: iterator it; 
    for(it = g.begin(); it != g.end(); ++it) 
        cout <<"->"<<*it; 
    cout << '\n'; 
} 
  
int main() 
{ 
  
  int node_count,edge_count;
  cout<<"enter the no of nodes";
  cin>>node_count;
  cout<<"enter the edges";
  cin>>edge_count;
  create_node(node_count);
  get_edges(edge_count);
  
  cout<<"NODE LIST"<<"\n";
  for(int itr=0;itr<node_count;itr++)
  {
      cout<<itr;
      cout<<"---";
      showlist(node[itr]);
      cout<<"\n";
  }
  start_coloring(node_count);
  cout<<"\n";
   cout<<"NODE COLORING-----MINIMUM COLOR NEEDED=="<<color_set.size()<<"\n";
  show_color();
    return 0; 
} 
