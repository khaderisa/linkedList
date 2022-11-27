#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node {
    int Data;
    struct node* Next;
};

void DeleteList(struct node* L) {
    struct node *P, *temp;
    P = L->Next;
    L->Next = NULL;
    while (P != NULL) {
        temp = P->Next;
        free(P);
        P = temp;
    }
}
struct node* createNode(){
    struct node* temp; // declare a node
    temp = (struct node*)malloc(sizeof(struct node*)); // allocate memory using malloc()
    temp->Next = NULL;// make next point to NULL
    return temp;//return the new node
}
//void createNode2(struct node* temp){
//    //struct node* temp; // declare a node
//    temp = (struct node*)malloc(sizeof(struct node*)); // allocate memory using malloc()
//    temp->Next = NULL;// make next point to NULL
//    //return temp;//return the new node
//}
struct node* MakeEmpty(struct node* L){
    if(L != NULL){
        DeleteList(L);
    }
    L=(struct node*)malloc(sizeof(struct node));
    if(L==NULL)
        printf("out of memo\n");
    L->Next=NULL;
    printf("s");
    return L;
}
void InsertFirst(int X, struct node* P){
    struct node*temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->Data = X;
    temp->Next = P->Next;
    P->Next = temp;
}
int IsLast(struct node* P,struct node*L){
    return P->Next==NULL;
}
void InsertLast(int X, struct node* P){
    struct node*temp=P;
    struct node*t;
    while (temp->Next->Next!=NULL){
        temp=temp->Next;
    }
    t = (struct node*)malloc(sizeof(struct node));
    t->Data = X;
    temp->Next->Next = t;
    t->Next = NULL;
}
struct node* Insert(int X, struct node* P){
    struct node*temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->Data = X;
    temp->Next = P->Next;
    P->Next = temp;
}
int IsEmpty(struct node* L){
    return L->Next == NULL;
}
void PrintList(struct node* L){
    struct node* P = L;
    if(IsEmpty(L))
        printf("Empty list\n");
    else
    do{
        P=P->Next;
        printf("%d\t", P->Data);
    }while( !IsLast(P, L) );
    printf("\n");
}
void print (struct node* a){
    struct node*p=a;
    while (!IsLast(p,a)) {
        p=p->Next;
        printf("%d\t",p->Data);
    }
}
struct node* find (int key ,struct node* p){
    struct node* a;
    a=p->Next;
    while (a->Data != key) {
        a=a->Next;
        if(a==NULL)
            return NULL;
    }
    return a;
}
//struct node* Find(int X,struct node* L){
//    struct node* P;
//    P = L->Next;
//    while(P != NULL && P->Data != X)
//        P = P->Next;
//    return P;
//}
struct node* findPrevious (int key ,struct node* p){
    struct node* a;
    a=p;
    while (a->Next->Data != key) {
        a=a->Next;
        if(a->Next==NULL)
            return NULL;
    }
    return a;
}
void Delete (int key,struct node* l){
    struct node* p;
    p=l;
    while (p->Next->Data != key && p->Next!=NULL) {
        p=p->Next;
        if(p->Next==NULL)
            printf("not exist !");
    }
    if(p->Next->Data == key) {
        struct node*temp=p->Next;
        p->Next = p->Next->Next;
        free(temp);
    }
}
int sizeOfList(struct node* l){
    struct node* p=l;
    int count=0;
    while (!IsLast(p,l)){
        ++count;
        p=p->Next;
    }
    return count;
}
//////////////////////////////////////////////////////////
//doubly linked list
struct doublyNode{
    int Data;
    struct doublyNode* Next;
    struct doublyNode* Previous;
};
int IsEmptyDoubly(struct doublyNode* L){
    return L->Next == NULL;
}
int IsLastDoubly(struct doublyNode* P,struct doublyNode*L){
    return P->Next==NULL;
}
struct doublyNode* creatDoublyList(){
    struct doublyNode* L;
    L=(struct doublyNode*) malloc(sizeof (struct doublyNode*));
    L->Next=NULL;
    return L;
}
void insertDoubly(int x,struct doublyNode* a){
    struct doublyNode* p;
    p=(struct doublyNode*) malloc(sizeof (struct doublyNode*));
    if (a->Next!=NULL){
        p->Next=a->Next;
        a->Next->Previous=p;
        p->Previous=a;
        a->Next=p;
    }else{
        a->Next=p;
        p->Next=NULL;
        p->Previous=a;
    }
    p->Data=x;

}

void deleteDoublyList (struct doublyNode* l){
    struct doublyNode *P, *temp;
    P = l->Next;
    l->Next = NULL;
    while (P != NULL) {
        temp = P->Next;
        free(P);
        P = temp;
    }
}
void printDoublyList(struct doublyNode*l){
    if (l->Next==NULL)
        printf("no element!");
    else{
        struct doublyNode*p=l->Next;
        while (p != NULL) {
            printf("%d\t",p->Data);
            p=p->Next;
        }
    }
}
struct doublyNode* findDoubly(int key,struct doublyNode* l){
    struct doublyNode* p=l->Next;
    while (p->Data != key&&p!=NULL) {
        p=p->Next;
    }
    return p;
}
struct doublyNode* findPreviousDoubly(int key,struct doublyNode* l){
    struct doublyNode* p=l->Next;
    while (p->Data != key&&p!=NULL) {
        p=p->Next;
    }
    return p->Previous;
}
////////////////////////////////////////////////////////////////
//Circular Linked List
struct circularNode{
    int Data;
    struct circularNode* Next;
};
typedef struct circularNode* cirNode;
cirNode creatCircularNode(){
    cirNode p;
    p=(cirNode) malloc(sizeof(cirNode));
    p->Next=NULL;
    return p;
}
int isLast(cirNode p,cirNode L){
    return p->Next==L->Next;
}
int isEmpty(cirNode L){
    return L->Next==NULL;
}
void insertCircularNode(int x,cirNode L){
    cirNode p,temp;
    p= (cirNode)malloc(sizeof(cirNode));
    p->Data=x;
    temp=L->Next;
    if(isEmpty(L)){
        L->Next=p;
        p->Next=p;
    }
    else{
        while(!isLast(temp,L)){
            temp=temp->Next;
        }
        p->Next=L->Next;
        L->Next=p;
        temp->Next=L->Next;
    }
}
void printCircularList(cirNode L){
    cirNode p=L->Next;
    if(isEmpty(L))
        printf("no element");
    else{
        printf("%d\t",p->Data);
        while(p->Next!=L->Next){
            p=p->Next;
            printf("%d\t",p->Data);
        }
    }
}
void deleteCircularList(cirNode L){
    struct node *P, *temp, *last;
    P = L->Next;
    last=L->Next;
    while (!isLast(last,L)){
        last=last->Next;
    }
    L->Next = NULL;
    while (P != last) {
        temp = P->Next;
        free(P);
        P = temp;
        printf("gg");
    }
}
cirNode findCircularNode(int key,cirNode L){
    cirNode p=L->Next;
    while (p->Data != key) {
        if(isLast(p,L)){
            return NULL;
        }
        p=p->Next;
    }
    return p;
}
//////////////////////////////////////////////////////////////////
//doubly circular linked list
struct doublyCircularNode {
    int Data;
    struct doublyCircularNode* Next;
    struct doublyCircularNode* Previous;
};
typedef struct doublyCircularNode* dbCirNode;
dbCirNode creatDoublyCircularList(){
    dbCirNode L;
    L = (dbCirNode) malloc(sizeof(dbCirNode));
    L->Next=NULL;
    return L;
}
int isLastDbCir(dbCirNode p,dbCirNode l){
    return p->Next==l->Next;
}
void insetDoublyCircularNode(int Data,dbCirNode l){
    dbCirNode p;
    p=(dbCirNode) malloc(sizeof(dbCirNode));
    p->Data=Data;
    if (l->Next == NULL) {
        l->Next=p;
        p->Next=p;
        p->Previous=p;
    } else {
        dbCirNode temp=l->Next;
        while (!isLastDbCir(temp,l)){
            temp=temp->Next;
        }
        p->Next=l->Next;
        p->Previous=temp;
        temp->Next=p;
        l->Next->Previous=p;
        l->Next=p;
    }
}
int isEmptydbcir(dbCirNode l){
    return l->Next==NULL;
}
void printDoublyCircularList(dbCirNode l){
    dbCirNode p=l->Next;
    if (isEmptydbcir(l))
        printf("null");
    else{
        while (!isLastDbCir(p, l)) {
            printf("%d\t", p->Data);
            p=p->Next;
        }
        printf("%d", p->Data);
    }

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {

//    struct node* r;
//    createNode2(r);
//    InsertFirst(3, r);
//    PrintList(r);

//    struct node* a=createNode();
//    InsertFirst(3, a);
//    InsertFirst(33, a);
//    InsertFirst(35, a);
//    InsertFirst(8, a);
//    struct node*n1=Insert(1,a);
//    struct node*n2=Insert(2,n1);
//    struct node*n3=Insert(3,a);
//    InsertFirst(6, a);
//    InsertFirst(34, a);
//    InsertLast(45,a);
////    struct node*n4=Insert(4,n3);
////    Delete(33, a);
//    print(a);
//    printf("%d\n", sizeOfList(a));
//    DeleteList(a);
//    PrintList(a);
//    printf("%d", sizeOfList(a));

//    struct node* t= findPrevious(354,a);
//    if (t!=NULL)
//        printf("%d", t->Data);
//    else
//        printf("not exist!");
/////////////////////////////////////////

//    struct doublyNode*g=creatDoublyList();
//    insertDoubly(3, g);
//    insertDoubly(4, g);
////    insertDoubly(5, g);
////    insertDoubly(1, g);
//    struct doublyNode* i= findDoubly(3,g);
//    printf("%d",i->Data);
//    printDoublyList(g);
    //////////////////////////////////////////////
//    cirNode y=creatCircularNode();
//    insertCircularNode(4,y);
//    insertCircularNode(6,y);
//    insertCircularNode(5,y);
//    insertCircularNode(2,y);
//    printCircularList(y);
////    deleteCircularList(y);
//    cirNode o = findCircularNode(4, y);
//    if (o!=NULL)
//        printf("%d", o->Data);
//    else
//        printf("not exist!");
////    printCircularList(y);
////    printf("%d",y->Next->Data);
/////////////////////////////////////////////

    dbCirNode q=creatDoublyCircularList();
    insetDoublyCircularNode(1, q);
    insetDoublyCircularNode(5, q);
    printDoublyCircularList(q);
    return 0;
}
