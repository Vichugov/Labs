#include "tree.h"
#include "ui_tree.h"
#include <QPainter>
bool revers=1;
int b=0,r=0,index=0,radius=50,distance=300;
int number[6];
QChar s[64];
QPainter painter;
QPen pen;

struct Uzel{
    bool kras=0;
    int x=0,y=0;
    int lsize,rsize;
    Uzel *left, *right, *top;
};
Uzel *current=NULL, *first=NULL;

Tree::Tree(QWidget *parent): QMainWindow(parent), ui(new Ui::Tree)
{  
    ui->setupUi(this);
    ui->enterbutton->setShortcut(Qt::Key_Return);
    ui->inputline->hide();
    ui->textlabel->hide();
    ui->stextlabel->hide();
    ui->enterbutton->hide();
    ui->gotree->hide();
    ui->simvolbutton->hide();
    ui->simvolline->hide();
    ui->gosearchbutton->hide();
}

Tree::~Tree()
{
    delete ui;
}
int Step(int k){
    int result=1;
    for (int i=0;i<k;i++) result*=2;
    return result;
}
void Tree::Maker(){
    bool z=0;
    while(!z){
    if (current->lsize==current->rsize){
       if (current->left!=NULL){
           current->lsize++;
           current=current->left;
           distance/=2;
       }
       else {
           current->left= new Uzel;
           current->left->top=current;
           current->left->left=NULL;
           current->left->right=NULL;
           current->left->x=current->x-distance;
           current->left->y=current->y+100;
           current->left->lsize=0;
           current->left->rsize=0;
           current->lsize++;
           current=first;
           distance=300;
           z=1;
       }
    }
    else{
        if (current->right!=NULL){
            current->rsize++;
            current=current->right;
            distance/=2;
        }
        else {
            current->right= new Uzel;
            current->right->top=current;
            current->right->left=NULL;
            current->right->right=NULL;
            current->right->x=current->x+distance;
            current->right->y=current->y+100;
            current->right->lsize=0;
            current->right->rsize=0;
            current->rsize++;;
            current=first;
            distance=300;
            z=1;
        }
    }
    }
}
void Tree::Go(){
    for (int i=1;i<r;i++){
        Maker();
    }
}
void Tree::EndInput()
{
    ui->inputline->hide();
    ui->textlabel->hide();
    ui->enterbutton->hide();
    ui->gotree->show();
    first = new Uzel;
    first->x=600-radius/2; first->y=200; first->top=NULL; first->left=NULL; first->right=NULL; first->lsize=0; first->rsize=0;
    current=first;
    index=0;
}

void Tree::paintEvent(QPaintEvent *)
{ 
    if (b==1){
        int glubina=0;
        current=first;
        number[0]=0;number[1]=0;number[2]=0;number[3]=0;number[4]=0;number[5]=0;
        revers=!revers;
        pen.setColor(Qt::red);
        pen.setWidth(3);
        painter.begin(this);
        painter.setPen(pen);
        while (current!=NULL){
            if (current->left!=NULL&&current->left->kras==revers){
                current=current->left;
                glubina++;
            }
            else if (current->right!=NULL&&current->right->kras==revers){
                current=current->right;
                glubina++;
            }
            else{        
                current->kras=!revers;
                painter.drawEllipse(current->x,current->y,radius,radius);
                if (current->top!=NULL) painter.drawLine(current->x+radius/2,current->y,current->top->x+radius/2,current->top->y+radius);
                painter.drawText(current->x+radius/2,current->y+radius/2+2,s[Step(glubina)+number[glubina]-1]);
                number[glubina]++;
                glubina--;
                current=current->top;
            }
        }
        painter.end();
    }
    if (b==2){
        int indexer=1;
        current=first;
        revers=!revers;
        pen.setColor(Qt::red);
        pen.setWidth(3);
        painter.begin(this);
        painter.setPen(pen);
        while (current->left!=NULL) current=current->left;
        while (current!=NULL){
            if (current->left!=NULL&&current->left->kras==revers){
                current=current->left;
            }
            else if (current->kras==revers){
                current->kras=!revers;
                painter.drawEllipse(current->x,current->y,radius,radius);
                if (current->top!=NULL) painter.drawLine(current->x+radius/2,current->y,current->top->x+radius/2,current->top->y+radius);
                painter.drawText(current->x+radius/2,current->y+radius/2+2,s[indexer-1]);
                indexer++;
            }
            else if (current->right!=NULL&&current->right->kras==revers){
                current=current->right;
            }
            else{
                current=current->top;
            }
        }
        painter.end();
    }
}
void Tree::on_gotree_clicked()
{
    Go();
    b=1;
    this->repaint();
    ui->gotree->hide();
    ui->stextlabel->show();
    ui->simvolbutton->show();
    ui->simvolline->show();
    ui->gosearchbutton->show();
}

void Tree::on_enterbutton_clicked()
{
    if (index<r){
        if (ui->inputline->text().length()>0){
        s[index++]=*(ui->inputline->text().begin());
        ui->inputline->setText("");
        QString vvod = "Введите элемент номер " + QString::number(index+1) + ':';
        ui->textlabel->setText(vvod);
        ui->statusbar->showMessage("");
        }
        else ui->statusbar->showMessage("Нельзя вводить пустые значения! ");
        if (index==r) EndInput();
    }
}
void Tree::on_startbutton_clicked()
{
    if (ui->startline->text().toInt()>1&&ui->startline->text().toInt()<64){
        if (ui->startline->text().toInt()>31) radius=30;
    ui->startlabel->hide();
    ui->startbutton->hide();
    ui->startline->hide();
    r=ui->startline->text().toInt();
    ui->statusbar->showMessage("");
    ui->inputline->show();
    ui->textlabel->show();
    ui->enterbutton->show();
    }
    else{
        ui->statusbar->showMessage("Количество узлов должно являться числом, быть больше 1 и не превышать 63! ");
        ui->startline->setText("");
    }
}

void Tree::on_simvolbutton_clicked()
{
    int meet=0;
    if (ui->simvolline->text().length()!=1){
        ui->simvolline->setText("");
        ui->statusbar->showMessage("Должен быть введён символ! ");
    }
    else{
    ui->statusbar->showMessage("");
    QChar simvol = *(ui->simvolline->text().begin());
    for (int i=0;i<r;i++) if (s[i]==simvol) meet++;
    QString stroka = "Введённый символ встретился в дереве " + QString::number(meet) + " раз(а).";
    ui->stextlabel->setText(stroka);
    }
}

void Tree::on_gosearchbutton_clicked()
{
    ui->gosearchbutton->hide();
    QChar minsim;
    int minpos;
    for (int i=0;i<r;i++){
        minsim=s[i];
        minpos=i;
        for (int e=i;e<r;e++){
            if (s[e]<minsim){
                minpos=e;
                minsim=s[e];
            }
        }
        if (minsim<s[i]){
            s[minpos]=s[i];
            s[i]=minsim;
        }
    }
    b=2;
    this->repaint();
}
