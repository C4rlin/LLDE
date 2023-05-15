#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <no.h>
#include <llde.h>
#include <QMessageBox>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonAcessarInicio_clicked();

    void on_pushButtonInserirInicio_clicked();

    void on_pushButtonRetirarInicio_clicked();

    void on_pushButtonInserirFim_clicked();

    void on_pushButtonAcessarFim_clicked();

    void on_pushButtonRetirarFim_clicked();

    void on_pushButtonAcessarPos_clicked();

    void on_pushButtonInserirPos_clicked();

    void on_pushButtonRetirarPos_clicked();

    void on_pushButtonAcessarPos_2_clicked();

private:
    Ui::MainWindow *ui;
    ce::LLDE lista;
    QMessageBox msgBoxIncluir;
};
#endif // MAINWINDOW_H
