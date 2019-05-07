#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QPushButton>



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    //Barre de menu
    QMenuBar *bar_menu;
    //Différents menus présent dans la barre de menu
    QMenu *menu_fichier; QMenu *menu_edition;erer
};

#endif // MAINWINDOW_H
