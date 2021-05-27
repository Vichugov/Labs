#ifndef TREE_H
#define TREE_H
#include <QPainter>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Tree; }
QT_END_NAMESPACE

class Tree : public QMainWindow
{
    Q_OBJECT

public:
    Tree(QWidget *parent = nullptr);
    ~Tree();

private:
    Ui::Tree *ui;
protected:
    void paintEvent(QPaintEvent*) override;
private slots:
    void on_enterbutton_clicked();
    void EndInput();
    void Go();
    void Maker();
    void on_startbutton_clicked();
    void on_gotree_clicked();
    void on_simvolbutton_clicked();
    void on_gosearchbutton_clicked();
};
#endif // TREE_H
