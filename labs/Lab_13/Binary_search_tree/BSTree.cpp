template <typename T>
void BSTree<T>::insert(Tnode<T>* &r,const T & item)
//function to insert node into the binary tree
{
    Tnode <T>*curr=r;
    Tnode <T>* newNode=new Tnode <T>(item);
    Tnode<T>* temp=NULL;
    //init

    while (curr!=NULL)
    {
        temp=curr;
        if (newNode->nodeValue<curr->nodeValue)
        {
            curr=curr->left;
            //set to left child
        }
        else
        {
            curr=curr->right;
        }
        //set parent to temp
    }
    newNode->parent=temp;
    if (temp==NULL)
    {
        root=newNode;
    }
    else if(newNode->nodeValue<temp->nodeValue)
    {
        temp->left=newNode;
    }
    else
    {
        temp->right=newNode;
    }
}
template <typename T>
void BSTree<T>::Delete(Tnode<T>* &r,const T & item)
//delete function derived from your pseduocode
{
    Tnode<T> *curr=r;
    Tnode<T> *x=NULL;
    Tnode<T> *y=NULL;
    Tnode<T> *z=Search(curr,item);
    //*******
    if (z->left==NULL||z->right==NULL)
    {
        y=z;
    }
    else
    {
        y=Tree_succesor(z);
    }
    if(y->left!=NULL)
    {
        x=y->left;
    }
    else
    {
        x=y->right;
    }
    if (x!=NULL)
    {
        x->parent=y->parent;
    }
    if (y->parent==NULL)
    {
        r=x;
    }
    else if(y==y->parent->left)
    {
        y->parent->left=x;
    }
    else
    {
        y->parent->right=x;
    }
    if(y!=z)
    {
        z->nodeValue=y->nodeValue;
    }
    delete y;
}

template <typename T>
Tnode<T>* BSTree<T>::getRoot()
{
    return root;
}

//make root = null
template <typename T>
BSTree<T>::~BSTree()
{
    if (root==NULL){
            //avoid an error if there is somehow a NULL root
        return;
    }
    while (root->left!=NULL &&root->right!=NULL)
    {
        if (root->left!=NULL)
        {
            Delete(root,root->left->nodeValue);

        }
        if (root->right!=NULL)
        {
            Delete(root,root->right->nodeValue);
        }
    }
    delete root;
    //call destructor
}
template <typename T>
void BSTree<T>::BSTInsert (const T & item)
{
    insert(root,item);


}

