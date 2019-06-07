#include <iostream>
#define Black 0
#define Red 1
using namespace std;
typedef struct any {
    int a; // a是下界
    int b; // b是上界
    int max;
} keytype;

typedef struct rbnode {
    int color;
    keytype content;
    struct rbnode *left;
    struct rbnode *right;
    struct rbnode *parent;
} node, brTree;

auto nil = new node;

node *get_node(keytype a) { //产生值为a的新节点，颜色为黑
    auto new_node = new node;
    new_node->content = a;
    new_node->right = new_node->left = new_node->parent = NULL;
    new_node->color = Black;
    return new_node;
}

int max(int a, int b) { return a > b ? a : b; }

void printnode(node *T) {
    if (T == nil) {
        // cout << "nil";
        return;
    }
    printf(" [color=%s,label=\"[%d,%d],max:%d\"];\n",
           T->color ? "Red" : "Black", T->content.a, T->content.b,
           T->content.max);
}

void printkey(node *T) {
    if (T == nil) {
        // cout << "nil";
        return;
    }
    cout << T->content.a;
}

void printTreecontent(brTree *T) {
    if (T == nil) {
        return;
    }
    printkey(T);
    printnode(T);

    if (T->left != nil) {
        printkey(T);
        cout << "->";
        printkey(T->left);
        if (T->right == nil) {
            cout << "[label=\"left\"]";
        }
        cout << ";" << endl;
    }
    if (T->right != nil) {
        printkey(T);
        cout << "->";
        printkey(T->right);
        if (T->left == nil) {
            cout << "[label=\"right\"]";
        }
        cout << ";" << endl;
    }

    printTreecontent(T->right);
    printTreecontent(T->left);
}

void printTree(brTree *T) { printTreecontent(T); }

void initTree(brTree *T) { //初始化树
    T->color = Black;
    T->left = T->right = NULL;
    T->content.a = -1;
    T->content.b = -1;
    T->content.max = -1;
}

void calmax(node *a) {
    int tmp = max(a->left->content.max, a->right->content.max);
    a->content.max = max(tmp, a->content.b);
}

void leftRotate(brTree *&T, node *x) {
    if (x->right == nil)
        return;
    auto y = x->right;
    if (y->left != nil)
        y->left->parent = x;
    x->right = y->left;
    y->parent = x->parent;
    y->left = x;
    if (x->parent == nil)
        T = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    x->parent = y;
    calmax(x);
    calmax(x->parent);
}

void rightRotate(brTree *&T, node *x) {
    if (x->left == nil)
        return;
    auto y = x->left;
    if (y->right != nil)
        y->right->parent = x;
    x->left = y->right;
    y->parent = x->parent;
    y->right = x;
    if (x->parent == nil)
        T = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    x->parent = y;
    calmax(x);
    calmax(x->parent);
}

int keytypecompare(keytype a, keytype b) {
    if (a.a < b.a)
        return -1;
    else if (a.a == b.a)
        return 0;
    else
        return 1;
}

int compare(node *a, node *b) { return keytypecompare(a->content, b->content); }

node *insert(brTree *&T, node *node_insert) { //按搜索树插入新节点，未调整颜色
    if (T == nil) {
        node_insert->parent = node_insert->left = node_insert->right = nil;
        T = node_insert;
        node_insert->content.max = node_insert->content.b;
        return T;
    }
    auto x = T;
    auto y = x->parent;
    while (x != nil) {
        if (compare(x, node_insert) < 0) {
            y = x;
            x = x->right;
        } else if (compare(x, node_insert) == 0)
            return x;
        else {
            y = x;
            x = x->left;
        }
    }
    if (compare(y, node_insert) < 0) {
        y->right = node_insert;
    } else
        y->left = node_insert;
    node_insert->left = node_insert->right = nil;
    node_insert->parent = y;
    node_insert->color = Red;
    node_insert->content.max = node_insert->content.b;
    auto z = node_insert;
    while (z->parent != nil) {
        if (z->parent->content.max < z->content.max)
            z->parent->content.max = z->content.max;
        z = z->parent;
    }
    return node_insert;
}

void Treeinsert(brTree *&T, keytype content) {
    auto z = insert(T, get_node(content));
    while (z->parent->color == Red) {
        if (z->parent == z->parent->parent->left) {
            auto y = z->parent->parent->right;
            if (y->color == Red) {
                z->parent->color = Black;
                y->color = Black;
                z->parent->parent->color = Red;
                z = z->parent->parent;
            }

            else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(T, z);
                }
                z->parent->color = Black;
                z->parent->parent->color = Red;
                rightRotate(T, z->parent->parent);
            }
        } else {
            auto y = z->parent->parent->left;
            if (y->color == Red) {
                z->parent->color = Black;
                y->color = Black;
                z->parent->parent->color = Red;
                z = z->parent->parent;
            }

            else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(T, z);
                }
                z->parent->color = Black;
                z->parent->parent->color = Red;
                leftRotate(T, z->parent->parent);
            }
        }
    }
    T->color = Black;
}

void transplant(brTree *&T, node *u, node *v) {
    if (u->parent == nil)
        T = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    v->parent = u->parent;
}

node *findnode(brTree *T, keytype a) {
    if (T == nil)
        return NULL;
    else if (keytypecompare(T->content, a) == 0)
        return T;
    else if (keytypecompare(T->content, a) > 0)
        return findnode(T->left, a);
    else
        return findnode(T->right, a);
}

node *minimun(node *z) {
    if (z == nil)
        return NULL;
    while (z->left != nil)
        z = z->left;
    return z;
}

void deletefix(brTree *&T, node *x) {
    // cout<<x->parent->content.a<<endl;
    while (x->parent != nil && x->color == Black) {
        if (x == x->parent->left) {
            auto w = x->parent->right;
            if (w->color == Red) {
                w->color = Black;
                x->parent->color = Red;
                leftRotate(T, x->parent);
                w = x->parent->right;
            }
            if (w->left->color == Black && w->right->color == Black) {
                w->color = Red;
                x = x->parent;
            } else {
                if (w->right->color == Black) {
                    w->left->color = Black;
                    w->color = Red;
                    rightRotate(T, w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = Black;
                w->right->color = Black;
                leftRotate(T, x->parent);
                x = T;
            }
        } else {
            auto w = x->parent->left;
            if (w->color == Red) {
                w->color = Black;
                x->parent->color = Red;
                leftRotate(T, x->parent);
                w = x->parent->left;
            }
            if (w->left->color == Black && w->right->color == Black) {
                w->color = Red;
                x = x->parent;
            } else {
                if (w->left->color == Black) {
                    w->right->color = Black;
                    w->color = Red;
                    rightRotate(T, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = Black;
                w->left->color = Black;
                leftRotate(T, x->parent);
                x = T;
            }
        }
    }
    x->color = Black;
}

void Treedelete(brTree *&T, keytype a) {
    auto z = findnode(T, a);
    if (z == NULL) {
        // cout<<"Not Find"<<endl;
        return;
    }
    auto y = z;

    int y_origin_color = y->color;
    //
    node *x = NULL;
    if (z->left == nil) {
        x = z->right;
        transplant(T, z, z->right);
    } else if (z->right == nil) {
        x = z->left;
        transplant(T, z, z->left);
    } else {
        y = minimun(z->right);
        y_origin_color = y->color;
        x = y->right;
        if (y->parent == z)
            x->parent = z;
        else {
            transplant(T, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(T, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    auto t = x->parent;
    while (t != nil) {
        calmax(t);
        t = t->parent;
    }
    if (y_origin_color == Black) {
        // cout<<y->parent->content.a<<endl;
        deletefix(T, x);
    }
}

int overlap(keytype a, keytype b) {
    if (a.a <= b.b && a.b >= b.a)
        return 1;
    else
        return 0;
}

node *interval_search(brTree *T, keytype a) {
    auto x = T;
    while (x != nil && !overlap(x->content, a)) {
        if (x->left != nil && x->left->content.max >= a.a)
            x = x->left;
        else
            x = x->right;
    }
    return x;
}

main() {
    auto T = nil;
    int num;
    initTree(T);
    keytype a;
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> a.a;
        cin >> a.b;
        Treeinsert(T, a);
    }
    a.a = 18;
    // Treedelete(T,a);
    a.a = 7;
    a.b = 10;
    auto tmp = interval_search(T, a);
    cout << "digraph graphname {" << endl;

    cout << "overlap";
    if (tmp == nil) {
        printf(" [color=Blue,label=\"nil\"];\n");
    } else
        printf(" [color=Blue,label=\"[%d,%d]\"];\n", tmp->content.a,
               tmp->content.b);
    // Treedelete(T, a);
    printTree(T);
    cout << endl << "}";
}
