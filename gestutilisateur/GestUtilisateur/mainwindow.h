#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int ligneSelectionne;
    QString sesGroupes;

private slots:
    void on_action_Quitter_triggered();

    void on_pushButtonAddGroup_clicked();

    void on_tableWidgetGroupe_2_clicked(const QModelIndex &index);

    void on_pushButtonDelGroup_clicked();

    void on_pushButtonAjouter_clicked();

    void ajoutConstruct();

    void chargeListeGroup();



    void on_tableWidgetUtilisateur_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
