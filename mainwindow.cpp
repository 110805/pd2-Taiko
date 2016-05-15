#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QKeyEvent>
#include <cstdlib>
#include <QTime>
#include <time.h>
QTimer *timer,*timer1,*timer2,*timer3,*timer4,*timer_R;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->timeword->hide();
    ui->countnumber->hide();
    ui->redsmall->hide();
    ui->bluesmall->hide();
    ui->scoreword->hide();
    ui->scoring->hide();
    ui->drum->hide();
    ui->restart->hide();
    ui->direct_red->hide();
    ui->direct_blue->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::time_timeout()
{
    if(count>0)
    {
        count--;
        ui->countnumber->setText(QString::number(count));
    }
    else
    {
        timer->stop();
        ui->bg1->hide();
        ui->bg2->hide();
        ui->timeword->hide();
        ui->countnumber->hide();
        ui->redsmall->hide();
        ui->bluesmall->hide();
        ui->redsmall2->hide();
        ui->bluesmall2->hide();
        ui->drum->hide();
        ui->restart->show();
        ui->exit->show();
        ui->direct_red->hide();
        ui->direct_blue->hide();
        ui->scoreword->move(130,70);
        ui->scoring->move(190,80);
    }
}

void MainWindow::on_start_clicked()
{
    ui->bg1->hide();
    ui->start->hide();
    ui->exit->hide();
    ui->timeword->show();
    ui->countnumber->show();
    ui->redsmall->show();
    ui->bluesmall->show();
    ui->scoreword->show();
    ui->scoring->show();
    ui->drum->show();
    ui->direct_red->show();
    ui->direct_blue->show();
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(time_timeout()));
    timer->start(1000);
    timer1=new QTimer(this);
    connect(timer1,SIGNAL(timeout()),this,SLOT(moving_red()));
    timer2=new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(moving_blue()));
    timer3=new QTimer(this);
    connect(timer3,SIGNAL(timeout()),this,SLOT(moving_red2()));
    timer4=new QTimer(this);
    connect(timer4,SIGNAL(timeout()),this,SLOT(moving_blue2()));
    timer_R=new QTimer(this);
    connect(timer_R,SIGNAL(timeout()),this,SLOT(generating()));
    timer_R->start(2000);
}

void MainWindow::on_exit_clicked()
{
    close();
}

void MainWindow::moving_red()
{
    if(ui->redsmall->x()>=0)
    {
        ui->redsmall->move(QPoint(ui->redsmall->x()-1,60));
    }
    else
    {
        timer1->stop();
        ui->redsmall->setGeometry(400,60,47,41);
    }
}

void MainWindow::moving_red2()
{
    if(ui->redsmall2->x()>=0)
    {
        ui->redsmall2->move(QPoint(ui->redsmall2->x()-1,60));
    }
    else
    {
        timer3->stop();
        ui->redsmall2->setGeometry(480,60,47,41);
    }
}

void MainWindow::moving_blue()
{
    if(ui->bluesmall->x()>=0)
    {
        ui->bluesmall->move(QPoint(ui->bluesmall->x()-1,60));
    }
    else
    {
        timer2->stop();
        ui->bluesmall->setGeometry(420,60,47,41);
    }
}

void MainWindow::moving_blue2()
{
    if(ui->bluesmall2->x()>=0)
    {
        ui->bluesmall2->move(QPoint(ui->bluesmall2->x()-1,60));
    }
    else
    {
        timer4->stop();
        ui->bluesmall2->setGeometry(450,60,47,41);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_J&&(ui->redsmall->x()-ui->drum->x()<30)&&(ui->redsmall->x()-ui->drum->x()>-20))
    {
        ui->redsmall->setGeometry(400,60,47,41);
        score++;
        ui->scoring->setText(QString::number(score));
        event->accept();
    }
    if(event->key()==Qt::Key_J&&(ui->redsmall2->x()-ui->drum->x()<30)&&(ui->redsmall2->x()-ui->drum->x()>-20))
    {
        ui->redsmall2->setGeometry(480,60,47,41);
        score++;
        ui->scoring->setText(QString::number(score));
        event->accept();
    }
    if(event->key()==Qt::Key_K&&(ui->bluesmall->x()-ui->drum->x()<30)&&(ui->bluesmall->x()-ui->drum->x()>-20))
    {
        ui->bluesmall->setGeometry(420,60,47,41);
        score++;
        ui->scoring->setText(QString::number(score));
        event->accept();
    }
    if(event->key()==Qt::Key_K&&(ui->bluesmall2->x()-ui->drum->x()<30)&&(ui->bluesmall2->x()-ui->drum->x()>-20))
    {
        ui->bluesmall2->setGeometry(450,60,47,41);
        score++;
        ui->scoring->setText(QString::number(score));
        event->accept();
    }


}

void MainWindow::generating()
{
    srand(time(NULL));
    r=rand()%4+1;
    if(r==1)
    {
        timer1->start(4);
    }
    if(r==2)
    {
        timer2->start(4);
    }
    if(r==3)
    {
        timer3->start(4);
    }
    if(r==4)
    {
        timer4->start(4);
    }
}

void MainWindow::on_restart_clicked()
{
    ui->bg1->hide();
    ui->bg2->show();
    ui->start->hide();
    ui->restart->hide();
    ui->exit->hide();
    ui->timeword->show();
    ui->direct_red->show();
    ui->direct_blue->show();
    count=30;
    ui->countnumber->show();
    ui->redsmall->setGeometry(400,60,47,41);
    ui->redsmall->show();
    ui->redsmall2->setGeometry(480,60,47,41);
    ui->redsmall2->show();
    ui->bluesmall->setGeometry(420,60,47,41);
    ui->bluesmall->show();
    ui->bluesmall2->setGeometry(450,60,47,41);
    ui->bluesmall2->show();
    ui->scoreword->move(130,210);
    ui->scoreword->show();
    score=0;
    ui->scoring->move(190,220);
    ui->scoring->show();
    ui->drum->show();
    timer->start(1000);
    timer_R->start(2000);
}
