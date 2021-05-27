#ifndef GRAF_H
#define GRAF_H
#include <QPainter>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Graf; }
QT_END_NAMESPACE

class Graf : public QMainWindow
{
    Q_OBJECT

public:
    Graf(QWidget *parent = nullptr);
    ~Graf();

private:
    Ui::Graf *ui;
protected:
    void paintEvent(QPaintEvent*) override;
private slots:
    void on_button_clicked();
};
#endif // GRAF_H
