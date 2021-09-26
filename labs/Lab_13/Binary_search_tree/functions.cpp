#include <iostream>
#include "BSTree.h"
using namespace std;


template <typename T>
void InOrder (Tnode<T> *r)
//do inorder tragversal
{
    Tnode <T>*curr=r;
    if (curr!=NULL)
    {
        InOrder(curr->left);
        cout<<curr->nodeValue<<" ";
        InOrder(curr->right);
    }

    //do recursion
}
template <typename T>
void PreOrder (Tnode<T> *r)
//do preorder traversal
{
    Tnode <T>*curr=r;
    if (curr!=NULL)
    {
        cout<<curr->nodeValue<<" ";
        PreOrder(curr->left);
        PreOrder(curr->right);
        //do recursion
    }
}
template <typename T>
void PostOrder (Tnode<T> *r)
//do postorder traversal
{
    Tnode <T>*curr=r;
    if (curr!=NULL)
    {
        PostOrder(curr->left);
        PostOrder(curr->right);
        cout<<curr->nodeValue<<" ";
    }
    //do recursion
}
template <typename T>
Tnode<T> * Search (Tnode<T> *r, const T &item)
//do search of node
{
    //do recursive search function
    Tnode<T> *x=r;
    if (x==NULL||item==x->nodeValue)
    {
        return x;
    }
    if (item<x->nodeValue)
    {
        return Search(x->left,item);
    }
    else
    {
        return Search(x->right,item);
    }
}
template <typename T>
Tnode<T> * SearchMax (Tnode<T> *r)
//finds largest value in tree
{
    if(r==NULL)
    {
        return 0;
    }
    Tnode<T> *curr=r;
    while(curr->right!=NULL)
        //goes to right recursively
    {
        curr=curr->right;
    }
    return(curr);
}
template <typename T>
Tnode<T> * SearchMin (Tnode<T> *r)
//finds smallest value in tree
{
    if(r==NULL)
    {
        return NULL;
    }
    Tnode<T> *curr=r;
    while(curr->left!=NULL)
        //goes to left recursively
    {

        curr=curr->left;
    }
    return(curr);
}
template <typename T>
int countLeaves (Tnode<T> *  r)
{
    Tnode<T> *curr=r;
    if (r==NULL)
        //if the root is null then there is nothing
    {
        return 0;
    }
    if ((curr->left==NULL)&&(curr->right==NULL))
    {
        //if left and right are both null then this is a leaf
        return 1;
    }
    else
    {
        //do recursion
        int count=countLeaves(r->left)+countLeaves(curr->right);
        return count;
    }
}
template <typename T>
Tnode<T> * Tree_succesor(Tnode<T> *r)
//name successor in case of root deletion
{
    //find tree sucessor
    Tnode<T> *x=r;
    Tnode<T> *y=NULL;
    if (x->right!=NULL)
    {
        return SearchMin(x->right);
    }
    else
    {
        y=r->parent;
    }
    while(y!=NULL && x==y->right)
    {
        x=y;
        y=y->parent;
    }
    return y;
}
template <typename T>
void menu(BSTree<T> bt)
//display the menu interface
{
    bool done=false;
    int choice;
    int sel;
    int number;
    while (done==false)
        //init
    {
        sel=-1;
        cout<<endl<<"Enter Your Choice"<<endl;
        cout<<"1: Insert 10 random numbers"<<endl<<"2: Traverse the tree"<<endl
            <<"3: Search and Print Node"<<endl<<"4: Show Smallest Value"<<endl
            <<"5: Show Largest Value"<<endl<<"6: Show number of leaves"<<endl
            <<"7: Exit The Program"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            //Insert 10 random numbers
            for( int i=0; i<10; i++)
            {
                int num=rand()%100+1;
                if( Search (bt.getRoot(),num)==NULL)
                {
                    bt.BSTInsert(num);
                }
                else
                {
                    //make sure no numbers are skipped
                    i--;
                }
            }
            break;
        case 2:
            //Tree Traversal
            cout<<"1: Preorder"<<endl<<"2: Inorder"<<endl<<"3: PostOrder"<<endl;
            while (sel<0||sel>3)
            {
                cin>>sel;
            }
            switch (sel)
            {
            case 1:
                //preorder
                PreOrder(bt.getRoot());
                break;
            case 2:
                InOrder(bt.getRoot());
                break;
            case 3:
                PostOrder(bt.getRoot());
                break;
            }
            cout<<endl;
            break;
        case 3:
            //Node Search
            cout<<"Enter the value you would like to search for"<<endl;
            cin>>number;
            if (Search(bt.getRoot(),number)!=NULL)
            {
                Search(bt.getRoot(),number)->PrintNodeInfo();
            }
            else
            {
                cout<<"This value is not in the tree"<<endl;
            }
            break;
        case 4:
            //Smallest
            cout<<"Smallest Value"<<endl<<
                SearchMin(bt.getRoot())->nodeValue<<endl;
            break;
        case 5:
            //largest
            cout<<"Largest Value"<<endl<<
                SearchMax(bt.getRoot())->nodeValue<<endl;
            break;
        case 6:
            //count leaves
            cout<<"Number of Leaves:"<<endl<<countLeaves(bt.getRoot())<<endl;
            break;
        case 7:
            //exit the program
            done=true;
            break;
        }
    }
}
