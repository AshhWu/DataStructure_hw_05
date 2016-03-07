// CodeBlocks
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class MyGraph
{
private:
    int num_of_vertices;
    vector<int> *Adj;   //記錄每個vertix連到的vertices
    bool* visited;      //紀錄是否走過的動態bool array
public:
    MyGraph(){}
    MyGraph(int V,int* arr);        //constructor
    ~MyGraph(){}
    void addEdge(int from, int to);
    void DFS(int Start);
    void CC();
};

MyGraph::MyGraph(int V,int* arr)    //constructor
{
    num_of_vertices=V;
    Adj = new vector<int>[V];
    int i,j;
    for(i=0;i<num_of_vertices;i++)  //走遍array將edge建立起來
    {
        for(j=0;j<num_of_vertices;j++)
        {
            if(arr[num_of_vertices*i+j])    //若num_of_vertices*i+j為1則加入edge
                addEdge(i,j);
        }
    }

}

void MyGraph::addEdge(int from, int to)
{
    Adj[from].push_back(to);    // Add "from" to "to" list.
}

void MyGraph::DFS(int Start)    //利用stack做nonrecursive的DFS
{
    stack<int> stack;
    vector<int>::iterator i;
    stack.push(Start);          //將開始元素push進空stack

    while(!stack.empty())
    {
        int top;
        top=stack.top();        //叫出最上方的元素
        if(visited[top]==true)  //若拜訪過則pop掉跳過
        {
            stack.pop();
            continue;
        }
        cout<<top<<' ';
        visited[top]=true;      //mark已拜訪過
        stack.pop();            //pop掉最上面的
        i=Adj[top].begin();     //iterator i從第一個元素開始
        for(;i!=Adj[top].end();i++) //直到end
        {
            if(!visited[*i])    //若未拜訪過則push進stack
                stack.push(*i);
        }

    }
    cout<<endl;
}

void MyGraph::CC()
{
    visited=new bool[num_of_vertices];  //紀錄是否走過
    fill(visited,visited+num_of_vertices,false);//初始visited
    int num_component=0;                //number of component
    for(int i=0;i<num_of_vertices;i++)  //走遍每個vertices
    {
        if(!visited[i])                 //若未拜訪過則拜訪 每一次都是一個component
        {
            num_component++;
            cout<<"Component#"<<num_component<<": ";
            DFS(i);
            cout<<endl;
        }
    }
    delete [] visited;      //delete動態array
}
