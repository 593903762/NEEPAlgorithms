/**
* 平衡二叉树：仍然是一棵二叉查找树，在其基础上增加了“平衡”
**/

//定义
struct node {
    int v, height; //v为结点权值，height为当前子树高度
    node *lchild, *rchild; //左右孩子结点地址
};
//新建结点
node* newNode(int v) {
    node* Node = new node; //申请一个node型变量的地址空间
    Node->v = v; //结点权值为v
    Node->height = 1; //结点高度初始为1
    Node->lchild = Node->rchild = NULL; //初始状态下没有左右孩子
    return Node; //返回新建结点的地址
}
//获取以root为根结点的子树的当前高度
int getHeight(node* root) {
    if (root == NULL)
        return 0; //空结点高度为0
    return root->height;
}
//计算结点root的平衡因子
int getBalanceFactor(node* root) {
    //左子树高度减右子树高度
    return getHeight(root->lchild) - getHeight(root->rchild);
}
//更新结点root的高度
void updateHeight(node* root) {
    //max(左孩子的height, 右孩子的height) + 1
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

//基本操作
//查找
//search函数查找AVL树中数据域为x的结点
void search(node* root, int x) {
    if (root == NULL) {
        printf("search failed\n"); //空树，查找失败
        return;
    }
    if (x == root->v) {
        printf("%d\n", root->v); //查找成功，访问之
    } else if (x < root->v) {
        search(root->lchild, x); //如果x比根结点的数据域小，说明x在左子树
    } else {
        search(root->rchild, x); //如果x比根结点的数据域大，说明x在右子树
    }
}
//插入
//左旋（Left Rotation）
void L(node* &root) {
    node* temp = root->rchild; //root指向结点A，temp指向结点B
    root->rchild = temp->lchild; //步骤1
    temp->lchild = root; //步骤2
    updateHeight(root); //更新结点A的高度
    updateHeight(temp); //更新结点B的高度
    root = temp; //步骤3
}
//右旋（Right Rotation）
void R(node* &root) {
    node* temp = root->lchild; //root指向结点B，temp指向结点A
    root->lchild = temp->rchild; //步骤1
    temp->rchild = root; //步骤2
    updateHeight(root); //更新结点B的高度
    updateHeight(temp); //更新结点A的高度
    root = temp; //步骤3
}
//插入权值为v的结点
void insert(node* &root, int v) {
    if (root == NULL) {
        root = newNode(v); //到达空结点
        return;
    }
    if (v < root->v) {
        insert(root->lchild, v); //v比根结点的权值小，往左子树插入
        updateHeight(root); //更新树高
        if (getBalanceFactor(root) == 2) {
            if (getBalanceFactor(root->lchild) == 1) {
                //LL型
                R(root);
            } else if (getBalanceFactor(root->lchild) == -1) {
                //LR型
                L(root->lchild);
                R(root);
            }
        }
    } else {
        insert(root->rchild, v); //v比根结点的权值大，往右子树插入
        updateHeight(root); //更新树高
        if (getBalanceFactor(root) == -2) {
            if (getBalanceFactor(root->rchild) == -1) {
                //RR型
                L(root);
            } else if (getBalanceFactor(root->rchild) == 1) {
                //RL型
                R(root->rchild);
                L(root);
            }
        }
    }
}
//建立
node* Create(int data[], int n) {
    node* root = NULL; //新建空根结点root
    for (int i = 0; i < n; i++) {
        insert(root, data[i]); //将data[0]-data[n-1]插入AVL树中
    }
    return root; //返回根结点
}
