#ifndef B2BLOCKGUI_H
#define B2BLOCKGUI_H

#include <QMainWindow>
#include <QStackedWidget>

#include "aboutdialog.h"
#include "overviewpage.h"

class QAction;
class QMenu;
class QPlainTextEdit;
class QSessionManager;

class OverviewPage;

class B2BlockGUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit B2BlockGUI(QWidget *parent = 0);
    ~B2BlockGUI();

private:
    
    QToolBar *toolbar;

    QStackedWidget *centralStackedWidget;

    OverviewPage *overviewPage;

    void createMenus();
    void createStatusBar();
    void createActions();
    void createToolBars();
    
    QAction *aboutAction;
    QAction *overviewAction;
    QAction *exitAction;

private slots:    
    
    void aboutClicked();
    void gotoOverviewPage();

    
};

#endif