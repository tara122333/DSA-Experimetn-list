#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node*left,*right;
}node;

node *create_Binary_Tree(node*);
node*insertion(node*,int);
node*deletion(node*,int);
node*pre_Order(node*);
node*in_Order(node*);
node*post_Order(node*);
node*find_Argument(node*,int ,node**,node**);
node*delet_A(node**,node*,node*);
node*delet_B(node**,node*,node*);
int total_Node(node*);
int external_Node(node*);
int internal_Node(node*);
int calculate_Height(node*);
node*largest_Element(node*);
node*smallest_Element(node*);
node*dispose_Tree(node*);
node*searching_Bst(node*,int);

int main()
{
    node *root;
    node*root1;
    root = create_Binary_Tree(root);
    int ch,data,count;
    // create a tree
    do
    {
        printf("\n1. Insertion \n");
        printf("2. Deletion \n");
        printf("3. Pre-Order Traversal \n");
        printf("4. In-Order Traversal \n");
        printf("5. Post-Order Traversal \n");
        printf("6. Searching a Value \n");
        printf("7. Total Node Count \n");
        printf("8. External Node Count\n");
        printf("9. Internal Node Count \n");
        printf("10. Calculate Height \n");
        printf("11. Largest Element \n");
        printf("12. Smallest Element \n");
        printf("13. Exit\n");
        printf("Please Enter your choice : ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter a value : ");
            scanf("%d",&data);
            root = insertion(root,data);
            break;

        case 2:
            printf("Enter a value you want to delet : ");
            scanf("%d",&data);
            root = deletion(root,data);
            break;

        case 3:
                pre_Order(root);
            break;

        case 4:
                in_Order(root);
            break;

        case 5:
                post_Order(root);
            break;

        case 6:
                printf("Enter a Value : ");
                scanf("%d",&data);
                root = searching_Bst(root,data);
                printf("Value is : %d\n",root->data);
            break;

        case 7:
                count = total_Node(root);
                printf("Total Node is %d \n",count);

            break;

        case 8:
                count = external_Node(root);
                printf("External Node is %d \n",count);
            break;

        case 9:
                count = internal_Node(root);
                printf("Internal Node is %d \n",count);
            break;

        case 10:
                count = calculate_Height(root);
                printf("Height is %d\n",count);
            break;

        case 11:
                root1 = largest_Element(root);
                printf("Largest Element is %d\n",root1->data);
            break;

        case 12:
                root1 = smallest_Element(root);
                printf("Smallest Element is %d\n",root1->data);
            break;

        case 13:
            printf("\nExit\n");
            break;

        default:
            printf("\nPlease Enter a valid value\n");
            break;
        }

    } while (ch!=13);

    //dispose Function

    return 0;
}
node *create_Binary_Tree(node*root){
    root = NULL;
    return root;
}
node*insertion(node*root,int val){
    node*ptr = (node*)malloc(sizeof(node));
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->data = val;
    if(root==NULL){
        root = ptr;
    }
    else{
        node*parent_ptr = NULL;
        node*nodeptr = root;
        while (nodeptr!=NULL)
        {
            parent_ptr = nodeptr;
            if(val<nodeptr->data){
                nodeptr = nodeptr->left;
            }
            else{
                nodeptr = nodeptr->right;
            }
        }
        if(val<parent_ptr->data){
            parent_ptr->left = ptr;
        }
        else{
            parent_ptr->right = ptr;
        }
    }
    return root;

}

node*find_Argument(node*tree,int val,node**loc,node**parent){
    node*ptr;
    node*save;
    if(tree==NULL){
        (*loc) = NULL;
        (*parent) = NULL;
        return (*loc);
    }
    else if(tree->data == val){
        (*loc) = tree;
        (*parent) = NULL;
        return (*loc); 
    }
    else if(tree->data>val){
        ptr = tree->left;
        save  = tree;
        // return ;
    }
    else{
        ptr = tree->right;
        save = tree;
        // return loc;
    }
    while (ptr!=NULL)
    {
        if(ptr->data == val){
            (*loc) = ptr;
            (*parent) = save;
            return (*loc);
        }
        if(val<ptr->data){
            save = ptr;
            ptr = ptr->left;
        }
        else{
            save = ptr;
            ptr = ptr->right;
        }
    }
    (*loc) = NULL;
    (*parent) = save;
    return (*loc);
    
}
node*delet_A(node**tree,node*loc,node*parent){
    node*child;
    if((loc->left==NULL)&&(loc->right==NULL)){
        child = NULL;
    }
    else if(loc->right !=NULL){
        child = loc->right;
    }
    else{
        child = loc->left;
    }
    if(parent != NULL){
        if(loc==parent->left){
            parent->left = child;
        }
        else{
            parent->right = child;
        }
    }
    else{
        (*tree) = child;
    }
    // return ;
}
node*delet_B(node**tree,node*loc,node*parent){
    node*save;
    node*ptr;
    ptr = loc->right;
    save = loc;
    while (ptr->left!=NULL)
    {
        save = ptr;
        ptr = ptr->left;
    }
    node*suc = ptr;
    node*parent_suc = save;
    delet_A(&tree,suc,parent_suc);
    if(parent!=NULL){
        if(loc==parent->left){
            parent->left = suc;
        }
        else{
            parent->right = suc;
        }
    }
    else{
        (*tree) = suc;
    }
    suc->left = loc->left;
    suc->right = loc->right;
    return (*tree);
}
node*deletion(node*root,int val){
    node*loc;
    node*parent;
    loc = find_Argument(root,val,&loc,&parent);
    if(loc == NULL){
        printf("\nValus is not Found\n");
        return root;
    }
    if((loc->right != NULL)&&(loc->left!=NULL)){
        root = delet_B(&root,loc,parent);
    }
    else{
        delet_A(&root,loc,parent);
    }
    return root;
}
node*pre_Order(node*root){
    if(root!=NULL){
        printf("==>> %d ",root->data);
        pre_Order(root->left);
        pre_Order(root->right);
    }
}
node*in_Order(node*root){
    if(root!=NULL){
        in_Order(root->left);
        printf("==>> %d ",root->data);
        in_Order(root->right);
    }
}
node*post_Order(node*root){
    if(root!=NULL){
        post_Order(root->left);
        post_Order(root->right);
        printf(" ==>> %d ",root->data);
    }
}
int total_Node(node*root){
    if(root==NULL)
    {
        return 0;
    }
    else{
        return (total_Node(root->left)+total_Node(root->right)+1);
    }
}
int external_Node(node*root){

    if(root==NULL)
    {
        return 0;
    }
    else
    {
        if((root->left==NULL)&&(root->right==NULL))
        {
            return 1;
        }
        else
            return (external_Node(root->left)+external_Node(root->right));
    }
}
int internal_Node(node*root){

    if((root==NULL)||(root->left==NULL && root->right==NULL))
    {
        return 0;
    }
    else
        return(internal_Node(root->left)+internal_Node(root->right)+1);
}
int calculate_Height(node*root){
    int left=1;
    int right=1;
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        left=calculate_Height(root->left);
        right=calculate_Height(root->right);
        if(left>=right)
        {
            return (left+1);
        }
        else
        {
            return (right+1);
        }
    }
}
node*largest_Element(node*root){
    if((root==NULL)||(root->right==NULL)){
        return root;
    }
    else{
       return largest_Element(root->right);
    }
}
node*smallest_Element(node*root){
    if((root==NULL)||(root->left==NULL)){
        return root;
    }
    else{
        return smallest_Element(root->left);
    }
}

node*searching_Bst(node*root, int val){

    if(root->data == val||(root==NULL))
    {
        return root;
    }
    else
    {
        if(val < root->data)
        {
            return searching_Bst(root->left,val);
        }
        else
        {
            return searching_Bst(root->right,val);
        }
    }
}
