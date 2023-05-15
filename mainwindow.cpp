#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int QE = lista.getQuantidadeDeElementos();
    ui->spinBoxPos->setMaximum(QE);

    msgBoxIncluir.setWindowTitle("ERRO");
    msgBoxIncluir.setText("Insira apenas inteiros!");
    msgBoxIncluir.setIcon(QMessageBox::Warning);
    msgBoxIncluir.setStyleSheet("QMessageBox{background-color: rgb(30, 37, 40);}" "QLabel{color: white;}");

    ui->pushButtonInserirInicio->setIcon(QIcon(":/icons/icons/incluir1.png"));
    ui->pushButtonAcessarInicio->setIcon(QIcon(":/icons/icons/acessar1.png"));
    ui->pushButtonRetirarInicio->setIcon(QIcon(":/icons/icons/retirar1.png"));
    ui->pushButtonInserirFim->setIcon(QIcon(":/icons/icons/incluir1.png"));
    ui->pushButtonAcessarFim->setIcon(QIcon(":/icons/icons/acessar1.png"));
    ui->pushButtonRetirarFim->setIcon(QIcon(":/icons/icons/retirar1.png"));
    ui->pushButtonInserirPos->setIcon(QIcon(":/icons/icons/incluir1.png"));
    ui->pushButtonAcessarPos->setIcon(QIcon(":/icons/icons/acessar1.png"));
    ui->pushButtonRetirarPos->setIcon(QIcon(":/icons/icons/retirar1.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonAcessarInicio_clicked()
{
    try
    {
        QString saida = QString::number(lista.acessarInicio());
        ui->lineEditValor->setText(saida);
    }
    catch (QString &erro)
    {
        QMessageBox::information(this,"ERRO DO SISTEMA", erro);
    }
}


void MainWindow::on_pushButtonInserirInicio_clicked()
{
    try {
        QString teste = ui->lineEditValor->text();
        bool ok;
        int valor = teste.toInt(&ok);
        if(ok)
        {
            lista.inserirInicio(valor);
            ui->lineEditValor->clear();
            ui->textEditSaida->setText(lista.obterLista());
            ui->lineEditQE->setText(QString::number(lista.getQuantidadeDeElementos()));
        }
        else
        {
            msgBoxIncluir.exec();
            ui->lineEditValor->clear();
        }
        int QE = lista.getQuantidadeDeElementos();
        ui->spinBoxPos->setMaximum(QE);

    } catch (QString &erro)
    {
        QMessageBox::information(this,"ERRO DO SISTEMA", erro);
    }
}


void MainWindow::on_pushButtonRetirarInicio_clicked()
{

    try
    {
        QString saida = QString::number(lista.retirarInicio());
        ui->lineEditValor->setText(saida);
        ui->textEditSaida->setText(lista.obterLista());
        ui->lineEditQE->setText(QString::number(lista.getQuantidadeDeElementos()));

        int QE = lista.getQuantidadeDeElementos();
        ui->spinBoxPos->setMaximum(QE);
    }
    catch (QString &erro)
    {
        QMessageBox::information(this,"ERRO DO SISTEMA",erro);
    }
}


void MainWindow::on_pushButtonInserirFim_clicked()
{
    try {
        QString teste = ui->lineEditValor->text();
        bool ok;
        int valor = teste.toInt(&ok);
        if(ok)
        {
            lista.inserirFim(valor);
            ui->lineEditValor->clear();
            ui->textEditSaida->setText(lista.obterLista());
            ui->lineEditQE->setText(QString::number(lista.getQuantidadeDeElementos()));
        }
        else
        {
            msgBoxIncluir.exec();
            ui->lineEditValor->clear();
        }
        int QE = lista.getQuantidadeDeElementos();
        ui->spinBoxPos->setMaximum(QE);

    } catch (QString &erro)
    {
        QMessageBox::information(this,"ERRO DO SISTEMA", erro);
    }
}


void MainWindow::on_pushButtonAcessarFim_clicked()
{
    try
    {
        QString saida = QString::number(lista.acessarFim());
        ui->lineEditValor->setText(saida);
    }
    catch (QString &erro)
    {
        QMessageBox::information(this,"ERRO DO SISTEMA", erro);
    }
}


void MainWindow::on_pushButtonRetirarFim_clicked()
{
    try
    {
        QString saida = QString::number(lista.retirarFim());
        ui->lineEditValor->setText(saida);
        ui->textEditSaida->setText(lista.obterLista());
        ui->lineEditQE->setText(QString::number(lista.getQuantidadeDeElementos()));

        int QE = lista.getQuantidadeDeElementos();
        ui->spinBoxPos->setMaximum(QE);
    }
    catch (QString &erro)
    {
        QMessageBox::information(this,"ERRO DO SISTEMA",erro);
    }
}


void MainWindow::on_pushButtonAcessarPos_clicked()
{
    int posicao = ui->spinBoxPos->value();
    try {
        QString saida = QString::number(lista.acessarPosicao(posicao));
        ui->lineEditValor->setText(saida);

    } catch (QString &erro)
    {
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }
}


void MainWindow::on_pushButtonInserirPos_clicked()
{
    int posicao = ui->spinBoxPos->value();
    try {
        QString teste = ui->lineEditValor->text();
        bool ok;
        int valor = teste.toInt(&ok);
        if(ok)
        {
            lista.inserirPosicao(valor, posicao);
            ui->lineEditValor->clear();
            ui->textEditSaida->setText(lista.obterLista());
            ui->lineEditQE->setText(QString::number(lista.getQuantidadeDeElementos()));
        }
        else
        {
            msgBoxIncluir.exec();
            ui->lineEditValor->clear();
        }
        int QE = lista.getQuantidadeDeElementos();
        ui->spinBoxPos->setMaximum(QE);

    } catch (QString &erro)
    {
        QMessageBox::information(this,"ERRO DO SISTEMA", erro);
    }
}


void MainWindow::on_pushButtonRetirarPos_clicked()
{
    int posicao = ui->spinBoxPos->value();
    try
    {
        QString saida = QString::number(lista.retirarPosicao(posicao));
        ui->lineEditValor->setText(saida);
        ui->textEditSaida->setText(lista.obterLista());
        ui->lineEditQE->setText(QString::number(lista.getQuantidadeDeElementos()));

        int QE = lista.getQuantidadeDeElementos();
        ui->spinBoxPos->setMaximum(QE);
    }
    catch (QString &erro)
    {
        QMessageBox::information(this,"ERRO DO SISTEMA",erro);
    }
}


void MainWindow::on_pushButtonAcessarPos_2_clicked()
{
    int ordem;
    if(ui->comboBox->currentIndex() == 0) ordem = 0;
    if(ui->comboBox->currentIndex() == 1) ordem = 1;
    ui->textEditSaidaOrdenada->setText(lista.obterListaOrdenada(ordem));
}

