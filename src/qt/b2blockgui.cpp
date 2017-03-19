#include <QtWidgets>
#include <QMenuBar>
#include <QStatusBar>
#include <QCloseEvent>
#include <QMessageBox>
#include <QStackedWidget>

#include "b2blockgui.h"
#include "aboutdialog.h"
#include "overviewpage.h"

B2BlockGUI::B2BlockGUI(QWidget *parent):
    QMainWindow(parent)
{

	#ifndef Q_OS_MAC
	    qApp->setWindowIcon(QIcon(":icons/b2block"));
	    setWindowIcon(QIcon(":icons/b2block"));
	#else
	    //setUnifiedTitleAndToolBarOnMac(true);
	    QApplication::setAttribute(Qt::AA_DontShowIconsInMenus);
	#endif

    createStatusBar();
    createActions();
    createMenus();
    createToolBars();
    
    setWindowTitle(tr("B2Block - B2B Blockchain System"));
    setMinimumSize(900, 600);
    resize(900, 600);

    setUnifiedTitleAndToolBarOnMac(true);

    overviewPage = new OverviewPage();
    
    centralStackedWidget = new QStackedWidget(this);
    centralStackedWidget->addWidget(overviewPage);

    QWidget *centralWidget = new QWidget();
    QVBoxLayout *centralLayout = new QVBoxLayout(centralWidget);

    centralLayout->addWidget(centralStackedWidget);
    setCentralWidget(centralWidget);

    gotoOverviewPage();
}

B2BlockGUI::~B2BlockGUI() {
}

void B2BlockGUI::createActions() {

    QActionGroup *tabGroup = new QActionGroup(this);    
    
    aboutAction = new QAction(QIcon(":/icons/about"),tr("&About B2Block"), this);
    aboutAction->setToolTip(tr("Show information about B2Block"));
    aboutAction->setShortcut( tr("Ctrl+A") );
    tabGroup->addAction(aboutAction);
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(aboutClicked()));            

    overviewAction = new QAction(QIcon(":/icons/dashboard"), tr("&Dashboard"), this);
    overviewAction->setToolTip(tr("Show general overview of B2Block system"));
    overviewAction->setCheckable(true);
    overviewAction->setShortcut(QKeySequence(Qt::ALT + Qt::Key_1));
    tabGroup->addAction(overviewAction);    
    connect(overviewAction, SIGNAL(triggered()), this, SLOT(gotoOverviewPage()));
    
    exitAction = new QAction( QIcon(":/icons/exit"), tr("E&xit"), this );
    exitAction->setShortcut( tr("Ctrl+Q") );
    exitAction->setToolTip( tr("Quit the application") );
    tabGroup->addAction(exitAction);
    connect( exitAction, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()) );

}

void B2BlockGUI::createMenus() {
		    		     	 
	    
    QMenu *exitMenu = new QMenu(tr("&Exit"));
    exitMenu->addAction(exitAction);        
    menuBar()->addMenu(exitMenu);
    
    
}

static QWidget* makeToolBarSpacer()
{
    QWidget* spacer = new QWidget();
    spacer->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    spacer->setStyleSheet("QWidget { background: none; }");
    return spacer;
}

void B2BlockGUI::createToolBars()
{
    toolbar = new QToolBar(tr("Tabs toolbar"));
    toolbar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolbar->addAction(overviewAction);
    toolbar->addAction(aboutAction);
    toolbar->addAction(exitAction);    
    toolbar->addWidget(makeToolBarSpacer());

    toolbar->setOrientation(Qt::Vertical);
    toolbar->setMovable(false);    

    addToolBar(Qt::LeftToolBarArea, toolbar);

    int maxwidth = 0;

    foreach(QAction *action, toolbar->actions()) {
        maxwidth = fmax(maxwidth, toolbar->widgetForAction(action)->width());
    }

    foreach(QAction *action, toolbar->actions()) {
        toolbar->widgetForAction(action)->setFixedWidth(maxwidth);
    }
}

void B2BlockGUI::createStatusBar() {
    statusBar()->showMessage(tr("Ready"));
}

void B2BlockGUI::aboutClicked()
{
    AboutDialog dlg;
    dlg.exec();
}

void B2BlockGUI::gotoOverviewPage()
{
    centralStackedWidget->setCurrentWidget(overviewPage);
}



