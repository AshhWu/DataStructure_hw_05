// CodeBlocks
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class MyGraph
{
private:
    int num_of_vertices;
    vector<int> *Adj;   //�O���C��vertix�s�쪺vertices
    bool* visited;      //�����O�_���L���ʺAbool array
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
    for(i=0;i<num_of_vertices;i++)  //���Marray�Nedge�إ߰_��
    {
        for(j=0;j<num_of_vertices;j++)
        {
            if(arr[num_of_vertices*i+j])    //�Ynum_of_vertices*i+j��1�h�[�Jedge
                addEdge(i,j);
        }
    }

}

void MyGraph::addEdge(int from, int to)
{
    Adj[from].push_back(to);    // Add "from" to "to" list.
}

void MyGraph::DFS(int Start)    //�Q��stack��nonrecursive��DFS
{
    stack<int> stack;
    vector<int>::iterator i;
    stack.push(Start);          //�N�}�l����push�i��stack

    while(!stack.empty())
    {
        int top;
        top=stack.top();        //�s�X�̤W�誺����
        if(visited[top]==true)  //�Y���X�L�hpop�����L
        {
            stack.pop();
            continue;
        }
        cout<<top<<' ';
        visited[top]=true;      //mark�w���X�L
        stack.pop();            //pop���̤W����
        i=Adj[top].begin();     //iterator i�q�Ĥ@�Ӥ����}�l
        for(;i!=Adj[top].end();i++) //����end
        {
            if(!visited[*i])    //�Y�����X�L�hpush�istack
                stack.push(*i);
        }

    }
    cout<<endl;
}

void MyGraph::CC()
{
    visited=new bool[num_of_vertices];  //�����O�_���L
    fill(visited,visited+num_of_vertices,false);//��lvisited
    int num_component=0;                //number of component
    for(int i=0;i<num_of_vertices;i++)  //���M�C��vertices
    {
        if(!visited[i])                 //�Y�����X�L�h���X �C�@�����O�@��component
        {
            num_component++;
            cout<<"Component#"<<num_component<<": ";
            DFS(i);
            cout<<endl;
        }
    }
    delete [] visited;      //delete�ʺAarray
}
