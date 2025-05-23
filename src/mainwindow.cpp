#include "mainwindow.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *central = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout;

    label = new QLabel("Hello, World!", this);
    label->setAlignment(Qt::AlignCenter);

    layout->addWidget(label);
    central->setLayout(layout);
    setCentralWidget(central);
}

MainWindow::~MainWindow() {}
