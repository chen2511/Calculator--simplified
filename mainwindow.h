#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QStack>
#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void calculate();
    int process(char a, char b);

private:
    QString s;
    //QStack<double> num;
    //stack<char> operation;
};

#endif // MAINWINDOW_H
