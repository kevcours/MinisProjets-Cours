#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ajoutConstruct();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_Quitter_triggered()
{
    //fermer l'appli

    this->close();
}

void MainWindow::on_pushButtonAddGroup_clicked()
{
    //variable qui compte le nombre de ligne et de verification
    int verif=0;
    int NbLigne=ui->tableWidgetGroupe_2->rowCount();

    // ajouter une ligne aux tableaux
   if(ui->spinBoxNumGroup->text()!="" && ui->lineEditNomGroupe->text()!="")
   {
       for(int i=0 ; i<NbLigne ; i++)
       {
           if(ui->spinBoxNumGroup->text()==ui->tableWidgetGroupe_2->item(i,0)->text() || ui->lineEditNomGroupe->text()==ui->tableWidgetGroupe_2->item(i,1)->text())
           {
               verif++;
           }
       }
       if(verif==0)
       {

           ui->tableWidgetGroupe_2->setRowCount(NbLigne+1);

           // ajout des valeur renseigne au tableau

           ui->tableWidgetGroupe_2->setItem(NbLigne,0,new QTableWidgetItem(ui->spinBoxNumGroup->text())) ;
           ui->tableWidgetGroupe_2->setItem(NbLigne,1,new QTableWidgetItem(ui->lineEditNomGroupe->text())) ;
           ui->tableWidgetGroupe_2->setItem(NbLigne,2,new QTableWidgetItem(ui->lineEditDescGroupe->text())) ;
           chargeListeGroup();


           // Vider les line edit

           ui->spinBoxNumGroup->clear();
           ui->lineEditNomGroupe->clear();
           ui->lineEditDescGroupe->clear();
       }
       else
       {
           QMessageBox::warning(this,"Erreur","Nom de groupe ou Numero de groupe deja existant");
       }
   }
   else

       //si les champs sont vides
       QMessageBox::warning(this,"Attention","Certaine donnée sont incomplete");
   }


void MainWindow::on_tableWidgetGroupe_2_clicked(const QModelIndex &index)
{
    //Mise a jour de la ligne Selectionnée

    ligneSelectionne=index.row();

    // Allimentation du formulaire grace au clique sur le tableau

    ui->spinBoxNumGroup->setValue(ui->tableWidgetGroupe_2->item(ligneSelectionne,0)->text().toInt());
    ui->lineEditNomGroupe->setText(ui->tableWidgetGroupe_2->item(ligneSelectionne,1)->text());
    ui->lineEditDescGroupe->setText(ui->tableWidgetGroupe_2->item(ligneSelectionne,2)->text());

}

void MainWindow::on_pushButtonDelGroup_clicked()
{
    //Suppression des lignes selectionnées

    ui->tableWidgetGroupe_2->removeRow(ligneSelectionne);
    chargeListeGroup();

    // Vider les line edit

    ui->spinBoxNumGroup->clear();
    ui->lineEditNomGroupe->clear();
    ui->lineEditDescGroupe->clear();

}

void MainWindow::on_pushButtonAjouter_clicked()
{
     int NbLigne=ui->tableWidgetUtilisateur->rowCount();




     // ajout des valeur au tableau des utilisateurs
     if(ui->lineEditNom->text()!="" && ui->lineEditPrenom->text()!="" && ui->lineEditLogin->text()!="" && ui->lineEditMdp->text()!="" && ui->lineEditConfMdp->text()!="" && ui->lineEditMail->text()!="")
     {
         if(ui->lineEditConfMdp->text()==ui->lineEditMdp->text())
         {
             //ajout de ligne au tableau utilisateur
             ui->tableWidgetUtilisateur->setRowCount(NbLigne+1);
             ui->tableWidgetUtilisateur->setItem(NbLigne,0,new QTableWidgetItem(ui->lineEditNom->text())) ;
             ui->tableWidgetUtilisateur->setItem(NbLigne,1,new QTableWidgetItem(ui->lineEditPrenom->text())) ;
             ui->tableWidgetUtilisateur->setItem(NbLigne,2,new QTableWidgetItem(ui->lineEditMail->text())) ;
             QStringList listeDesGroupesSelectionnes;
             for(int noLigne=0;noLigne<ui->listWidgetGroup->count();noLigne++)
             {
                 if(ui->listWidgetGroup->item(noLigne)->isSelected())
                 {
                     listeDesGroupesSelectionnes<<ui->listWidgetGroup->item(noLigne)->text();
                 }
             }
             sesGroupes=listeDesGroupesSelectionnes.join(',');

             ui->tableWidgetUtilisateur->setItem(NbLigne,3,new QTableWidgetItem(sesGroupes));
             ui->tableWidgetUtilisateur->setItem(NbLigne,4,new QTableWidgetItem(ui->comboBox->currentText())) ;
             ui->tableWidgetUtilisateur->setItem(NbLigne,5,new QTableWidgetItem(ui->lineEditLogin->text())) ;
             ui->tableWidgetUtilisateur->setItem(NbLigne,6,new QTableWidgetItem(ui->lineEditMdp->text())) ;
         }
         else
         {
             QMessageBox::warning(this,this->windowTitle(),"Erreur Confirmation mot de passe invalide");
         }
     }
     else
     {
         QMessageBox::warning(this,this->windowTitle(),"Champs incomplet");
     }

     ui->lineEditNom->clear();
     ui->lineEditPrenom->clear();
     ui->lineEditLogin->clear();
     ui->lineEditMdp->clear();
     ui->lineEditConfMdp->clear();
     ui->lineEditMail->clear();
     for(int noLigne=0;noLigne<ui->listWidgetGroup->count();noLigne++)
     {
         if(ui->listWidgetGroup->item(noLigne)->isSelected())
         {
            ui->listWidgetGroup->item(noLigne)->setSelected(false);
         }
     }


}
void MainWindow::ajoutConstruct()
{
    //action faites lors de la construction
    this->ligneSelectionne=-1;
    ui->tableWidgetGroupe_2->hideColumn(0);
    ui->tableWidgetUtilisateur->hideColumn(5);
    ui->tableWidgetUtilisateur->hideColumn(6);
}

void MainWindow::chargeListeGroup()
{
    //charge dynamique du tableau de groupe du coté utilisateur + comboBox
    ui->listWidgetGroup->clear();
    ui->comboBox->clear();

    int NbLigne=ui->tableWidgetGroupe_2->rowCount();
    if (NbLigne==0)
    {
        ui->listWidgetGroup->clear();
        ui->comboBox->clear();
    }
    else
    {
        for (int i=0;i<NbLigne ; i++)
        {
            QString LeGroupe=ui->tableWidgetGroupe_2->item(i,1)->text();
            ui->listWidgetGroup->addItem(LeGroupe);
            ui->comboBox->addItem(LeGroupe);
        }
    }

}

void MainWindow::on_tableWidgetUtilisateur_clicked(const QModelIndex &index)
{
    //Mise a jour de la ligne Selectionnée

    ligneSelectionne=index.row();

    // Allimentation du formulaire grace au clique sur le tableau

    ui->lineEditNom->setText(ui->tableWidgetUtilisateur->item(ligneSelectionne,0)->text());
    ui->lineEditPrenom->setText(ui->tableWidgetUtilisateur->item(ligneSelectionne,1)->text());
    ui->lineEditMail->setText(ui->tableWidgetUtilisateur->item(ligneSelectionne,2)->text());
    ui->comboBox->setCurrentText(ui->tableWidgetUtilisateur->item(ligneSelectionne,4)->text());
    ui->lineEditLogin->setText(ui->tableWidgetUtilisateur->item(ligneSelectionne,5)->text());
    ui->lineEditMdp->setText(ui->tableWidgetUtilisateur->item(ligneSelectionne,6)->text());
    QStringList listGroup=sesGroupes.split(",");
    for(int nogroupe=0 ; nogroupe<listGroup.size();nogroupe++)
    {
        for (int noGroupe=0 ; noGroupe<ui->listWidgetGroup->count(); noGroupe++)
        {
            if(listGroup.value(nogroupe)==ui->listWidgetGroup->item(noGroupe)->text())
                ui->listWidgetGroup->item(noGroupe)->setSelected(true);
        }
    }

}
