/**
* 树与二叉树
**/

//二叉树的存储结构
struct node {
    typename data; //数据域
    node* lchild; //指向左子树根结点的指针
    node* rchild; //指向右子树根结点的指针
};
node* root = NULL;
//生成一个新结点，v为结点权值
node* newNode(int v) {
    node* Node = new node; //申请一个node型变量的地址空间
    Node->data = v; //结点权值为v
    Node->lchild = Node->rchild = NULL; //初始状态下没有左右孩子
    return Node; //返回新建结点的地址
}

//二叉树结点的查找、修改
void search(node* root, int x, int newdata) {
    if (root == NULL) {
        return; //空树，死胡同（递归边界）
    }
    if (root->data == x) {
        root->data = newdata; //找到数据域为x的结点，把它修改成newdata
    }
    search(root->lchild, x, newdata); //往左子树搜索x（递归式）
    search(root->rchild, x, newdata); //往右子树搜索x（递归式）
}

//二叉树结点的插入
//insert函数将在二叉树中插入一个数据域为x的新结点
//注意根结点指针root要使用引用，否则插入不会成功
void insert(node* &root, int x) {
    //空树，说明查找失败，也即插入位置（递归边界）
    if (root == NULL) {
        root = newNode(x);
        return;
    }
    if (由二叉树的性质，x应该插在左子树) {
        insert(root->lchild, x); //往左子树搜索（递归式）
    } else {
        insert(root->rchild, x); //往右子树搜索（递归式）
    }
}

//二叉树的创建
node* Create(int data[], int n) {
    node* root = NULL; //新建空根结点root
    for (int i = 0; i < n; i++) {
        insert(root, data[i]); //将data[0]-data[n-1]插入二叉树中
    }
    return root; //返回根结点
}
