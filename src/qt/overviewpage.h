#ifndef OVERVIEWPAGE_H
#define OVERVIEWPAGE_H

#include <QDialog>

namespace Ui {
    class OverviewPage;
}

/** Overview ("home") page widget */
class OverviewPage : public QWidget
{
    Q_OBJECT

public:
    explicit OverviewPage(QWidget *parent = 0);
    ~OverviewPage();

private:
    Ui::OverviewPage *ui;

};

#endif // OVERVIEWPAGE_H
