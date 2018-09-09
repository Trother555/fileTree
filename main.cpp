#include "mainwindow.h"
#include <QApplication>
#include <QFileSystemModel>
#include <QTreeView>
#include <QDir>
#include "filestatisticscontroller.h"
#include "filestatisticsviewcontainer.h"
#include <QModelIndex>
#include <QTextBrowser>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QString root = "";
    //"C:/Users/Pavel/Desktop/asd"
    //set up the fileTree with a model
    QFileSystemModel fsModel;
    fsModel.setRootPath(root);
    auto fileTree = w.findChild<QTreeView*>("fileTree");
    fileTree->setModel(&fsModel);
    fileTree->setAnimated(false);
    fileTree->setIndentation(20);
    fileTree->setSortingEnabled(true);
    const QModelIndex rootIndex = fsModel.
            index(QDir::cleanPath(root));
    fileTree->setRootIndex(rootIndex);

    //set up slots for statistics controller
    FileStatisticsController controller(&a);

    //set up the statistics view
    FileStatisticsViewContainer statisticsView;
    statisticsView.setView(w.findChild<QTextBrowser*>("statisticsView"));

    //connecting signals to slots
    QObject::connect(fileTree, &QTreeView::pressed,
                     &controller, &FileStatisticsController::updateStatistics);
    QObject::connect(&controller, &FileStatisticsController::updated,
                     &statisticsView, &FileStatisticsViewContainer::updateView);

    return a.exec();
}
