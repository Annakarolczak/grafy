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
    bool koniec;

private slots:
    void on_comboBox_2_activated(const QString &arg1);

    void on_rb_dodaj_clicked(bool checked);

    void on_rb_usun_clicked(bool checked);

    void on_rb_V_clicked(bool checked);

    void on_rb_E_clicked(bool checked);

    void on_b_koniec_clicked();

    void on_b_edytuj_clicked();

    void on_b_clean_clicked();

    void on_rb_skie_clicked(bool checked);

    void on_rb_nieskie_clicked(bool checked);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
