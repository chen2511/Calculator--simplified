#include "mainwindow.h"
#include <QPushButton>
#include <QStack>
#include <QTextEdit>
#include <QDebug>

#include "floatnumber.h"

typedef struct node _tNode;
#define NUM_OF_NUMBER 20
#define KIND_NUMBER 0
#define KIND_OPERATOR 1

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //初始化
    s = "";
    resize(510,510);
    setWindowTitle("计算器");

    //设置按钮,指定父对象
    QPushButton *button_1 = new QPushButton(this);
    QPushButton *button_2 = new QPushButton(this);
    QPushButton *button_3 = new QPushButton(this);
    QPushButton *button_4 = new QPushButton(this);
    QPushButton *button_5 = new QPushButton(this);
    QPushButton *button_6 = new QPushButton(this);
    QPushButton *button_7 = new QPushButton(this);
    QPushButton *button_8 = new QPushButton(this);
    QPushButton *button_9 = new QPushButton(this);
    QPushButton *button_0 = new QPushButton(this);
    QPushButton *button_add = new QPushButton(this);
    QPushButton *button_dec = new QPushButton(this);
    QPushButton *button_mul = new QPushButton(this);
    QPushButton *button_div = new QPushButton(this);
    QPushButton *button_clear = new QPushButton(this);
    QPushButton *button_equal = new QPushButton(this);
    QPushButton *button_point = new QPushButton(this);
    QPushButton *button_left = new QPushButton(this);
    QPushButton *button_right = new QPushButton(this);
    QPushButton *button_delete = new QPushButton(this);

    button_0->setText("0");
    button_1->setText("1");
    button_2->setText("2");
    button_3->setText("3");
    button_4->setText("4");
    button_5->setText("5");
    button_6->setText("6");
    button_7->setText("7");
    button_8->setText("8");
    button_9->setText("9");
    button_add->setText("+");
    button_dec->setText("-");
    button_mul->setText("*");
    button_div->setText("/");
    button_clear->setText("CE");
    button_equal->setText("=");
    button_point->setText(".");
    button_left->setText("(");
    button_right->setText(")");
    button_delete->setText("Del");

    //设置显示窗口

    QTextEdit *text = new QTextEdit(this);
    text->resize(490,90);
    text->move(10,10);

    //布局
    button_0->resize(90,90);
    button_0->move(10,110);

    button_1->resize(90,90);
    button_1->move(110,110);

    button_2->resize(90,90);
    button_2->move(210,110);

    button_3->resize(90,90);
    button_3->move(310,110);

    button_4->resize(90,90);
    button_4->move(10,210);

    button_5->resize(90,90);
    button_5->move(110,210);

    button_6->resize(90,90);
    button_6->move(210,210);

    button_7->resize(90,90);
    button_7->move(310,210);

    button_8->resize(90,90);
    button_8->move(10,310);

    button_9->resize(90,90);
    button_9->move(110,310);

    button_add->resize(90,90);
    button_add->move(210,310);

    button_dec->resize(90,90);
    button_dec->move(310,310);

    button_mul->resize(90,90);
    button_mul->move(10,410);

    button_div->resize(90,90);
    button_div->move(110,410);

    button_clear->resize(90,90);
    button_clear->move(210,410);

    button_equal->resize(90,90);
    button_equal->move(310,410);

    button_left->resize(90,90);
    button_left->move(410,110);

    button_right->resize(90,90);
    button_right->move(410,210);

    button_point->resize(90,90);
    button_point->move(410,310);

    button_delete->resize(90,90);
    button_delete->move(410,410);
    //连接、处理信号,lambda表达式
    connect(button_0,&QPushButton::clicked,
            [=]()
            {
                //button_0->setText("123");
                s+="0";
                text->setText(s);
            }
            );
    connect(button_1,&QPushButton::clicked,
            [=]()
            {
                s+="1";
                text->setText(s);
            }
            );
    connect(button_2,&QPushButton::clicked,
            [=]()
            {
                s+="2";
                text->setText(s);
            }
            );
    connect(button_3,&QPushButton::clicked,
            [=]()
            {
                s+="3";
                text->setText(s);
            }
            );
    connect(button_4,&QPushButton::clicked,
            [=]()
            {
                s+="4";
                text->setText(s);
            }
            );
    connect(button_5,&QPushButton::clicked,
            [=]()
            {
                s+="5";
                text->setText(s);
            }
            );
    connect(button_6,&QPushButton::clicked,
            [=]()
            {
                s+="6";
                text->setText(s);
            }
            );
    connect(button_7,&QPushButton::clicked,
            [=]()
            {
                s+="7";
                text->setText(s);
            }
            );
    connect(button_8,&QPushButton::clicked,
            [=]()
            {
                s+="8";
                text->setText(s);
            }
            );
    connect(button_9,&QPushButton::clicked,
            [=]()
            {
                s+="9";
                text->setText(s);
            }
            );
    connect(button_add,&QPushButton::clicked,
            [=]()
            {
                s+="+";
                text->setText(s);
            }
            );
    connect(button_dec,&QPushButton::clicked,
            [=]()
            {
                s+="-";
                text->setText(s);
            }
            );
    connect(button_mul,&QPushButton::clicked,
            [=]()
            {
                s+="*";
                text->setText(s);
            }
            );
    connect(button_div,&QPushButton::clicked,
            [=]()
            {
                s+="/";
                text->setText(s);
            }
            );
    connect(button_clear,&QPushButton::clicked,
            [=]()
            {
                s="";
                text->setText(s);
            }
            );
    connect(button_left,&QPushButton::clicked,
            [=]()
            {
                s+="(";
                text->setText(s);
            }
            );
    connect(button_right,&QPushButton::clicked,
            [=]()
            {
                s+=")";
                text->setText(s);
            }
            );
    connect(button_point,&QPushButton::clicked,
            [=]()
            {
                s+=".";
                text->setText(s);
            }
            );
    connect(button_delete,&QPushButton::clicked,
            [=]()
            {
                s=s.left(s.length()-1);
                text->setText(s);
            }
            );
//    connect(button_equal,&QPushButton::clicked,
//            this,
//            &MainWindow::calculate
//            );
    connect(button_equal,&QPushButton::clicked,
            [=]()
            {
        MainWindow::calculate();
                text->setText(s);
            }
            );

    //槽函数，由于使用lambda表达式简便书写，多数实现

}

MainWindow::~MainWindow()
{

}

void MainWindow::calculate()
{
    //qDebug() << "Ready";
    //QString _s;
    //qDebug() << s[0];
    _tNode Node[NUM_OF_NUMBER];
    double num1=0;
    int len=s.length();
    int i=0;            //字符串位置
    int num_of_point=0; //小数点个数
    int num_or_op=0;    //浮点数和操作符的个数
    int isfloat=0;      //小数点
    while(i<len){
        if((s[i]>='0'&&s[i]<='9')){
            if(!isfloat){   //整数部分
                num1=num1*10+(s[i].toLatin1()-'0');
                ++i;
            }
            else{       //小数部分
                double per=1;
                for(int k=0;k<num_of_point;k++)
                    per*=0.1;
                num1+=(s[i].toLatin1()-'0')*per;
                num_of_point++;
                ++i;
            }
        }
        else if(s[i].toLatin1()=='.'){     //读到小数点
            isfloat=1;
            num_of_point=1;
            i++;
        }
        else{       //读到操作符
            if(num1){
                Node[num_or_op].flag=KIND_NUMBER;
                Node[num_or_op].num.a=num1;
                num1=0;
                ++num_or_op;
                isfloat=0;
                num_of_point=0;
            }

            Node[num_or_op].flag=KIND_OPERATOR;
            Node[num_or_op].num.op=s[i].toLatin1();
            ++num_or_op;

            ++i;
        }
    }
    if(num1){
        Node[num_or_op].flag=KIND_NUMBER;
        Node[num_or_op].num.a=num1;
        ++num_or_op;
        //qDebug() << num1;

        num1=0;
    }

    //qDebug() << num_or_op;

//    for(int i=0;i<=num_or_op;i++)
//        if(Node[i].flag)
//            qDebug() << Node[i].num.op;
//        else
//            qDebug() << Node[i].num.a;

    //以上是转换

    //以下是计算
    QStack<_tNode> pNode;
    _tNode _Node[NUM_OF_NUMBER];
    int j = 0;
    for(int i = 0; i < num_or_op;){
        if(Node[i].flag){//符号
            if(pNode.isEmpty())
                pNode.push_back(Node[i++]);
            else{
                _tNode tem=pNode.top();
                int ret=process(tem.num.op,Node[i].num.op);
                switch (ret) {
                case -1:
                    pNode.push_back(Node[i++]);
                    break;
                case 1:
                    _Node[j++]=pNode.top();
                    pNode.pop();
                    //pNode.push_back(Node[i]);
                    break;
                default:
                    pNode.pop();
                    i++;
                    break;
                }
            }
        }
        else{
            _Node[j++]=Node[i++];
        }
    }
    for(;!pNode.isEmpty();){
        _tNode tem=pNode.top();
        if(tem.num.op != '('&& tem.num.op != ')')
            _Node[j++]=tem;
        pNode.pop();
    }

//    for(int i=0;i<=j;i++)
//        if(_Node[i].flag)
//            qDebug() << _Node[i].num.op;
//        else
//            qDebug() << _Node[i].num.a;

    //具体计算过程：
    QStack<double> last;
    double d1,d2;
    for(int i = 0; i < j; i++){
        if(_Node[i].flag){//操作符

            d2=last.top();
            last.pop();
            d1=last.top();
            last.pop();
            switch (_Node[i].num.op) {
            case '+':
                d1+=d2;
                break;
            case '-':
                d1-=d2;
                break;
            case '*':
                d1*=d2;
                break;
            case '/':
                d1/=d2;
                break;
            default:
                break;
            }
            last.push_back(d1);
        }
        else{
            last.push_back(_Node[i].num.a);
        }
    }
    qDebug() << d1;

    s += '=';
    s += QString::number(d1);
}

int MainWindow::process(char a, char b)
{
    char aim[7][8] = { { ">><<<>>" },{ ">><<<>>" },{ ">>>><>>" },{ ">>>><>>" },{ "<<<<<=1" },{ ">>>>1>>" },{ "<<<<<1=" } };
    char sta[7] = { '+','-','*','/','(',')','#' };
    char _result;
    int i, pa, pb;
    for (i = 0; i<6; i++) {
        if (a == sta[i])pa = i;
        if (b == sta[i])pb = i;
    }
    _result = aim[pa][pb];
    if (_result == '>')return 1;
    else if (_result == '<')return -1;
    else return 0;
}
