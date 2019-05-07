#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //Creation de la barre de menu
    bar_menu = new QMenuBar(this);

    menu_fichier = bar_menu()->addMenu("Fichier");
    menu_edition = QMenu("Edition");




}

MainWindow::~MainWindow()
{

}
