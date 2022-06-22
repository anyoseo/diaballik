#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clickablelabel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(1200, 800));

    ui->listWidget->addItem("CLASSIQUE");
    ui->listWidget->addItem("VARIANTE");
    ui->listWidget->item(0)->setForeground(Qt::white);
    ui->listWidget->item(1)->setForeground(Qt::white);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    hide();
    if(ui->listWidget->currentItem()->text().toStdString()=="VARIANTE")
        gameWindow = new GameWindow(this, true);
    else
        gameWindow = new GameWindow(this);
    gameWindow->show();
    int result = gameWindow->exec();
    if(result==QDialog::Rejected){
        show();
    }
}
