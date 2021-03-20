#ifndef DEF_WINDOW
#define DEF_WINDOW

#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QRadioButton>


//forward declaration
namespace Ui{
class MainWindow;
}
class render_area;

/** Declaration of the window class */
class window: public QMainWindow
{
    Q_OBJECT

public:

    window(QWidget *parent=nullptr);
    ~window();

private slots:

    void action_quit();
    int on_pushButton_lay_clicked();

private:

    Ui::MainWindow *ui;
    render_area *render;

};

#endif
