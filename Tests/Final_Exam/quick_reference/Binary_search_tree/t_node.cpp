#include "t_node.h"
template <typename T>
void Tnode <T>::PrintNodeInfo()
//function for printing node informatino
{
    cout<<"Value"<<endl;
    cout<<nodeValue<<endl;
    cout<<"Parent"<<endl;
    if(parent!=NULL)
    {
        cout<<parent->nodeValue<<endl;
    }
    else
        //check for null
    {
        cout<<"Null"<<endl;
    }
    cout<<"Left"<<endl;
    if(left!=NULL)
    {
        cout<<left->nodeValue<<endl;
    }
    else
    {
        cout<<"Null"<<endl;
    }
    cout<<"Right"<<endl;
    if(right!=NULL)
    {
        cout<<right->nodeValue<<endl;
    }
    else
    {
        cout<<"Null"<<endl;
    }
}
template <typename T>
Tnode <T> ::Tnode (const T& item,Tnode <T>*parentNode,Tnode <T>*leftNode,Tnode <T>*rightNode)
//constructor assignment
{
    nodeValue=item;
    //init value of node
    parent=parentNode;
    left=leftNode;
    right=rightNode;
}
